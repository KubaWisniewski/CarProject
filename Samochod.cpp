#include <iostream>
#include <string>
#include <fstream>
#include"Samochod.h"
#include "Pasazer.h"

using namespace std;

int Samochod::liczba_pasazerow = 0;
int Samochod::liczba_obiektów = 0;
string nazwa_pliku_s = "Samochod.txt";///<Nazwa pliku do zapisu stanu obiektu

Samochod::Samochod(){
#ifdef _DEBUG
	cout << "Wywolano domyslny konstruktor Samochod" << endl;
#endif
	marka = "domyslna_marka";
	model = "domyslny_model";
	typ_samochodu = "domyslny_typ";
	stan_tech = 5;
	liczba_obiektów++;
}

Samochod::Samochod(int stan){
#ifdef _DEBUG
	cout << "Wywolano konstruktor Samochod" << endl;
#endif
	typ_samochodu = "domyslny_typ";
	stan_tech = stan;
	marka = "domyslna_marka";
	model = "domyslny_model";
	liczba_obiektów++; 
}
//Samochod::Samochod(const Samochod &samochod)
//{
//	marka = samochod.marka;
//	model = samochod.model;
//	radio = samochod.radio;
//	silnik = samochod.silnik;
//	stan_tech = samochod.stan_tech;
//	vector<Pasazer>pasazer = samochod.pasazer;
//}

void Samochod::wyswietlPasazerow() {
	if (pasazer.size() != 0)
	{
		for (size_t i = 0; i < pasazer.size(); i++)
		{
			cout << "Pasazer:" << i << endl;
			pasazer[i].wyswietlInfo();
			cout << endl;
		}
	}
	else
		cout << "Brak pasazerow" << endl;
	}

void Samochod::dodajPasazera() {
	Pasazer *tmp_pasazer = new Pasazer();
	pasazer.push_back(*tmp_pasazer);
	delete tmp_pasazer;
	liczba_pasazerow++;
}

void Samochod::usunPasazera() {
	for (size_t i = 0; i < pasazer.size();i++)
	{
		pasazer.erase(pasazer.begin() + i);
	}
	--liczba_pasazerow;
}

void Samochod::wyswietlIlosc(){
	cout << liczba_obiektów << endl;
}

void Samochod::wyswietlInfo(){
	cout << "Typ samochodu:" << typ_samochodu << endl;
	cout << "Marka:" << marka << endl;
	cout << "Model:" << model << endl;
	cout << "Stan techniczny:" << stan_tech << endl;
}

void Samochod::zmienMarke(string nowa_marka){
	marka = nowa_marka;
}

void Samochod::zmienModel(string nowy_model){
	model = nowy_model;
}

void Samochod::zmienParametrPojazdu(int nowa_wartosc){
	stan_tech = nowa_wartosc;
}

void Samochod::zapiszStan(Samochod &samochod){
#ifdef _DEBUG
	cout << "Zapisano stan obiektu klasy Samochod" << endl;
#endif 
	ofstream plik(nazwa_pliku_s);
	plik << samochod;
	plik.close();
	samochod.silnik.zapiszStan(samochod.silnik);
	samochod.radio.zapiszStan(samochod.radio);
	for (size_t i = 0; i < samochod.pasazer.size(); i++)
	{
		samochod.pasazer[i].zapiszStan(samochod.pasazer[i]);
	}
}

void Samochod::wczytajStan(Samochod &samochod){
#ifdef _DEBUG
	cout << "Wczytano stan obiektu klasy Samochod" << endl;
#endif 
	ifstream plik(nazwa_pliku_s);
	plik >> samochod;
	plik.close();
	samochod.silnik.wczytajStan(samochod.silnik);
	samochod.radio.wczytajStan(samochod.radio);
	for (size_t i = 0; i < samochod.pasazer.size(); i++)
	{
		samochod.pasazer[i].wczytajStan(samochod.pasazer[i]);
	}
}

bool Samochod::operator==(const Samochod &samochod){
	if (samochod.stan_tech == stan_tech)
		return true;
	else
		return false;
}

bool Samochod::operator<(const Samochod &samochod){
	if (samochod.stan_tech < stan_tech)
		return false;
	else
		return true;
}

bool Samochod::operator>(const Samochod &samochod){
	if (samochod.stan_tech>stan_tech)
		return false;
	else
		return true;
}

Samochod & Samochod::operator=(const Samochod &samochod){
	stan_tech = samochod.stan_tech;
	marka = samochod.marka;
	model = samochod.model;
	return *this;
}

Samochod & Samochod::operator+=(const Samochod &samochod){
	stan_tech += samochod.stan_tech;
	return *this;
}

Samochod & Samochod::operator-=(const Samochod &samochod){
	stan_tech -= samochod.stan_tech;
	return *this;
}

Samochod & Samochod::operator*=(const Samochod &samochod){
	stan_tech *= samochod.stan_tech;
	return *this;
}

Samochod & Samochod::operator++(int){
	stan_tech++;
	return *this;
}

Samochod & Samochod::operator--(int){
	if (stan_tech != 0)
		stan_tech--;
	return *this;
}

///Zdefinowany operator strumieniowy 
std::ostream& operator <<(std::ostream &s, Samochod &samochod) {
	s << samochod.marka << " " << samochod.model << " " << samochod.stan_tech << endl;
	s << samochod.silnik << endl;
	s<< samochod.radio << endl;
	for (size_t i = 0; i < samochod.pasazer.size(); i++)
	{
		s << samochod.pasazer[i] << endl;
	}
	s << *((Pojazd*)&samochod) << endl;
		return s; 
}

///Zdefiniowany operator strumieniowy
std::istream& operator >> (std::istream& s, Samochod &samochod) {
	s >> samochod.marka >> samochod.model >> samochod.stan_tech;
	s >> samochod.silnik;
	s >> samochod.radio;
	for (size_t i = 0; i < samochod.pasazer.size(); i++)
	{
		s >> samochod.pasazer[i];
	}
	s >> *((Pojazd*)&samochod);
	return s;
}

Samochod::~Samochod(){
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Samochod" << endl;
#endif 
	--liczba_obiektów;
}