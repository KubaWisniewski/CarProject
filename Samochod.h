#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Pojazd.h"
#include "Silnik.h"
#include "Radio.h"
#include "Pasazer.h"
#include <vector>


class Samochod :public Pojazd {
private:
	string typ_samochodu;
public:
	vector<Pasazer>pasazer;
	Silnik silnik;
	Radio radio;
	string model;
	string marka;
	int stan_tech;
	int liczba_pasazerow;
	static int liczba_obiektów;
	Samochod();
	Samochod(int stan);
	Samochod(string nowa_marka, string nowy_model, int stan);
	~Samochod();
//Samochod(const Samochod &samochod);
	void wyswietlPasazerow();
	void dodajPasazera();
	void usunPasazera();
	void zmienModel(string nowy_model);
	void zmienMarke(string nowa_marka);
	void wyswietlInfo();
	void wyswietlIlosc();

	
	void zapiszStan(Samochod &samochod);
	void wczytajStan(Samochod &samochod);

	void zmienParametrPojazdu(int nowa_wartosc);

	bool operator ==(const Samochod &samochod);
	bool operator <(const Samochod &samochod);
	bool operator >(const Samochod &samochod);
	Samochod& operator =(const Samochod &samochod);
	Samochod& operator +=(const Samochod &samochod);
	Samochod& operator -=(const Samochod &samochod);
	Samochod& operator *=(const Samochod &samochod);
	Samochod& operator ++(int);
	Samochod& operator --(int);

	friend std::ostream& operator <<(std::ostream &s, Samochod &samochod);
	friend std::istream& operator >>(std::istream &s, Samochod &samochod);

};