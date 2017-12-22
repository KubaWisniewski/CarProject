#include <string>
#include <iostream>
#include <fstream>
#include "Radio.h"

using namespace std;
string nazwa_pliku_r = "Radio.txt";///<Nazwa pliku do zapisu stanu obiektu

Radio::Radio(){
#ifdef _DEBUG
	cout << "Wywolano konstruktor Radio" << endl;
#endif 
	kolor = "Domyslny";
	cena = 100;
	typ_wyswietlacza = "Domyslny";
}

void Radio::zapiszStan(Radio &radio) {
#ifdef _DEBUG
	cout << "Zapisano stan obiektu klasy Radio" << endl;
#endif
	ofstream plik(nazwa_pliku_r);
	plik << radio;
	plik.close();
}

void Radio::wczytajStan(Radio &radio) {
#ifdef _DEBUG
	cout << "Wczytano stan obiektu klasy Radio" << endl;
#endif
	ifstream plik(nazwa_pliku_r);
	plik >> radio;
	plik.close();
}

///Zdefiniowano operator strumieniowy
std::ostream& operator <<(std::ostream &s, Radio &radio) {
	s << radio.kolor << " " << radio.cena << " " << radio.typ_wyswietlacza << endl;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >>(std::istream& s, Radio &radio) {
	s >> radio.kolor >> radio.cena >> radio.typ_wyswietlacza;
	return s;
}

Radio::~Radio(){
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Radio" << endl;
#endif 
}