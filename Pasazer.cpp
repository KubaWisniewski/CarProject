#include <iostream>a
#include <string>
#include <fstream>
#include "Pasazer.h"

using namespace std;
string nazwa_pliku_pas = "Pasazer.txt";///<Nazwa pliku do zapisu stanu obiektu

Pasazer::Pasazer() {
#ifdef _DEBUG
	cout << "Wywolano konstruktor Pasazer" << endl;
#endif
	Imie = "Brak";
	Nazwisko = "Brak";
	wiek = 0;
	waga = 0;
}

void Pasazer::wyswietlInfo(){
	cout << "Imie:" << Imie << endl;
	cout << "Nazwisko" << Nazwisko << endl;
	cout << "Wiek:" << wiek << endl;
	cout << "Waga" << waga << endl;
}

void Pasazer::zmien_imie(string nowe_imie) {
	Imie = nowe_imie;
}

void Pasazer::zmien_nazwisko(string nowe_nazwisko) {
	Nazwisko = nowe_nazwisko;
}

void Pasazer::zmien_wiek(int nowy_wiek) {
	wiek = nowy_wiek;
}

void Pasazer::zmien_wage(int nowa_waga) {
	waga = nowa_waga;
}

void Pasazer::zapiszStan(Pasazer &pasazer) {
#ifdef _DEBUG
	cout << "Zapisano stan obiektu klasy Pasazer" << endl;
#endif 
	ofstream plik(nazwa_pliku_pas);
	plik << pasazer;
	plik.close();
}

void Pasazer::wczytajStan(Pasazer &pasazer) {
#ifdef _DEBUG
	cout << "Wczytano stan obiektu klasy Pasazer" << endl;
#endif 
	ifstream plik(nazwa_pliku_pas);
	plik >> pasazer;
	plik.close();
}

///Zdefiniowany operator strumieniowy 
std::ostream& operator <<(std::ostream &s, Pasazer &pasazer) {
	s << pasazer.Imie << endl << pasazer.Nazwisko << endl << pasazer.wiek << endl << pasazer.waga;
	return s;
}

///Zdefiniowany operator strumieniowy
std::istream& operator >>(std::istream &s, Pasazer &pasazer) {
	s >> pasazer.Imie >> pasazer.Nazwisko >> pasazer.wiek >> pasazer.waga;
	return s;
}

Pasazer::~Pasazer()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Pasazer" << endl;
#endif

}