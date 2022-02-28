/*
 *  Batcher -- converts all the files it can find with a
 *  suitable file name.
 *  Converts raw data files of Chinon ES-1000 or Kodak DC20 to TGA files.
 *
 *  based on cmttoppm.c written by YOSHIDA Hideki <hideki@yk.rim.or.jp>
 *  enhanced to dc2totga.c by Oliver.Hartmann@t-online.de
 *
 */

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



#define VERSION_STRING  "Windows CE version."

#define UINT8 unsigned char
#define UINT16 unsigned short
#define UINT32 unsigned long

#define UBYTE unsigned short int
#define UWORD unsigned int

#define COLUMNSIZE     512

int mode=0;			// 1 for standard, 0 for high

int COLUMNS=512;		// 256 for standard, 512 for HIGH
#define LINES       243L
#define RES_LINES   375

#define LEFT_MARGIN   2
//#define RIGHT_MARGIN 5

int RIGHT_MARGIN=10;		//5 for standard, 10 for high

#define TOP_MARGIN    1
#define BOTTOM_MARGIN 1

#define NET_COLUMNS (COLUMNS - LEFT_MARGIN - RIGHT_MARGIN)
#define NET_LINES   (LINES - TOP_MARGIN - BOTTOM_MARGIN)
#define NET_PIXELS  (NET_COLUMNS * NET_LINES)

//#define CAMERA_HEADER_SIZE 256

int CAMERA_HEADER_SIZE=256;		// 256 for standard, 512 for HIGH

#define SCALE 64
#define SCALESQUARE 4096
#define	SCALEHALF 32
#define SMAX (256 * SCALE - 1)
#define HORIZ_IPOL 3
#define HISTOGRAM_STEPS 4096

#define RFACTOR 0.64f
#define GFACTOR 0.58f
#define BFACTOR 1.00f
#define RINTENSITY 0.476f
#define GINTENSITY 0.299f
#define BINTENSITY 0.175f

#define SATURATION 1.2f
#define NORM_PERCENTAGE 0.5f
#define GAMMA 0.5f

// Changes to reflect the High/Standard Image modes


int IFFBODYSIZE=558000;	// 558000 for high
int IFFWIDTH=62;		// 62 for high, 


long low_i = -1, high_i = -1;
float gamma_value = GAMMA;
float saturation = SATURATION;
float rfactor = RFACTOR, gfactor = GFACTOR, bfactor = BFACTOR;
float norm_percentage = NORM_PERCENTAGE;
int all_files= 0, fcnt= 1, opt_lev= 2; // make = 0 for speed
UINT8 max_ccd_val= 255;
char filename[127]= { 0 };

UINT8 *ccd[RES_LINES];
short *horiz_ipol[RES_LINES];
short *red[RES_LINES], *green[RES_LINES], *blue[RES_LINES];

typedef struct  {
	int name1; 
	char name2; 
	unsigned long bfSize;
	unsigned long reserved; 
	unsigned long bfOffs;
} bmfh_type;

typedef struct  {
	unsigned long biSize;//=sizeof(BitMapInfoHeader); 
	unsigned long biWidth;// = 496;     // width
	unsigned long biHeight;// = 375;	 // height
	unsigned short biPlanes;// = 1;	 // always 1, apparently
	unsigned short biBitCount;// = 24;  // lots of colours
	unsigned long biCompression;// = 0; // no compression
	unsigned long biSizeImage;
	unsigned long biXPelsPerMeter;// = 44;
	unsigned long biYPelsPerMeter;// = 44;
	unsigned long biClrUsd;// = 0;
	unsigned long biClrImportant;// = 44;
} bmih_type;

	bmih_type BMInfoHeader;
	bmfh_type BMFileHeader;

void Bastard()
{
	BMFileHeader.name1='B';
	BMFileHeader.name2='M';
	BMFileHeader.bfSize=sizeof(BMFileHeader)+sizeof(BMInfoHeader);
	BMFileHeader.reserved=0;
	BMFileHeader.bfOffs=sizeof(BMFileHeader)+sizeof(BMInfoHeader);

	BMInfoHeader.biSize=sizeof(BMInfoHeader);
	BMInfoHeader.biWidth = 496;
	BMInfoHeader.biHeight = 375;
	BMInfoHeader.biPlanes= 1;				// always 1, apparently
	BMInfoHeader.biBitCount=24;			// lots of colours
	BMInfoHeader.biCompression= 0;			// no compression
	BMInfoHeader.biSizeImage=1000;			// Size of data
	BMInfoHeader.biXPelsPerMeter= 44;
	BMInfoHeader.biYPelsPerMeter= 44;
	BMInfoHeader.biClrUsd=0;
	BMInfoHeader.biClrImportant=0;
}



