#include "Zajazd.h"

Zajazd::Zajazd()
{
}

Zajazd::Zajazd(char* paDestinacia, int paCena, char paDoprava, int paPlaz)
{
	if (paDestinacia && *paDestinacia)
	{
		this->destinacia = new char[strlen(paDestinacia) + 1];
		strcpy(this->destinacia, paDestinacia);

		this->cena = paCena;
		this->doprava = paDoprava;
		this->plaz = paPlaz;
	}
}

Zajazd::Zajazd(const Zajazd& zdroj)
{
	if (this != &zdroj)
	{
		this->destinacia = new char[strlen(zdroj.destinacia) + 1];
		strcpy(this->destinacia, zdroj.destinacia);

		this->cena = zdroj.cena;
		this->doprava = zdroj.doprava;
		this->plaz = zdroj.plaz;
	}
}

Zajazd& Zajazd::operator=(const Zajazd& zdroj)
{
	if (this != &zdroj)
	{
		Zajazd::~Zajazd();

		this->destinacia = new char[strlen(zdroj.destinacia) + 1];
		strcpy(this->destinacia, zdroj.destinacia);

		this->cena = zdroj.cena;
		this->doprava = zdroj.doprava;
		this->plaz = zdroj.plaz;
	}
	return *this;
}

void Zajazd::vypis()
{
	printf("Destinacia: %s, Cena: %d eur, Plaz: %d m, Doprava: ", destinacia, cena, plaz);
	if (doprava == 'A')
		printf("autobus\n");
	else
		printf("lietadlo\n");
}

Zajazd::~Zajazd()
{
	delete[] this->destinacia;
}
