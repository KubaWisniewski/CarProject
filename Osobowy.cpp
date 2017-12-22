#include <iostream>
#include <fstream>
#include "Osobowy.h"

using namespace std;
string nazwa_pliku_o = "Osobowy.txt";///<Nazwa pliku do zapisu stanu

Osobowy::Osobowy(){
#ifdef _DEBUG
	cout << "Wywolano domyslny konstruktor Osobowy" << endl;
#endif 
	ilosc_miejsc = 5;
	marka = "Osobowy";
	model = "Osobowy";
}

void Osobowy::zmienParametrPojazdu(int nowa_wartosc) {
#ifdef _DEBUG
	cout << "Wywolano metode wirtualna w klasie Osobowy" << endl;
#endif 
	ilosc_miejsc = nowa_wartosc;
}

void Osobowy::zapiszStan(Osobowy &samochod){
#ifdef _DEBUG
	cout << "Zapisano stan obiektu klasy Osobowy" << endl;
#endif
ofstream plik(nazwa_pliku_o);
plik << samochod;
plik.close();
}

void Osobowy::wczytajStan(Osobowy &samochod) {
#ifdef _DEBUG
	cout << "Wczytano stan obiektu klasy Osobowy" << endl;
#endif 
	ifstream plik(nazwa_pliku_o);
	plik >> samochod;
	plik.close();
}

void Osobowy::wyswietlInfo(){
	cout << "Marka:" << marka << endl;
	cout << "Model:" << model << endl;
	cout << "Stan techniczny:" << stan_tech << endl;
	cout << "Ilosc miejsc:" << ilosc_miejsc << endl;
}

bool Osobowy::operator==(const Osobowy &samochod)
{
	if (samochod.stan_tech == stan_tech && marka == samochod.marka && model == samochod.model && samochod.ilosc_miejsc == ilosc_miejsc)
		return true;
	else
		return false;
}
Osobowy & Osobowy::operator = (const Osobowy &samochod)
{
	stan_tech = samochod.stan_tech;
	marka = samochod.marka;
	model = samochod.model;
	ilosc_miejsc = samochod.ilosc_miejsc;
}
///Zdefiniowany operator strumieniowy 
std::ostream& operator <<(std::ostream &s, Osobowy &osobowy) {
	s << osobowy.marka <<" " << osobowy.model << " " << osobowy.stan_tech << " " << osobowy.ilosc_miejsc << endl;
	s << *((Samochod*)&osobowy) << endl;
	return s;
}

///Zdefiniowany operator strumieniowy 
std::istream& operator >> (std::istream& s, Osobowy &osobowy) {
	s >> osobowy.marka >> osobowy.model >> osobowy.stan_tech >> osobowy.ilosc_miejsc;
	s >> *((Samochod*)&osobowy);
	return s;
}

Osobowy::~Osobowy() {
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Osobowy" << endl;
#endif 
	--liczba_obiektów;
}