/*

*/


/*
int read_dc2_file(FILE *infd, UINT8 *ccd[LINES])
{
  int line;

  fseek(infd, 0, SEEK_END);

  if ( ftell(infd) < 124928L )
	{
	COLUMNS=256;
	RIGHT_MARGIN=5;
	CAMERA_HEADER_SIZE=256;
	IFFBODYSIZE=288000;
	IFFWIDTH=32;
	mode=1;
	//printf("Processing shorty!\n");
	}
   else
	{
	COLUMNS=512;
	RIGHT_MARGIN=10;
	CAMERA_HEADER_SIZE=512;
	IFFBODYSIZE=558000;
	IFFWIDTH=62;
	mode=0;
	//printf("Processing biggy!\n");
	}

	fseek(infd, CAMERA_HEADER_SIZE, SEEK_SET);

  for (line= 0; line < LINES; line++)
    fread(ccd[line], 1, COLUMNS, infd);

  return (0);
}

*/

void set_initial_interpolation(UINT8 *ccd[LINES],
                               short *horiz_ipol[LINES])
{
  int column, line;
  for (line = 0; line < LINES; line++)
  {
    horiz_ipol[line][LEFT_MARGIN]= ccd[line][LEFT_MARGIN + 1] * SCALE;
    horiz_ipol[line][COLUMNS-RIGHT_MARGIN-1]=  ccd[line][COLUMNS-RIGHT_MARGIN-2] * SCALE;
    for (column = LEFT_MARGIN+1; column < COLUMNS-RIGHT_MARGIN- 1; column++)
    {
      horiz_ipol[line][column] = ((short) ccd[line][column-1] + (short) ccd[line][column+1]) * (SCALEHALF);
    }
  }
}

void ipol_horizontally(UINT8 *ccd[LINES], short *horiz_ipol[LINES])
{
  int column, line, i, init_col;
  for (line = TOP_MARGIN-1; line < LINES-BOTTOM_MARGIN+1; line++)
  {
    for (i = 0; i < HORIZ_IPOL; i++)
    {
      for (init_col= LEFT_MARGIN+1; init_col <= LEFT_MARGIN+2; init_col++)
      {
        for (column = init_col; column < COLUMNS-RIGHT_MARGIN-1; column+= 2)
	{
           horiz_ipol[line][column] = (short)
                     (((float)ccd[line][column - 1] / horiz_ipol[line][column - 1] +
                       (float)ccd[line][column + 1] / horiz_ipol[line][column + 1]) *
								ccd[line][column] * (2048) + 0.5f);
                              //ccd[line][column] * (SCALESQUARE / 2) + 0.5f);
        }
      }
    }
  }
}

