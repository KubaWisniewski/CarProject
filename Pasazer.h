#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Pasazer
{
	
private:
	string Imie;
	string Nazwisko;
	int wiek;
	int waga;
public:
	Pasazer();
	~Pasazer();
	
	void wyswietlInfo();
	void zmien_imie(string nowe_imie);
	void zmien_nazwisko(string nowe_nazwisko);
	void zmien_wiek(int nowy_wiek);
	void zmien_wage(int nowa_waga);

	void zapiszStan(Pasazer &pasazer);
	void wczytajStan(Pasazer &pasazer);

	friend std::ostream& operator <<(std::ostream &s, Pasazer &pasazer);
	friend std::istream& operator >>(std::istream &s, Pasazer &pasazer);

};