#include <iostream>
#include <string>
#include <fstream>
#include "Pojazd.h"
using namespace std;

Pojazd::Pojazd() {
#ifdef _DEBUG
	cout << "Wywolano domyslny konstruktor Pojazd" << endl;
#endif
	typ_pojazdu = "domyslny typ";

}
///Zdefiniowany operator strumieniowy
std::ostream& operator <<(std::ostream &s,Pojazd &pojazd)
{
	s << pojazd.typ_pojazdu << endl;
return s;
}
///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream &s, Pojazd &pojazd)
{
	s >> pojazd.typ_pojazdu;
	return s;
}

Pojazd::~Pojazd()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Pojazd" << endl;
#endif
}