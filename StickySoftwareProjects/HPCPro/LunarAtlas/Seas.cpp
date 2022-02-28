//
// Sea Date
//


#include "stdafx.h"
#include "math.h"

struct Sea_type {
	char name[30];
	float latitude;
	float longitude;
	int diam;
	char desc[80];
} ;


Sea_type Sea[23] = 
{
{"Mare Anguis",22.6,-67.7,150,"Serpent Sea"},
{"Mare Australe",-38.9,-93,603,"Southern Sea"},
{"Mare Cognitum",-10,23.1,376,"Sea that has become known"},
{"Mare Crisium",17,-59.1,418,"Sea of Crises"},
{"Mare Fecunditatis",-7.8,-51.3,909,"Sea of Fecundity"},
{"Mare Frigoris",56,-1.4,1596,"Sea of Cold"},
{"Mare Humboldtianum",56.8,-81.5,273," "},
{"Mare Humorum",-24.4,38.6,389,"Sea of Moisture"},
{"Mare Imbrium",32.8,15.6,1123,"Sea of Showers"},
{"Mare Ingenii",-33.7,-163.5,318,"Sea of Cleverness"},
{"Mare Insularum",7.5,30.9,513,"Sea of Islands"},
{"Mare Marginis",13.3,-86.1,420,"Sea of the Edge"},
{"Mare Moscoviense",27.3,-147.9,277,"Sea of Muscovy"},
{"Mare Nectaris",-15.2,-35.5,333,"Sea of Nectar"},
{"Mare Nubium",-21.3,16.6,715,"Sea of Clouds"},
{"Mare Orientale",-19.4,92.8,327,"Eastern sea"},
{"Mare Serenitatis",28,-17.5,707,"Sea of Serenity"},
{"Mare Smythii",1.3,-87.5,373," "},
{"Mare Spumans",1.1,-65.1,139,"Foaming Sea"},
{"Mare Tranquillitatis",8.5,-31.4,873,"Sea of Tranquility"},
{"Mare Undarum",6.8,-68.4,243,"Sea of Waves"},
{"Mare Vaporum",13.3,-3.6,245,"Sea of Vapors"},
{"Oceanus Procellarum",18.4,57.4,2568,"Ocean of Storms"}
};

CString Get_Sea_name(int i)
{
	return Sea[i].name;
}