void ipol_vertically(UINT8 *ccd[LINES], short *horiz_ipol[LINES],
                     short *red[LINES], short *green[LINES], short *blue[LINES])
{
  int column, line;
  for (line = TOP_MARGIN; line < LINES - BOTTOM_MARGIN; line++)
  {
    for (column = LEFT_MARGIN; column < COLUMNS - RIGHT_MARGIN; column++)
    {
      long r2gb, g2b, rg2, rgb2, r, g, b;
      long this_ccd = ccd[line][column] * SCALE;
      long up_ccd   = ccd[line - 1][column] * SCALE;
      long down_ccd = ccd[line + 1][column] * SCALE;
      long this_horiz_ipol = horiz_ipol[line][column];
      long this_intensity = this_ccd + this_horiz_ipol;
      long up_intensity   = horiz_ipol[line-1][column] + up_ccd;
      long down_intensity = horiz_ipol[line+1][column] + down_ccd;
      long this_vert_ipol;
      if (line == TOP_MARGIN)
      {
        this_vert_ipol = (long) ((float)down_ccd / down_intensity * this_intensity + 0.5f);
      }
      else
        if (line == LINES - BOTTOM_MARGIN - 1)
        {
          this_vert_ipol= (long)((float)up_ccd / up_intensity * this_intensity + 0.5f);
        }
        else
        {
          this_vert_ipol= (long)(((float)up_ccd/up_intensity + (float)down_ccd/down_intensity) *
			    this_intensity / 2.0f + 0.5f);
        }
      if (line & 1)
      {
        if (column & 1)
        {
          r2gb = this_ccd;
          g2b = this_horiz_ipol;
          rg2 = this_vert_ipol;
          r = (2 * (r2gb - g2b) + rg2) / 5;
          g = (rg2 - r) / 2;
          b = g2b - 2 * g;
        }
        else
        {
          g2b = this_ccd;
          r2gb = this_horiz_ipol;
          rgb2 = this_vert_ipol;
          r = (3 * r2gb - g2b - rgb2) / 5;
          g = 2 * r - r2gb + g2b;
	  b = g2b - 2 * g;
        }
      }
      else
      {
        if (column & 1)
        {
          rg2 = this_ccd;
          rgb2 = this_horiz_ipol;
          r2gb = this_vert_ipol;
          b = (3 * rgb2 - r2gb - rg2) / 5;
          g = (rgb2 - r2gb + rg2 - b) / 2;
          r = rg2 - 2 * g;
        }
        else
        {
          rgb2 = this_ccd;
          rg2 = this_horiz_ipol;
          g2b = this_vert_ipol;
          b = (g2b - 2 * (rg2 - rgb2)) / 5;
	  g = (g2b - b) / 2;
          r = rg2 - 2 * g;
        }
      }
      if (r < 0) r = 0;
      if (g < 0) g = 0;
      if (b < 0) b = 0;
      red  [line][column] = (short) r;
      green[line][column] = (short) g;
      blue [line][column] = (short) b;
    }
  }
}

void adjust_color_and_saturation(short *red[LINES], short *green[LINES], short *blue[LINES])
{
  int line, column;
#if DEBUG
  long ri, gi, bi;
  long r_min = SMAX, g_min = SMAX, b_min = SMAX;
  long r_max =    0, g_max =    0, b_max =    0;
  long r_sum =    0, g_sum =    0, b_sum =    0;
#endif
  float sqr_saturation = (float) sqrt(saturation);
  for (line = TOP_MARGIN; line < LINES - BOTTOM_MARGIN; line++)
  {
    for (column = LEFT_MARGIN; column < COLUMNS - RIGHT_MARGIN; column++)
    {
      float r = red  [line][column] * rfactor;
      float g = green[line][column] * gfactor;
      float b = blue [line][column] * bfactor;
      if (saturation != 1.0f)
      {
        float *min, *mid, *max, new_intensity;
        float intensity = r * RINTENSITY + g * GINTENSITY + b * BINTENSITY;
        if (r > g)
        {
          if (r > b)
          {
            max = &r;
	    if (g > b)
            {
              min = &b;
              mid = &g;
            }
            else
            {
              min = &g;
              mid = &b;
            }
          }
          else
          {
            min = &g;
            mid = &r;
            max = &b;
          }
        }
        else
        {
	  if (g > b)
          {
            max = &g;
            if (r > b)
            {
              min = &b;
              mid = &r;
            }
            else
            {
              min = &r;
              mid = &b;
            }
          }
          else
          {
            min = &r;
            mid = &g;
            max = &b;
          }
	}
        *mid = *min + sqr_saturation * (*mid - *min);
        *max = *min + saturation * (*max - *min);
        new_intensity = r * RINTENSITY + g * GINTENSITY + b * BINTENSITY;
        r *= intensity / new_intensity;
        g *= intensity / new_intensity;
        b *= intensity / new_intensity;
      }
      red  [line][column] = (short) (r + 0.5f);
      green[line][column] = (short) (g + 0.5f);
      blue [line][column] = (short) (b + 0.5f);
#if DEBUG
      ri= (long) (r + 0.5f);
      gi= (long) (g + 0.5f);
      bi= (long) (b + 0.5f);
      if (r_min > ri) r_min = ri;
      if (g_min > gi) g_min = gi;
      if (b_min > bi) b_min = bi;
      if (r_max < ri) r_max = ri;
      if (g_max < gi) g_max = gi;
      if (b_max < bi) b_max = bi;
      r_sum+= ri;
      g_sum+= gi;
      b_sum+= bi;
#endif
    }
  }
}


