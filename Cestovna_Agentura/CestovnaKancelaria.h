#pragma once
#include "Zajazd.h"

class CestovnaKancelaria
{
private:
	Zajazd** zoznam = nullptr;
	int pocetZajazdov = 0;
public:
	CestovnaKancelaria();
	CestovnaKancelaria(char* nazovSuboru);
	void zorad();
	void vymen(Zajazd& a, Zajazd& b);
	void vypis();
	void exportuj();
	~CestovnaKancelaria();
};

