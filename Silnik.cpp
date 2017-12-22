#include <string>
#include <iostream>
#include <fstream>
#include "Silnik.h"

using namespace std;

string nazwa_pliku_si = "silnik.txt";///<Nazwa pliku do zapisu stanu obiektu

Silnik::Silnik(){
#ifdef _DEBUG
	cout << "Wywolano konstruktor Silnik" << endl;
#endif
	Moc = 100;
	pojemnosc = 2.0;
	rodzaj = "Domyslny";
}

void Silnik::zapiszStan(Silnik &silnik) {
#ifdef _DEBUG
	cout << "Zapisano stan obiektu klasy Silnik" << endl;
#endif 
	ofstream plik(nazwa_pliku_si);
	plik << silnik;
	plik.close();
}

void Silnik::wczytajStan(Silnik &silnik) {
#ifdef _DEBUG
	cout << "Wczytano stan obiektu klasy Silnik" << endl;
#endif
	ifstream plik(nazwa_pliku_si);
	plik >> silnik;
	plik.close();
}

///Zdefinowany operator strumieniowy
std::ostream& operator <<(std::ostream& s, Silnik &silnik) {
	s << silnik.Moc << " " << silnik.pojemnosc << " " << silnik.rodzaj << endl;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator>> (std::istream& s, Silnik &silnik) {
	s >> silnik.Moc >> silnik.pojemnosc >> silnik.rodzaj;
	return s;
}

Silnik::~Silnik(){
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Silnik" << endl;
#endif 
}