int lumi(UINT16 r, UINT16 g, UINT16 b)
{
  return ( (3*r)/10 + (6*g)/10 + b/10 );
}

/*
int min3(int x, int y, int z)
{
  return (x < y ? (x < z ? x : z) : (y < z ? y : z));
}

int max3(int x, int y, int z)
{
  return (x > y ? (x > z ? x : z) : (y > z ? y : z));
}
*/

void determine_limits(short *red[LINES], short *green[LINES],
                      short *blue[LINES], long *low_i_ptr, long *high_i_ptr)
{
  static unsigned int histogram[HISTOGRAM_STEPS + 1];
  int column, line;
  long nrm_perc= (long) (norm_percentage * 100);
  long i, s;
  long low_i = *low_i_ptr, high_i = *high_i_ptr;
  long max_i = 0;
  for (line = TOP_MARGIN; line < LINES - BOTTOM_MARGIN; line++)
  {
    for (column = LEFT_MARGIN; column < COLUMNS - RIGHT_MARGIN; column++)
    {
      /* i = max3(red[line][column], green[line][column], blue[line][column]); */
      i = lumi(red[line][column], green[line][column], blue[line][column]);
      if (i > max_i) max_i = i;
    }
  }
  if (low_i == -1)
  {
    for (i = 0; i <= HISTOGRAM_STEPS; i++)
      histogram[i] = 0;
    for (line = TOP_MARGIN; line < LINES - BOTTOM_MARGIN; line++)
    {
      for (column = LEFT_MARGIN; column < COLUMNS - RIGHT_MARGIN; column++)
      {
        /* i = min3(red[line][column], green[line][column], blue[line][column]); */
        i = lumi(red[line][column], green[line][column], blue[line][column]);
        histogram[i * HISTOGRAM_STEPS / max_i]++;
      }
    }
    s= 0;
    low_i= 0;
    for ( ; low_i<= HISTOGRAM_STEPS && s< NET_PIXELS*nrm_perc/10000; low_i++)
    {
      s += histogram[low_i];
    }
    low_i = (low_i * max_i + HISTOGRAM_STEPS / 2) / HISTOGRAM_STEPS;
    *low_i_ptr = low_i;
  }
  if (high_i == -1)
  {
    for (i = 0; i <= HISTOGRAM_STEPS; i++)
      histogram[i] = 0;
    for (line = TOP_MARGIN; line < LINES - BOTTOM_MARGIN; line++)
    {
      for (column = LEFT_MARGIN; column < COLUMNS - RIGHT_MARGIN; column++)
      {
        /* i = max3(red[line][column], green[line][column], blue [line][column]); */
        i = lumi(red[line][column], green[line][column], blue [line][column]);
        histogram[i * HISTOGRAM_STEPS / max_i]++;
      }
    }
    s= 0;
    high_i = HISTOGRAM_STEPS;
    for ( ; high_i >= 0 && s < NET_PIXELS*nrm_perc/10000; high_i--)
    {
      s += histogram[high_i];
    }
    high_i = (high_i * max_i + HISTOGRAM_STEPS / 2) / HISTOGRAM_STEPS;
    *high_i_ptr = high_i;
  }
#if DEBUG
 // printf(" low_i = %ld, high_i = %ld ", low_i, high_i);
#endif
}

UINT8 *make_gamma_table(int range)
{
  int i;
  double factor = pow(256.0, 1.0 / gamma_value) / range;
  UINT8 *gamma_table;
  if ((gamma_table = (UINT8 *)malloc(range * sizeof(UINT8))) == NULL)
  {
 //   fprintf(stderr, "Can't allocate memory for gamma table\n");
   // exit(1);
  }
  for (i = 0; i < range; i++)
  {
    int g = (int) (pow((double)i * factor, gamma_value) + 0.5);
    if (g > 255) g = 255;
    gamma_table[i] = (UINT8) g;
  }
  return gamma_table;
}

int lookup_gamma_table(int i, long low_i, long high_i,
                       UINT8 gamma_table[])
{
  if (i <= (int) low_i)  return   0;
  if (i >= (int) high_i) return 255;
  return gamma_table[i - low_i];
}

