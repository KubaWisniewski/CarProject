#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Radio {
private:
	string kolor;
	int cena;
	string typ_wyswietlacza;
public:
	Radio();
	~Radio();
	void zapiszStan(Radio &radio);
	void wczytajStan(Radio &radio);

	friend std::ostream& operator <<(std::ostream &s, Radio &radio);
	friend std::istream& operator >>(std::istream &s, Radio &radio);

};