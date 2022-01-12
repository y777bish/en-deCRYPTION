#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "plik.h"
using namespace std;

elementy::elementy(int argi, char* argj[])
{
	for (int i{}; i < argi; i++)
	{
		if (string(argj[i]) == "-od")
		{
			odszyfrowywanie = true;
		}
		/*else if (string(argj[i]) == "-odbk")
		{
			odszyfrowywanieBezKlucza = true;
		}*/
		else if (string(argj[i]) == "-sz")
		{
			szyfrowanie = true;
		}
		else if (string(argj[i]) == "-nin")
		{
			if (i + 1 < argi)
			{
				nazwaInput = argj[++i];
			}
		}
		else if (string(argj[i]) == "-nout")
		{
			if (i + 1 < argi)
			{
				nazwaOutput = argj[++i];
			}
		}
		else if (string(argj[i]) == "-nk")
		{
			if (i + 1 < argi)
			{
				nazwaKlucza = argj[++i];
			}
		}
		/*else if (string(argj[i]) == "-e")
		{
			if (i + 1 < argi)
			{
				lacz = true;
				nazwaPliku1 = argj[i + 1];
				nazwaPliku2 = argj[i + 2];
			}
		}*/
	}

	//sprawdzanie tego co użytkownik wklepie w konsolę
}


bool istnieje(string sciezkaPliku)
{
	ifstream plik;
	plik.open(sciezkaPliku.c_str()); //

	return bool(plik);
}

vector<int> uzyskajKlucz(string nazwaKlucza)
{
	ifstream klucz; //klucz jest klasą do operowania na pliku

	vector<int> kluczInt;
	vector<char> kluczChar;

	klucz.open(nazwaKlucza); //operujemy na pliku o nazwie zapisanej w zmiennej nazwaKlucza
	char kluczChar_data;
	klucz >> kluczChar_data;

	while (!klucz.eof()) //dopóki nie skończy się plik...
	{
		kluczChar.push_back(toupper(kluczChar_data)); //push_back dodaje nowy element na koniec vectora, toupper robi CAPS na każdej literce
		klucz >> kluczChar_data;
	}

	klucz.close();

	for (int i{}; i < kluczChar.size(); i++)
	{
		kluczInt.push_back((int)kluczChar[i] - 65);
	}

	return kluczInt;
}

void dekodowanieZkluczem(string nazwaInput, string nazwaKlucza, string nazwaOutput)
{
	ifstream wejscie;
	ofstream wyjscie;

	vector<int> kluczInt = uzyskajKlucz(nazwaKlucza);
	int klucz_length = kluczInt.size();

	wejscie.open(nazwaInput);
	wyjscie.open(nazwaOutput);

	char aktualnyZnak;
	int aktualnyIndeks = 0;
	int aktualnyZnakAscii;

	while (wejscie >> noskipws >> aktualnyZnak)
	{
		if (isalpha(aktualnyZnak))
		{
			int wspolczynnikPrzesuniecia = aktualnyIndeks % klucz_length;
			char przesunietyZnak = ((int)toupper(aktualnyZnak) - kluczInt[wspolczynnikPrzesuniecia]);
			if (przesunietyZnak < 65)
			{
				wyjscie << char(przesunietyZnak + 26);
				aktualnyIndeks += 1;
			}
			else
			{
				wyjscie << char(przesunietyZnak);
				aktualnyIndeks += 1;
			}
		}
		else
		{
			wyjscie << aktualnyZnak;
		}
	}

	aktualnyIndeks = 0;

	wejscie.close();
	wyjscie.close();
}

void kodowanie(string nazwaInput, string nazwaKlucza, string nazwaOutput)
{
	ifstream wejscie;
	ofstream wyjscie;

	vector<int> kluczInt = uzyskajKlucz(nazwaKlucza);
	int klucz_length = kluczInt.size();

	wejscie.open(nazwaInput);
	wyjscie.open(nazwaOutput);

	char aktualnyZnak;
	int aktualnyIndeks = 0;
	int aktualnyZnakAscii;
	int nowaPozycja;

	while (wejscie >> noskipws >> aktualnyZnak)
	{
		if (isalpha(aktualnyZnak)) //isalpha sprawdza czy znak jest literką z alfabetu
		{
			aktualnyZnakAscii = (int)toupper(aktualnyZnak);
			int wspolczynnikPrzesuniecia = aktualnyIndeks % klucz_length;

			nowaPozycja = ((aktualnyZnakAscii + kluczInt[wspolczynnikPrzesuniecia]) - 65) % 26;
			char przesunietyZnak = char(nowaPozycja + 65);

			wyjscie << przesunietyZnak;
			aktualnyIndeks += 1;
		}
		else { wyjscie << aktualnyZnak; }

	}
	wejscie.close();
	wyjscie.close();
}

//void dwaPliki(string nazwaPliku1, string nazwaPliku2)
//{
//	ifstream wejscie1; //ifstream służy do odczytu danych, ofstream do zapisu danych, fstream jest uniwersalny
//	ifstream wejscie2;
//	string nowyTxtNazwa;
//
//	cout << "Wprowadz nazwe nowego pliku: " << endl;
//	cin >> nowyTxtNazwa;
//
//	ofstream nowyTxt(nowyTxtNazwa);
//
//	nowyTxt.open(nowyTxtNazwa);
//	nowyTxt << wejscie1.rdbuf() << wejscie2.rdbuf();
//	nowyTxt.close();
//}

int main(int argi, char* argj[])
{
	cout << "Do zaszyfrowania wpisz -sz -nin nazwa_wejscia.txt -nk nazwa_klucza -nout nazwa_wyjscia" << endl;
	cout << "Do odszyfrowania wpisz -od -nin nazwa_wejscia.txt -nk nazwa_klucza -nout nazwa_wyjscia" << endl;

	elementy konsola(argi, argj);

	if ((konsola.odszyfrowywanie && konsola.szyfrowanie) || (!konsola.odszyfrowywanie && !konsola.szyfrowanie))
	{
		cerr << "Zle dane!" << endl;
		return 1;
	}
	else if (!istnieje(konsola.nazwaInput) || !istnieje(konsola.nazwaKlucza))
	{
		cerr << "Zle dane!" << endl;
		return 1;
	}

	if (konsola.szyfrowanie)
	{
		
		kodowanie(konsola.nazwaInput, konsola.nazwaKlucza, konsola.nazwaOutput);
	}
	else if (konsola.odszyfrowywanie)
	{
		dekodowanieZkluczem(konsola.nazwaInput, konsola.nazwaKlucza, konsola.nazwaOutput);
	}

	return 0;
}