void stretch(short *red[RES_LINES], short *green[RES_LINES],
             short *blue[RES_LINES], long low_i, long high_i,
             UINT8 *ccd[LINES])
{
#if DEBUG
  int  r_min= 255, g_min= 255, b_min= 255;
  int  r_max=   0, g_max=   0, b_max=   0;
  long r_sum=   0, g_sum=   0, b_sum=   0;
#endif
  int column, line, i;
  UINT8 *gamma_table = make_gamma_table((int) (high_i - low_i));

  for (line = TOP_MARGIN; line < LINES - BOTTOM_MARGIN; line++)
  {
    for (column = LEFT_MARGIN; column < COLUMNS - RIGHT_MARGIN; column++)
    {
      int r = lookup_gamma_table(red  [line][column], low_i, high_i, gamma_table);
      int g = lookup_gamma_table(green[line][column], low_i, high_i, gamma_table);
      int b = lookup_gamma_table(blue [line][column], low_i, high_i, gamma_table);

      if (ccd[line][column] >= max_ccd_val)
        if ( ccd[line][column-1] >= max_ccd_val ||
             ccd[line][column+1] >= max_ccd_val ||
             ccd[line-1][column] >= max_ccd_val ||
             ccd[line+1][column] >= max_ccd_val )
        {
          r= g= b= ccd[line][column];
        }

      if (r > 255) r = 255; else if (r < 0) r = 0;
      if (g > 255) g = 255; else if (g < 0) g = 0;
      if (b > 255) b = 255; else if (b < 0) b = 0;
      red  [line-TOP_MARGIN][column]= (short) r;
      green[line-TOP_MARGIN][column]= (short) g;
      blue [line-TOP_MARGIN][column]= (short) b;
#if DEBUG
      if (r_min > r) r_min = r;
      if (g_min > g) g_min = g;
      if (b_min > b) b_min = b;
      if (r_max < r) r_max = r;
      if (g_max < g) g_max = g;
      if (b_max < b) b_max = b;
      r_sum += r;
      g_sum += g;
      b_sum += b;
#endif
    }
  }

  free(gamma_table);

  for (line=RES_LINES-1; line >= 0; line--)
  {
    float fy = NET_LINES / (float) RES_LINES;
    float by, ey;
    int   byab, eyab;
    float teilzeile;
    UINT16 ufakt;
    UINT16 ofakt;

    by=fy*line;                                 
    ey=fy*(line+1);                             

    byab=(int)by;                               
    eyab=(int)ey;                               
    if ((float)eyab==ey) eyab--;                

    teilzeile = eyab/fy;                        
    ufakt = (UINT16) ((teilzeile-line)*256);    
    ofakt = (UINT16) ((line+1-teilzeile)*256);  

    for (column=LEFT_MARGIN; column< COLUMNS-RIGHT_MARGIN; column++)
    {
      UINT16 erg_blau = 128;
      UINT16 erg_gruen= 128;
      UINT16 erg_rot  = 128;

      if(byab!=eyab)
      {
	for (i=eyab; i>=byab; i--)
        {
          UINT16 sum_blau  = blue[i][column];
          UINT16 sum_gruen = green[i][column];
          UINT16 sum_rot   = red[i][column];

          if(i==byab)
          {
            sum_blau  *= ufakt;
            sum_gruen *= ufakt;
            sum_rot   *= ufakt;
          }
          else
          {
            sum_blau  *= ofakt;
            sum_gruen *= ofakt;
            sum_rot   *= ofakt;
          }
          erg_blau += sum_blau;
          erg_gruen+= sum_gruen;
	  erg_rot  += sum_rot;
        }
        blue [line][column]= (short) (erg_blau/256);
        green[line][column]= (short) (erg_gruen/256);
        red  [line][column]= (short) (erg_rot/256);
      }
      else
      {
        blue [line][column]= blue [byab][column];
        green[line][column]= green[byab][column];
        red  [line][column]= red  [byab][column];
      }
    }      /* Ende Spalte Zielbild */
  }        /* Ende Zeile  Zielbild */

#if DEBUG
//  fprintf(stderr, "r: min= %3d, max= %3d, avg= %3d\n", r_min, r_max, r_sum/NET_PIXELS);
 // fprintf(stderr, "g: min= %3d, max= %3d, avg= %3d\n", g_min, g_max, g_sum/NET_PIXELS);
 // fprintf(stderr, "b: min= %3d, max= %3d, avg= %3d\n", b_min, b_max, b_sum/NET_PIXELS);
#endif
}

