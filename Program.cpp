#include <iostream>
#include <string>
#include <vector>
#include "Samochod.h"
#include "Osobowy.h"
#include "Ciezarowy.h"
#include "kontener.h"

using namespace std;

void clear() {
	system("cls");
}

int main() {
	
	Kontener<Samochod>kontener;
	int opcja;
	int obiekt = 0;
	string plik = "";

	opcja = 99;
	do {
		switch (opcja)
		{
		case 99:
			cout << "MENU PROGRAMU" << endl;
			cout << "------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1:Zmien obiekt" << endl;
			cout << "2:Dodaj obiekty do kontenera" << endl;
			cout << "3:Wyswietl obiekty" << endl;
			cout << "4:Usun wybrany obiekt" << endl;
			cout << "5:Zapis stanu obiektu do pliku" << endl;
			cout << "6:Odczyt stanu obiektu z pliku" << endl;
			cout << "7:Testowanie kontenera " << endl;
			cout << "0:Zamknij program" << endl;
			cout << "------------------" << endl;
			cout << "Opcja: ";
			cin >> opcja;
			break;
		case 1:
			clear();
			if (kontener.size() != 0) {
				kontener.wyswietlWszystkieObiekty();
				do {
					cout << "Zmien obiekt:(podaj liczbe calkowita z zakresu 0-" << kontener.size() - 1 << ":";
					try {

						cin >> obiekt;
					}
					catch (ifstream::failure) {
						cout << "Nie podano liczby." << endl;
						cin.clear();
						cin.ignore();
					}
				} while (!(obiekt >= 0 && obiekt < kontener.size()));
				clear();
				cout << "Wybrano obiekt nr" << endl;

			}
			else
				cout << "Pusty kontener ." << endl;
			opcja = 99;
			break;
		case 2:
			{
				int liczba;
				do {
					cout << "Liczba obiekto do dodania:";
					try {
						liczba = 0;
						cin >> liczba;
					}
					catch (ifstream::failure) {
						cout << "Nie podano liczby." << endl;
						cin.clear();
						cin.ignore();
					}
				} while (liczba <= 0);
				for (int i = 0; i < liczba; i++) {
					
					string nowa_marka, nowy_model;
					int stan;
					cout << "Obiekt" << i + 1 << endl;
					cout << "Podaj marke:";
					cin >> nowa_marka;
					cout << "Podaj model:";
					cin >> nowy_model;
					do {
						stan = 0;
						cout << "Podaj stan:";
						try {
							cin >> stan;
						}
						catch (ifstream::failure) {
							cout << "Nie podano liczby." << endl;
							cin.clear();
							cin.ignore();
						}
					} while (stan <= 0);
					Samochod sam2(nowa_marka, nowy_model, stan);
					kontener.dodajElement(sam2);

				}
				clear();
				cout << "Liczba dodanych obiektow:" << liczba << endl;
				opcja = 99;
				break;
			}
		case 3:
		
			cout << "Liczba obiektow:" << kontener.size() << endl;
			kontener.wyswietlWszystkieObiekty();
			
			cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac" << endl;
			getchar();
			opcja = 99;
			break;
		case 4:
		{
			clear();
			if (obiekt < kontener.size()) {
				string ch;
				cout << "Czy chesz usunac obiekt nr" <<obiekt<<"(t-akceptuj)" <<endl;
				cin >> ch;
				if (ch == "t") {
					kontener.usunElement(obiekt);
					cout << "Usunieto obiekt nr" << obiekt << endl;

				}

			}
			else {
				cout << "Obiekt nr" << obiekt << "nie istnieje" << endl;
			}
			opcja = 99;
			break;
		}
		case 5:
		{
			clear();
			cout << "Wpisz nazwe pliku(bez .txt):";
			cin >> plik;
			kontener.zapiszObiekt(obiekt, plik);
			opcja = 99;
			break;
		}
		case 6:
		{
			clear();
			cout << "Wpisz nazwe pliku (bez .txt):";
			cin >> plik;
			try {
				kontener.wczytajObiekt(plik);
			}
			catch (string err) {
				cout << err << endl;
			}
			opcja = 99;
			break;
		}
		case 7:
		{
			clear();
			Kontener<Samochod> kont1, kont2;
			Samochod sam1("pierwszy", "test", 0);
			Samochod sam2("drugi", "test", 0);
			Samochod sam3("trzeci", "test3", 3);
			cout << "Testowanie kontenera" << endl;
			cout << "Dodano obiekt" << endl;
			kont1.dodajElement(sam1);
			kont1.dodajElement(sam2);
			kont2 = kont1;
			cout << "Kontener 1 - liczba obiektow:" << kont1.size() << endl;
			cout << "Kontener 2 - liczba obiektow:" << kont2.size() << endl;
			if (kont1 == kont2)
				cout << "Kontenery sa identyczne." << endl;
			else
				cout << "Kontenery sa rozne." << endl;
			cout << "Dodano obiekt" << endl;
			kont2.dodajElement(sam3);
			cout << "Kontener 2 - liczba obiektow" << kont2.size() << endl;
			cout << "Usunieto obiekt" << endl;
			kont2.usunOstatni();
			cout << "Kontener 2 - liczba obiektow" << kont2.size() << endl;

			cout << "Test operatora []" << endl;
			kont2[0].wyswietlInfo();

			cout << "Sprawdzanie wyjatkow" << endl;
			try {
				kont2[4].wyswietlInfo();
			}
			catch (string err) {
				cout << err << endl;
			}
		
			cout << endl << "Nacisnij klawisz." << endl;
			getchar();
			opcja = 99;
			break;
		}
		default:
			clear();
			cout << "Wybrano niepoprawna opcje." << endl;
			opcja = 99;
		}
	} while (opcja != 0);
	return 0;



}