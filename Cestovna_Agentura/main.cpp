#include "Zajazd.h"
#include "CestovnaKancelaria.h"
#define _CRT_SECURE_NO_DEPRECATE

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CestovnaKancelaria tour((char*)"data.txt");
	tour.zorad();
	tour.exportuj();

	printf("Zadajte vas cenovy strop: ");
	int cena = 0;
	scanf("%d", &cena);
	tour.vypis(cena);

	return 0;
}