/*
struct swapbits {
unsigned one:1;
unsigned two:1;
unsigned thr:1;
unsigned fou:1;
unsigned fiv:1;
unsigned six:1;
unsigned sev:1;
unsigned eig:1;
};

union union_type {
UBYTE number1;
struct swapbits number2;
};



UBYTE bitbackward (UBYTE digit, UBYTE bitnumber)
{

//	 Return 1 or 0 (i.e. the bit)
//		of the digit value. BUT reverse
//		the bit number at the same time! 

	UBYTE value=0;

	union union_type the_byte;

	the_byte.number1=digit;

	switch (bitnumber){
	case 0: value=the_byte.number2.eig;break;
	case 1: value=the_byte.number2.sev;break;
	case 2: value=the_byte.number2.six;break;
	case 3: value=the_byte.number2.fiv;break;
	case 4: value=the_byte.number2.fou;break;
	case 5: value=the_byte.number2.thr;break;
	case 6: value=the_byte.number2.two;break;
	case 7: value=the_byte.number2.one;break;
	}

	return value;
}

UBYTE bitvalue (UBYTE digit, UBYTE bitnumber)
{

  // Return 1 or 0 (i.e. the bit)
	//	of the digit value. BUT reverse
	//	the bit number at the same time! 

	UBYTE value=0;

	union union_type the_byte;

	the_byte.number1=digit;


	switch (bitnumber){
	case 0: value=the_byte.number2.eig;break;
	case 1: value=the_byte.number2.sev;break;
	case 2: value=the_byte.number2.six;break;
	case 3: value=the_byte.number2.fiv;break;
	case 4: value=the_byte.number2.fou;break;
	case 5: value=the_byte.number2.thr;break;
	case 6: value=the_byte.number2.two;break;
	case 7: value=the_byte.number2.one;break;
	}

	return value;
}

*/

/*
void output_rgb_iff(short *red[RES_LINES], short *green[RES_LINES],
                short *blue[RES_LINES], FILE *outfp)
{

	UBYTE pixel_count,pixel_byte,plane;

	LONG Length;
	int bodylength;
	BitMapHead OutHead;
	int column, line;
	UBYTE bit;

	UBYTE pixelbuffer[62];
	int	pixelbuffercount;

	bodylength=IFFBODYSIZE;

	Length=4+4+4+20+4+4+bodylength;

	fwrite((char *)"FORM",4,1,outfp);
	fwrite((char *)&Length,4,1,outfp);
	fwrite((char *)"ILBM",4,1,outfp);


	// Write Bitmap header

	Length=20;

	if (mode==1) OutHead.w=256; else OutHead.w=496;
	OutHead.h=375;
	OutHead.x=0;
	OutHead.y=0;
	OutHead.nPlanes=24;
	OutHead.Masking=0;
	OutHead.Compression=0;
	OutHead.pad1=0;
	OutHead.transColor=0;
	OutHead.xAspect=44;
	OutHead.yAspect=44;
	if (mode==1) OutHead.pageWidth=256; else OutHead.pageWidth=496;
	OutHead.pageHeight=375; 
	
	fwrite((char *)"BMHD",4,1,outfp);
	fwrite((char *)&Length,4,1,outfp);
	fwrite((char *)&OutHead,Length,1,outfp);
	fwrite((char *)"BODY",4,1,outfp);
	Length=bodylength;
	fwrite((char *)&Length,4,1,outfp);

	// Write body

	// Line by line, write R0-R7, then G0-G7, then B0-B7

	
	for (line = 0; line < RES_LINES; line++)	// for each scan line
  	{
		for (plane=0;plane<8;plane++)			// for each bit plane
		{
			pixel_count=0;pixel_byte=0;pixelbuffercount=0;
			for (column = LEFT_MARGIN+2; column < COLUMNS-RIGHT_MARGIN-2; column++)
    		{
				bit=bitvalue((UBYTE)red [line][column],(UBYTE)plane);
				pixel_byte=(pixel_byte<<1)|bit;
				pixel_count++;
				if (pixel_count==8) 
				{
					pixelbuffer[pixelbuffercount++]=pixel_byte;
					pixel_count=0;pixel_byte=0;
				}
			}
			fwrite((char *)&pixelbuffer,IFFWIDTH,1,outfp);
		}

		for (plane=0;plane<8;plane++)			// for each bit plane
		{
			pixel_count=0;pixel_byte=0;pixelbuffercount=0;
			for (column = LEFT_MARGIN+2; column < COLUMNS-RIGHT_MARGIN-2; column++)
    		{
				bit=bitvalue((UBYTE)green [line][column],(UBYTE)plane);
				pixel_byte=(pixel_byte<<1)|bit;
				pixel_count++;
				if (pixel_count==8) 
				{
					pixelbuffer[pixelbuffercount++]=pixel_byte;
					pixel_count=0;pixel_byte=0;
				}
			}
			fwrite((char *)&pixelbuffer,IFFWIDTH,1,outfp);
		}

	for (plane=0;plane<8;plane++)			// for each bit plane
		{
			pixel_count=0;pixel_byte=0;pixelbuffercount=0;
			for (column = LEFT_MARGIN+2; column < COLUMNS-RIGHT_MARGIN-2; column++)
    		{
				bit=bitvalue((UBYTE)blue [line][column],(UBYTE)plane);
				pixel_byte=(pixel_byte<<1)|bit;
				pixel_count++;
				if (pixel_count==8) 
				{
					pixelbuffer[pixelbuffercount++]=pixel_byte;
					pixel_count=0;pixel_byte=0;
				}
			}
			fwrite((char *)&pixelbuffer,IFFWIDTH,1,outfp);
		}
	}
}

*/

