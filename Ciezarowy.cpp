#include <iostream>
#include <string>
#include <fstream>
#include "Ciezarowy.h"

using namespace std;
string nazwa_pliku_c = "Ciezarowy.txt";///<Nazwa pliku do zapisu stanu

Ciezarowy::Ciezarowy(){
#ifdef _DEBUG
	cout << "Wywolano domyslny konstruktor Ciezarowy" << endl;
#endif 
	marka = "Ciezarowy";
	model = "Ciezarowy";
	ladownosc = 1000;
}

void Ciezarowy::zmienParametrPojazdu(int nowa_wartosc){
	ladownosc = nowa_wartosc;
}

void Ciezarowy::zapiszStan(Ciezarowy &samochod) {
#ifdef _DEBUG
	cout << "Zapisano stan obiektu klasy Ciezarowe" << endl;
#endif 
	ofstream plik(nazwa_pliku_c);
	plik << samochod;
	plik.close();
}

void Ciezarowy::wczytajStan(Ciezarowy &samochod) {
#ifdef _DEBUG
	cout << "Wczytano stan obiektu klasy Ciezarowy" << endl;
#endif 
	ifstream plik(nazwa_pliku_c);
	plik >> samochod;
	plik.close();
}
bool Ciezarowy::operator==(const Ciezarowy &samochod)
{
	if (samochod.stan_tech == stan_tech && marka == samochod.marka && model == samochod.model && samochod.ladownosc == ladownosc)
		return true;
	else
		return false;
}
Ciezarowy & Ciezarowy::operator = (const Ciezarowy &samochod)
{
	stan_tech = samochod.stan_tech;
	marka = samochod.marka;
	model = samochod.model;
	ladownosc = samochod.ladownosc;
}

void Ciezarowy::wyswietlInfo(){
	cout << "Marka:" << marka << endl;
	cout << "Model:" << model << endl;
	cout << "Stan techniczny:" << stan_tech << endl;
	cout << "Ladownosc:" << ladownosc << endl;
}

///Zdefiniowany operator strumieniowy
std::ostream& operator <<(std::ostream &s, Ciezarowy &ciezarowy) {
	s << ciezarowy.marka << " " << ciezarowy.model << " " << ciezarowy.stan_tech << " " << ciezarowy.ladownosc << endl;
	s << *((Samochod*)&ciezarowy) << endl;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >>(std::istream& s, Ciezarowy &ciezarowy) {
	s >> ciezarowy.marka >> ciezarowy.model >> ciezarowy.stan_tech >> ciezarowy.ladownosc;
	s >> *((Samochod*)&ciezarowy);
	return s;
}

Ciezarowy::~Ciezarowy(){
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Ciezarowy" << endl;
#endif 
	--liczba_obiektów;
}
