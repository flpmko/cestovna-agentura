#include "CestovnaKancelaria.h"
#include <fstream>

CestovnaKancelaria::CestovnaKancelaria()
{
}

CestovnaKancelaria::CestovnaKancelaria(char* nazovSuboru)
{
	if (nazovSuboru != nullptr)
	{
		ifstream input;
		input.open(nazovSuboru);
		if (input.is_open())
		{
			//zistim pocet riadkov aby som vedel aky velky zoznam vytvorit
			int pocetRiadkov = 0;
			string riadok;
			while (getline(input, riadok)) pocetRiadkov++;
			input.clear(); 
			input.seekg(0); //nastavim kurzor opat na zaciatok suboru

			pocetZajazdov = pocetRiadkov;
			zoznam = new Zajazd * [pocetRiadkov];

			string destinacia = "";
			int cena = 0;
			char doprava = ' ';
			int plaz = 0;
			int i = 0;

			while (!input.eof())
			{
				input >> destinacia >> cena >> doprava >> plaz;
				zoznam[i] = new Zajazd((char*)destinacia.c_str(), cena, doprava, plaz);
				i++;
			}
		}
		input.close();
	}
}

void CestovnaKancelaria::zorad()
{
	for (int i = 0; i < this->pocetZajazdov - 1; i++)
	{
		for (int j = 0; j < this->pocetZajazdov - i - 1; j++)
		{
			if (this->zoznam[j]->getCena() > this->zoznam[j + 1]->getCena())
			{
				vymen(*this->zoznam[j], *this->zoznam[j + 1]);
			}
		}
	}
}

void CestovnaKancelaria::vymen(Zajazd& a, Zajazd& b)
{
	Zajazd c = a;
	a = b;
	b = c;
}

void CestovnaKancelaria::vypis()
{
	if (this->zoznam != nullptr)
	{
		for (int i = 0; i < pocetZajazdov; i++)
		{
			zoznam[i]->vypis();
		}
	}
}

void CestovnaKancelaria::exportuj()
{
	ofstream output;
	output.open("zajazd.txt");
	if (output.is_open())
	{
		for (int i = 0; i < pocetZajazdov; i++)
		{
			output << "Destinacia: " << zoznam[i]->getDestinacia()
				<< ", Cena: " << zoznam[i]->getCena() 
				<< " eur, Plaz: " << zoznam[i]->getPlaz()
				<< "m, Doprava: ";
			if (zoznam[i]->getDoprava() == 'A')
				output << "autobus" << endl;
			else
				output << "lietadlo" << endl;
		}
	}
	output.close();
}

CestovnaKancelaria::~CestovnaKancelaria()
{
	for (int i = 0; i < pocetZajazdov; i++)
	{
		delete zoznam[i];
	}
	delete[] this->zoznam;
}
