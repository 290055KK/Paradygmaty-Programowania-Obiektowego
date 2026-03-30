#include <iostream>

using namespace std;
// Dodac listy obecnosci v1 v2 v3,  wskazniki do osob z danych dni 
const int rozmiar = 10;

class Osoba{
	string imie = "";
	string nazwisko = "";
	string data = "";
	int indeks = 0;
	int wzrost = 0;
	public:
	
	void setImie(string s);
	void setNazwisko(string s);
	void setIndeks(int i);
	
	void setWzrost(int i);
	void setData(string s);
	
	
	string getImie();
	string getNazwisko();
	int getIndeks();
	string getData();
	int getWzrost();
};

void Osoba::setImie(string s){
	if(s != ""){
		imie = s;
	}
	return;
}
void Osoba::setNazwisko(string s){
	nazwisko = s;
	return;
}
void Osoba::setIndeks(int i){
	if(i != 0){
		indeks = i;
	}
	return;
}
void Osoba::setWzrost(int i){
	if(i != 0){
		wzrost = i;
	}
	return;
}
void Osoba::setData(string s){
	if(s != ""){
		data = s;
	}
	return;
}

string Osoba::getImie(){
	return imie;
}
string Osoba::getNazwisko(){
	return nazwisko;
}
int Osoba::getIndeks(){
	return indeks;
}
int Osoba::getWzrost(){
	return wzrost;
}
string Osoba::getData(){
	return data;
}


void dodajOsobe(Osoba *osoby, Osoba o){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == ""){
			osoby[i] = o;
			break;
		}
	}
	return;
}

void ustawObecnosc(Osoba *osoby, bool *tablicaObecnosci, string nazwisko, bool obecnosc){
	for (int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwisko){
			tablicaObecnosci[i] = obecnosc;
			break;
		}
	}
	return;
}

void drukujListe(Osoba *tabOsob, bool *tablicaObecnosci){
	cout << "Indeks              |Imie                |Nazwisko            |Obecnosc            |Wzrost (cm)         |Data urodzenia      \n";
	cout << "--------------------|--------------------|--------------------|--------------------|--------------------|--------------------\n";
	for(int i = 0; i < rozmiar; i++){
		if(tabOsob[i].getNazwisko() != ""){
			cout << tabOsob[i].getIndeks();
			for(int j = 6; j < 20; j++){
				cout << " ";
			}
			cout << "|" << tabOsob[i].getImie();
			for(int j = tabOsob[i].getImie().size(); j < 20; j++){
				cout << " ";
			}
			cout << "|" << tabOsob[i].getNazwisko();
			for(int j = tabOsob[i].getNazwisko().size(); j < 20; j++){
				cout << " ";
			}
			cout<< "|" << tablicaObecnosci[i];
			for(int j = 1; j < 20; j++){
				cout << " ";
			}
			cout << "|" << tabOsob[i].getWzrost();
			for(int j = 3; j < 20; j++){
				cout << " ";
			}
			cout << "|" << tabOsob[i].getData() << "\n";

			
		}
	}
	return;
}

void kasacja(Osoba *osoby, bool *tablicaObecnosci, string nazwiskoKasowanego){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwiskoKasowanego){
			for(int j = i; j < rozmiar-1; j++){
				osoby[j].setNazwisko(osoby[j+1].getNazwisko());
				osoby[j+1].setNazwisko("");
				osoby[j].setImie(osoby[j+1].getImie());
				osoby[j].setIndeks(osoby[j+1].getIndeks());
				osoby[j].setWzrost(osoby[j+1].getWzrost());
				osoby[j].setData(osoby[j+1].getData());
				tablicaObecnosci[j] = tablicaObecnosci[j+1];
				tablicaObecnosci[j+1] = false;
			}
			break;
		}
	}
	
	return;
}


void edycjaImienia(Osoba *osoby, string nazwisko, string noweImie){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwisko){
			osoby[i].setImie(noweImie);
		}
	}
}
void edycjaIndeksu(Osoba *osoby, string nazwisko, int nowyIndeks){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwisko){
			osoby[i].setIndeks(nowyIndeks);
		}
	}
}
void edycjaNazwiska(Osoba *osoby, string stareNazwisko, string noweNazwisko){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == stareNazwisko){
			osoby[i].setNazwisko(noweNazwisko);
		}
	}
}
void edycjaDaty(Osoba *osoby, string nazwisko, string data){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwisko){
			osoby[i].setData(data);
		}
	}
}
void edycjaWzrostu(Osoba *osoby, string nazwisko, int wzrost){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwisko){
			osoby[i].setWzrost(wzrost);
		}
	}
}

int main(){	
	Osoba tabOsob[10];
	bool tabObecnosc[10];
	
	int input = 8;
	do{
		
		switch (input){
			case 1:{
				string s; int i; Osoba o;
				cout << "Podaj naziwsko "; cin >> s; o.setNazwisko(s);
				cout << "Podaj imie "; cin >> s; o.setImie(s);
				cout << "Podaj indeks "; cin >> i; o.setIndeks(i);
				cout << "Podaj wzrost (cm) "; cin >> i; o.setWzrost(i);
				cout << "Podaj date urodzenia "; cin >> s; o.setData(s);
				dodajOsobe(tabOsob, o);
				input = 8;
			break;
			}
			case 2:{
				drukujListe(tabOsob, tabObecnosc);
				input = 8;
			break;
			}
			case 3:{
				string nazwisko; int jest;
				cout << "Podaj nazwisko "; cin >> nazwisko;
				cout << "Podaj 1 lub 0 zalezenie czy student jest "; cin >> jest;
				ustawObecnosc(tabOsob, tabObecnosc, nazwisko, jest != 0);
				input = 8;
			break;
			}
			case 4:{
				string nazwisko; cout << "Podaj nazwisko delikwenta " << endl; cin >> nazwisko;
				kasacja(tabOsob, tabObecnosc, nazwisko);
			break;
			}
			case 5:{
				cout << "Wybierz opcje z menu " << endl
					<< "1. Zmien imie. " << endl
					<< "2. Zmien indeks. " << endl
					<< "3. Zmien nazwisko. " << endl
					<< "4. Zmien wzrost. " << endl
					<< "5. Zmien date urodzenia." << endl;
				cin >> input;
				switch(input){
					case 1:{
						string nazwisko; string imie;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko; 
						cout << "Podaj nowe imie "; cin >> imie; 
						edycjaImienia(tabOsob, nazwisko, imie);
					break;					
					}
					case 2:{
						string nazwisko; int indeks;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj nowy indeks "; cin >> indeks;
						edycjaIndeksu(tabOsob, nazwisko, indeks);
					break;
					}
					case 3:{
						string nazwisko, nowe;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj nowe nazwisko "; cin >> nowe;
						edycjaNazwiska(tabOsob, nazwisko, nowe);
					break;
					}
					case 4:{
						string nazwisko; int wzrost;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj nowy wzrost (cm) "; cin >> wzrost;
						edycjaWzrostu(tabOsob, nazwisko, wzrost);
					break;
					}
					case 5:{
						string nazwisko, data;
						cout << "Podaj nazwisko delikwenta "; cin >> nazwisko;
						cout << "Podaj poprawna date urodzenia "; cin >> data;
						edycjaDaty(tabOsob, nazwisko, data);
					break;
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