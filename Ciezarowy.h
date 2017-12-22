#pragma once
#include "Samochod.h"

class Ciezarowy:public Samochod {
private:
	int ladownosc;
public:
	Ciezarowy();
	~Ciezarowy();
	void zmienParametrPojazdu(int nowa_wartosc);
	void zapiszStan(Ciezarowy &samochod);
	void wczytajStan(Ciezarowy &samochod);
	void wyswietlInfo();

	bool operator ==(const Ciezarowy &samochod);
	Ciezarowy& operator = (const Ciezarowy &samochod);

	friend std::ostream& operator <<(std::ostream &s, Ciezarowy &ciezarowy);
	friend std::istream& operator >>(std::istream &s, Ciezarowy &ciezarowy);

};