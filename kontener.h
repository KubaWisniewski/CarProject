#pragma once
#include <iostream>

using namespace std; 

template<class TYP>
struct Wezel {
	TYP ob;
	Wezel *nastepny_wezel;
};

template <class TYP>
class Kontener {
private:
	Wezel<TYP> *poczatek;
	int liczba_elementow;
public:
	Kontener();
	void dodajElement(const TYP &ob);
	void usunElement(int indeks);
	void usunOstatni();
	TYP& zwrocObiekt(int indeks);
	
	void zapiszObiekt(int indeks, string nazwa_pliku);
	void wczytajObiekt(string nazwa_pliku);
	void wyswietlWszystkieObiekty();
	Wezel<TYP>*zwrocWskaznikWezla(int indeks);
	int size();
	int indexOf(const TYP &);
	~Kontener();

	bool operator== (Kontener &);
	Kontener& operator=(Kontener &);
	TYP& operator[](int i);
};



template <class TYP>
Kontener<TYP>::Kontener() {
	liczba_elementow = 0;
	poczatek = NULL;
}

template <class TYP>
void Kontener <TYP>::dodajElement(const TYP &ob) {
	if (indexOf(ob) == -1) {
		Wezel<TYP>*nowy_wezel;
		nowy_wezel = new Wezel<TYP>();
		nowy_wezel->nastepny_wezel = NULL;
		nowy_wezel->ob = ob;
		if (liczba_elementow == 0)
		{
			poczatek = nowy_wezel;
		}
		else
		{
			Wezel<TYP> *tmp;
 			tmp = zwrocWskaznikWezla(liczba_elementow - 1);
			tmp->nastepny_wezel = nowy_wezel;
		}
		liczba_elementow++;
	}
	else
		cout << "Obiekt znajduje sie juz w kntenerze." << endl;
}
template <class TYP>
void Kontener<TYP>::usunElement(int indeks)
{
	if (liczba_elementow == 1 || indeks == liczba_elementow - 1) {
		usunOstatni();
		return;
	}
	else if (indeks == 0) {
		Wezel<TYP> *tmp;
		tmp = new Wezel<TYP>();
		tmp = poczatek->nastepny_wezel;
		delete poczatek;
		poczatek = tmp;

	}
	else
	{
		
		Wezel <TYP> *wezel;
		Wezel <TYP> *wezel_pop;
		wezel = zwrocWskaznikWezla(indeks);
		wezel_pop = zwrocWskaznikWezla(indeks - 1);
		wezel_pop->nastepny_wezel = wezel->nastepny_wezel;
		delete wezel;
		delete wezel_pop;
	}
	liczba_elementow--;
}

template<class TYP>
void Kontener<TYP>::usunOstatni() {
	if (liczba_elementow < 2)
	{
		delete poczatek;
		poczatek = NULL;
	}
	else
	{
		Wezel<TYP>*tmp = zwrocWskaznikWezla(liczba_elementow - 2);
		delete tmp->nastepny_wezel;
		
	}
	liczba_elementow--;
}
template <class TYP>
TYP& Kontener<TYP>::zwrocObiekt(int indeks)
{
	return zwrocWskaznikWezla(indeks)->ob;
}
template <class TYP>
void Kontener<TYP>::zapiszObiekt(int indeks, string nazwa_pliku)
{
	TYP obiekt = (*this)[indeks];
	nazwa_pliku += string(".txt");
	ofstream plik;
	plik.open(nazwa_pliku);
	plik << obiekt;
	plik.close();
	cout << "Zapis danych do pliku: " << nazwa_pliku << endl;

}
template <class TYP>
void Kontener<TYP>::wczytajObiekt(string nazwa_pliku) {
	TYP obiekt;
	nazwa_pliku += string(".txt");
	ifstream plik;
	plik.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		plik.open(nazwa_pliku);
	}
	catch (ifstream::failure e) {
		throw string("Nie znaleziono pliku" + nazwa_pliku);
	}
	plik >> obiekt;
	plik.close();
	cout << "Wczytywanie danych z pliku: " << nazwa_pliku << endl;
	dodajElement(obiekt);
}
template<class TYP>
Wezel<TYP>* Kontener<TYP>::zwrocWskaznikWezla(int indeks) {
	Wezel<TYP> *wezel = poczatek;
	for (int i = 0; i < indeks; i++) {
		if (wezel == NULL)
			return NULL;
		wezel = wezel->nastepny_wezel;
	}
	return wezel;
}
template <class TYP>
void Kontener<TYP>::wyswietlWszystkieObiekty()
{
	if (liczba_elementow != 0)
		for (int i = 0; i < liczba_elementow; i++) {
			cout << "Obiekt nr " << indexOf((*this)[i]) << endl;
			(*this)[i].wyswietlInfo();
		}
	else
		cout << "Brak obiektow." << endl;
}
template <class TYP>
int Kontener<TYP>::size() {
	return liczba_elementow;
}
template <class TYP>
int Kontener<TYP>::indexOf(const TYP &k) {
	int indeks = -1;
	for (int i = 0; i < liczba_elementow; i++)
		if ((*this)[i] == k) {
			indeks = i;
			break;
		}
	return indeks;
}

template <class TYP>
Kontener <TYP>::~Kontener() {
	while (liczba_elementow > 0)
		usunOstatni();
}
template <class TYP>
Kontener<TYP>& Kontener<TYP>::operator=(Kontener &k) {
	for(int i = 0; i < k.liczba_elementow; i++)
		dodajElement(k[i]);
	return *this;
}
template <class TYP >
bool Kontener<TYP>::operator==(Kontener &k) {
	for (int i = 0; i < k.liczba_elementow; i++)
		if (!(k[i] == (*this)[i]))
			return false;
	return true;
}

template <class TYP>
TYP&Kontener <TYP>::operator[](int i) {
	if (i < 0 || i >= liczba_elementow)
		throw string("Nie istnieje taki obiekt.");
	return zwrocObiekt(i);
}

