#pragma once
#include <string>
#include <iostream>

using namespace std;

class Zajazd
{
private:
	char* destinacia = nullptr;
	int cena = 0;
	char doprava = ' ';
	int plaz = 0;
public:
	Zajazd();
	Zajazd(char* paDestinacia, int paCena, char paDoprava, int paPlaz);
	Zajazd(const Zajazd& zdroj);
	Zajazd& operator = (const Zajazd& zdroj);
	void vypis();
	inline char* getDestinacia() { return this->destinacia; };
	inline int getCena() { return this->cena; };
	inline char getDoprava() { return this->doprava; };
	inline int getPlaz() { return this->plaz; };
	~Zajazd();
};

