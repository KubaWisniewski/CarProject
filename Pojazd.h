#pragma once
#include  <iostream>
#include <fstream>

using namespace std;

class Pojazd {
private:
	string typ_pojazdu;
public:
	Pojazd();
	virtual ~Pojazd();
	virtual void zmienParametrPojazdu(int nowa_wartosc) = 0;
	virtual void wyswietlInfo() = 0;
	
	friend std::ostream& operator <<(std::ostream &s, Pojazd &pojazd);
	friend std::istream& operator >> (std::istream &s, Pojazd &pojazd);

};

