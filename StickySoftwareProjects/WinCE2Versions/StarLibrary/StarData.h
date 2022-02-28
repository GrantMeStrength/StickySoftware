//
// Star data
//




struct BS_entry
{   
	short int mag;
	float ra,dec;
} ;

struct star_type
{
	float alt,azm;
};

struct star_type stars[BS_NUMBER];


BS_entry BSstars[BS_NUMBER] = 
{
{short int(0),float(6.75246417),float(-16.7161083)},
{short int(0),float(1.62857),float(-57.2367167)},
{short int(0),float(13.4198853),float(-11.1613083)}
}
;

