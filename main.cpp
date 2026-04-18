#include <iostream>

using namespace std;

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

class ListaObecnosci{
	private:
		bool tabObecnosc[rozmiar] = {0};
		Osoba *tabOsob;
	public:
		ListaObecnosci(Osoba *tab);
		void ustawObecnosc(string nazwisko);
		bool *getTablicaObecnosci();
};

void dodajOsobe(Osoba *osoby, Osoba o){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == ""){
			osoby[i] = o;
			break;
		}
	}
	return;
}

void kasacja(Osoba *osoby, ListaObecnosci *lista, int lList, string nazwiskoKasowanego){
	for(int i = 0; i < rozmiar; i++){
		if(osoby[i].getNazwisko() == nazwiskoKasowanego){
			for(int j = i; j < rozmiar-1; j++){
				osoby[j].setNazwisko(osoby[j+1].getNazwisko());
				osoby[j+1].setNazwisko("");
				osoby[j].setImie(osoby[j+1].getImie());
				osoby[j].setIndeks(osoby[j+1].getIndeks());
				osoby[j].setWzrost(osoby[j+1].getWzrost());
				osoby[j].setData(osoby[j+1].getData());
				for(int i = 0; i < lList; i++){
					lista[i].getTablicaObecnosci()[j] = 0;
				}	
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


ListaObecnosci::ListaObecnosci(Osoba *tab){
	tabOsob = tab;
}
void ListaObecnosci::ustawObecnosc(string nazwisko){
	for (int i = 0; i < rozmiar; i++){
		if(tabOsob[i].getNazwisko() == nazwisko){
			tabObecnosc[i] = !tabObecnosc[i];
			break;
		}
	}
	return;
}
bool *ListaObecnosci::getTablicaObecnosci(){
	return tabObecnosc;
}
class InterfejsUzytkownika{
	private:
		int input;
		Osoba *tabOsob;
		ListaObecnosci *tabListaObecnosc;
		int lList;
	public:
		InterfejsUzytkownika(Osoba *tabO, ListaObecnosci *tabL, int l);
		void petla();
	
};

InterfejsUzytkownika::InterfejsUzytkownika(Osoba *tabO, ListaObecnosci *tabL, int l){
	input = 8;
	tabOsob = tabO;
	tabListaObecnosc = tabL;
	lList = l;
}

void InterfejsUzytkownika::petla(){
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
				int i;
				cout << "Podaj numer listy od 1 do " << lList << " "; cin >> i;
				drukujListe(tabOsob, tabListaObecnosc[i-1].getTablicaObecnosci());
				input = 8;
			break;
			}
			case 3:{
				string nazwisko; int i;
				cout << "Podaj nazwisko "; cin >> nazwisko;
				cout << "Podaj numer listy od 1 do " << lList << " "; cin >> i;
				tabListaObecnosc[i-1].ustawObecnosc(nazwisko);
				input = 8;
			break;
			}
			case 4:{
				string nazwisko; cout << "Podaj nazwisko delikwenta " << endl; cin >> nazwisko;
				kasacja(tabOsob, tabListaObecnosc, 2, nazwisko);
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
	
}
// rozmiar = 10
int main(){	
	Osoba tabOsob[rozmiar];
	ListaObecnosci tabObecnosci[2] = { 
		ListaObecnosci(tabOsob), 
		ListaObecnosci(tabOsob) 
	};
	
	InterfejsUzytkownika ui(tabOsob, tabObecnosci,2);
	
	ui.petla();
	
	return 0;
}