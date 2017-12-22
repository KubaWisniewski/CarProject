#pragma once
#include "Samochod.h"

class Osobowy :public Samochod {
private:
	int ilosc_miejsc;
public:
	Osobowy();
	~Osobowy();
	void zmienParametrPojazdu(int nowa_wartosc);
	void wyswietlInfo();
	void zapiszStan(Osobowy &samochod);
	void wczytajStan(Osobowy &samochod);

	bool operator ==(const Osobowy &samochod);
	Osobowy& operator = (const Osobowy &samochod);
	
	friend std::ostream& operator <<(std::ostream &s, Osobowy &osobowy);
	friend std::istream& operator >> (std::istream &s, Osobowy &osobowy);

};
