//
// Given a program name and an index, save a BMP of
// the program's icon
//

#include "stdafx.h"

void SaveBMP(CDC *dc, CString FileName,int index)
{

// 1. Get Icon

	SHFILEINFO shfi;
	HANDLE hIcon;

	//TCHAR szFilePathName[]=TEXT("\\Windows\\solotaire.exe\0");

	memset (&shfi, 0, sizeof (SHFILEINFO));
	if (0==SHGetFileInfo (FileName, 0, &shfi, sizeof (SHFILEINFO), SHGFI_ICON|SHGFI_LARGEICON))
		MessageBox(NULL,L"0",L"0",MB_OK);

	hIcon = shfi.hIcon;

  /*
	hIcon=LoadImage(NULL,FileName,IMAGE_ICON,32,32,0);

	if (hIcon==NULL) MessageBox(NULL,L"0",L"0",MB_OK);
*/



	// 2. Create bitmap, draw icon into it

	CBitmap icon_bitmap;
	CDC iconDC;

//	CClientDC dc(this);

	iconDC.CreateCompatibleDC(dc);
	icon_bitmap.CreateCompatibleBitmap(dc,32,32);//CreateBitmap(32,32,8,0,NULL); //
	iconDC.SelectObject(&icon_bitmap);
	iconDC.FillSolidRect(0,0,32,32,RGB(255,255,255));
	DrawIconEx(iconDC, 0, 0, (struct HICON__*)hIcon, 32, 32, 0, NULL, DI_NORMAL);

	CFile file;	

	#define IMAGESIZE 1024
	#define PALETTESIZE 1024

	CString SaveName;

	switch (index) {
	case 0:SaveName="\\Windows\\Temporary Internet Files\\userA.bmp";break;
	case 1:SaveName="\\Windows\\Temporary Internet Files\\userB.bmp";break;
	case 2:SaveName="\\Windows\\Temporary Internet Files\\userC.bmp";break;
	case 3:SaveName="\\Windows\\Temporary Internet Files\\userD.bmp";break;
	}

	
	if( !file.Open(SaveName, CFile::modeWrite|CFile::modeCreate) )
		return;
	
	BITMAPFILEHEADER	hdr;

	//BYTE *byte_pointer;

	
	RGBQUAD pal[256];

	
	// Define BITMAPINFOHEADER

	BITMAPINFOHEADER bmih;

	bmih.biSize			= sizeof(BITMAPINFOHEADER);	
	bmih.biWidth			= 32;
	bmih.biHeight 			= -32;	
	bmih.biPlanes 			= 1;
	bmih.biBitCount			= 8;
	bmih.biCompression		= BI_RGB;	
	bmih.biSizeImage		= 0;	
	bmih.biXPelsPerMeter	= 0;
	bmih.biYPelsPerMeter	= 0;	
	bmih.biClrUsed			= 0;	
	bmih.biClrImportant		= 0;

	//BitBlt(dc,120,40,32,32,iconDC,0,0,SRCCOPY);

	int x,y,i,c,p;
	COLORREF col;
	COLORREF mypal[256];
	int pc=0;
	bool nc;
	BYTE pixels[1024];

	p=0;
	for (y=0;y<32;y++)
		for (x=0;x<32;x++)
		{
			col=GetPixel(iconDC,x,y);
			//SetPixel(dc,50+x*2,50+y*2,col);

			nc=true;
			for (i=0;i<pc;i++)
				if (col==mypal[i])
				{
					c=i;
					i=1024;
					nc=false;
				}
			if (nc) 
			{
				mypal[++pc]=col;
				c=pc;
			}

			pixels[p++]=c;
		}

	// Move palette into palette structure

		memset(&pal,0,1024);
		for (i=0;i<pc;i++)
		{
			pal[i].rgbRed=GetRValue(mypal[i]);
			pal[i].rgbGreen=GetGValue(mypal[i]);
			pal[i].rgbBlue=GetBValue(mypal[i]);
		}

	// Define BITMAP Header

	hdr.bfType			= ((WORD) ('M' << 8) | 'B');	// is always "BM"
	hdr.bfSize			= sizeof(hdr)+PALETTESIZE+IMAGESIZE+sizeof(BITMAPINFOHEADER);
	hdr.bfReserved1 	= 0;
	hdr.bfReserved2 	= 0;
	hdr.bfOffBits		= sizeof(hdr)+PALETTESIZE+sizeof(BITMAPINFOHEADER) ;

	// Write the file header 
	file.Write(&hdr, sizeof(hdr));

	// Write the core info  
	file.Write(&bmih,sizeof(BITMAPINFOHEADER));

	// Write the palette
	file.Write(&pal,PALETTESIZE);

	// Write the pixels  

	file.Write(pixels,1024);

	file.Close();
}