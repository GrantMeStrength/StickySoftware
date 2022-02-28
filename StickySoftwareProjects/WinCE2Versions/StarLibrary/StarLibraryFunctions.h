//
// .h
//

#define BS_NUMBER 3
#define EXPORTDLL extern "C" __declspec (dllexport)


// These are the functions provided

EXPORTDLL int Library_Get_Stars();
EXPORTDLL short int Library_Get_Star_Mag(int i);
EXPORTDLL double Library_Get_Star_Azm(int i);
EXPORTDLL double Library_Get_Star_Alt(int i);
EXPORTDLL void Library_Get_Name(char *name);



