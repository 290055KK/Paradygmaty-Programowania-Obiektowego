#include <iostream>

using namespace std;

const int rozmiar = 10;

void dodajOsobe(string *tablicaNazwisk, string *tablicaImien,int *tablicaIndeksow, string nazwisko, string imie, int indeks){
	for(int i = 0; i < rozmiar; i++){
		if(tablicaIndeksow[i] == 0){
			tablicaNazwisk[i] = nazwisko;
			tablicaImien[i] = imie;
			tablicaIndeksow[i] = indeks;
			return;
		}
	}
	return;
}

void ustawObecnosc(string *tablicaNazwisk, bool *tablicaObecnosci, string nazwisko, bool obecnosc){
	for (int i = 0; i < rozmiar; i++){
		if(tablicaNazwisk[i] == nazwisko){
			tablicaObecnosci[i] = obecnosc;
		}
	}
	return;
}

void drukujListe(int *tablicaIndeksow,string *tablicaImion, string *tablicaNazwisk, bool *tablicaObecnosci){
	cout << "Indeks              |Imie                |Nazwisko            |Obecnosc            \n";
	cout << "--------------------|--------------------|--------------------|--------------------\n";
	for(int i = 0; i < rozmiar; i++){
		if(tablicaNazwisk[i] != ""){
			cout << tablicaIndeksow[i];
			for(int j = 6; j < 20; j++){
				cout << " ";
			}
			cout << "|" << tablicaImion[i];
			for(int j = tablicaImion[i].size(); j < 20; j++){
				cout << " ";
			}
			cout << "|" << tablicaNazwisk[i];
			for(int j = tablicaNazwisk[i].size(); j < 20; j++){
				cout << " ";
			}
			cout<< "|" << tablicaObecnosci[i] << "\n";
		}
	}
	return;
}

void kasacja(string *tablicaImion, int *tablicaIndeksow, string *tablicaNazwisk, bool *tablicaObecnosci, string nazwiskoKasowanego){
	for(int i = 0; i < rozmiar; i++){
		if(tablicaNazwisk[i] == nazwiskoKasowanego){
			for(int j = i; j < rozmiar-1; j++){
				tablicaNazwisk[j] = tablicaNazwisk[j+1];
				tablicaImion[j] = tablicaImion[j+1];
				tablicaIndeksow[j] = tablicaIndeksow[j+1];
				tablicaObecnosci[j] = tablicaObecnosci[j+1];
			}
		}
	}
	
	return;
}

void edycjaImienia(string *imienia, string *nazwiska, string noweImie, string nazwisko){
	for(int i = 0; i < rozmiar; i++){
		if(nazwiska[i] == nazwisko){
			imienia[i] = noweImie;
		}
	}
}
void edycjaIndeksu(int *indeksy, string *nazwiska, int nowyIndeks, string nazwisko){
	for(int i = 0; i < rozmiar; i++){
		if(nazwiska[i] == nazwisko){
			indeksy[i] = nowyIndeks;
		}
	}
}
void edycjaNazwiska(string *nazwiska, string stareNazwisko, string noweNazwisko){
	for(int i = 0; i < rozmiar; i++){
		if(nazwiska[i] == stareNazwisko){
			nazwiska[i] = noweNazwisko;
		}
	}
}

int main(){
	string tabImienia[10];
	int tabIndeksy[10];
	string tabNazwiska[10];
	bool tabObecnosc[10];
	
	int input = 8;
	do{
		
		switch (input){
			case 1:{
				string nazwisko, imie; int indeks;
				cout << "Podaj naziwsko "; cin >> nazwisko;
				cout << "Podaj imie "; cin >> imie;
				cout << "Podaj indeks "; cin >> indeks;
				dodajOsobe(tabNazwiska, tabImienia, tabIndeksy,nazwisko,imie,indeks);
				input = 8;
			break;
			}
			case 2:{
				drukujListe(tabIndeksy, tabImienia, tabNazwiska, tabObecnosc);
				input = 8;
			break;
			}
			case 3:{
				string nazwisko; int jest;
				cout << "Podaj nazwisko "; cin >> nazwisko;
				cout << "Podaj 1 lub 0 zalezenie czy student jest "; cin >> jest;
				ustawObecnosc(tabNazwiska, tabObecnosc, nazwisko, jest != 0);
				input = 8;
			break;
			}
			case 4:{
				string nazwisko; cout << "Podaj nazwisko delikwenta " << endl; cin >> nazwisko;
				kasacja(tabImienia, tabIndeksy, tabNazwiska, tabObecnosc, nazwisko);
			break;
			}
			case 5:{
				cout << "Wybierz opcje z menu " << endl
					<< "1. Zmien imie. " << endl
					<< "2. Zmien indeks. " << endl
					<< "3. Zmien nazwisko. " << endl;
				cin >> input;
				switch(input){
					case 1:{
						string nazwisko, imie;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj nowe imie "; cin >> imie;
						edycjaImienia(tabImienia, tabNazwiska, imie, nazwisko);
					break;					
					}
					case 2:{
						string nazwisko; int indeks;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj nowy indeks "; cin >> indeks;
						edycjaIndeksu(tabIndeksy, tabNazwiska, indeks, nazwisko);
					break;
					}
					case 3:{
						string nazwisko, nowe;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj nowe nazwisko "; cin >> nowe;
						edycjaNazwiska(tabNazwiska,nazwisko,nowe);
					}
					default:
					break;
				}
				input = 8;
				break;
			}
			default:
			break;
			break;
		}
		cout << "Wybierz opcje z menu: " << endl 
			<< "1.Dodaj osobe." << endl
			<< "2.Wyswietl liste." << endl
			<< "3.Ustaw obecnosc." << endl
			<< "4.Usun osobe." << endl
			<< "5.Edytuj osobe." << endl;
	}while (cin >> input);
	
	return 0;
}