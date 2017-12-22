#pragma once

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Silnik {
private:
	int Moc;
	float pojemnosc;
	string rodzaj;
public:
	Silnik();
	~Silnik();
	void zapiszStan(Silnik &silnik);
	void wczytajStan(Silnik &silnik);

	friend std::ostream& operator <<(std::ostream &s, Silnik &silnik);
	friend std::istream& operator >>(std::istream &s, Silnik &silnik);

};