void dc2tobmp(
	     UINT8 *ccd[RES_LINES], short *horiz_ipol[RES_LINES],
	     short *red[RES_LINES], short *green[RES_LINES], short *blue[RES_LINES])
{


  /* Decode raw CCD data to RGB */
  set_initial_interpolation(ccd, horiz_ipol);

  ipol_horizontally(ccd, horiz_ipol);

  ipol_vertically(ccd, horiz_ipol, red, green, blue);

  adjust_color_and_saturation(red, green, blue);

  /* Determine lower and upper limit using histogram */
  low_i = high_i = -1;
  if (low_i == -1 || high_i == -1)
  {
    determine_limits(red, green, blue, &low_i, &high_i);
  }

  stretch(red, green, blue, low_i, high_i, ccd);

}


#define MAX_INP_LINE   128
#define MAX_ARG_CNT     20

void freeup()
{
  int line;

  for (line= RES_LINES-1 ; line >= 0 ; line--)
  {
    free(ccd[line]);
    free(horiz_ipol[line]);
    free(red[line]);
    free(green[line]);
    free(blue[line]);
  }
}

void prepare(void)
{
	MessageBox(NULL,L"Starting",L"",MB_OK);
	Bastard();

  for (int line= 0; line < RES_LINES; line++)
  {
    if ( (ccd[line]= (UINT8 *)malloc(COLUMNSIZE*sizeof(char))) == NULL )
      break;
    if ( (horiz_ipol[line]= (short *)malloc(COLUMNSIZE*sizeof(short))) == NULL )
      break;
    if ( (red[line]= (short *)malloc(COLUMNSIZE*sizeof(short))) == NULL )
      break;
    if ( (green[line]= (short *)malloc(COLUMNSIZE*sizeof(short))) == NULL )
      break;
    if ( (blue[line]= (short *)malloc(COLUMNSIZE*sizeof(short))) == NULL )
      break;
  }

  if (line < RES_LINES)
  {
	  MessageBox(NULL,L"Can't allocate enough memory!",L"",MB_OK);

    for ( ; line >= 0 ; line--)
    {
      free(ccd[line]);
      free(horiz_ipol[line]);
      free(red[line]);
      free(green[line]);
      free(blue[line]);
    }
  }

}

void convert() 
{

	MessageBox(NULL,L"Image processing",L"",MB_OK);

	dc2tobmp(ccd, horiz_ipol, red, green, blue);

	MessageBox(NULL,L"End of conversion",L"",MB_OK);

}

void cleanup()
{
	MessageBox(NULL,L"Cleaning up",L"",MB_OK);
	
	freeup();

	MessageBox(NULL,L"The end",L"",MB_OK);

}




/*

prepare()
loadfile()
convertfile() (return if no file in memory)
displayfile()
savefile()
cleanup()



1. Prepare system (mallocs)

2. Wait..

3. Select & Load file into arrays

4. Convert file

5. Wait..

6. Display file

7. Save file

8. Exit (clean mallocs)

*/