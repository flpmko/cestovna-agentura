#include "Zajazd.h"
#include "CestovnaKancelaria.h"
#define _CRT_SECURE_NO_DEPRECATE

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/*Zajazd zajazd((char*)"Taliansko", 645, 'A', 20);
	zajazd.vypis();*/

	CestovnaKancelaria tour((char*)"data.txt");
	tour.zorad();
	tour.vypis();
	tour.exportuj();

	return 0;
}