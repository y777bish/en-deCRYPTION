#pragma once

#include <string>
#include <vector>
#include <fstream>
using namespace std;

/// Funkcja "istnieje"
/// 
/// Sprawdza czy sciezka pliku zostala podana poprawnie
bool istnieje(string sciezkaPliku);

/// Kontener na dane "uzyskajKlucz"
/// 
/// Dynamiczna tablica sluzaca do uzyskania klucza z pliku o rozszerzeniu .txt
vector<int> uzyskajKlucz(string nazwaKlucza);

/// Funkcja "dekodowanieZkluczem"
/// 
/// Ma za zadanie dekodowac plik szyfrem Vigenere'a, z uzyciem klucza
void dekodowanieZkluczem(string nazwaInput, string nazwaKlucza, string nazwaOutput);

/// Funkcja "kodowanie"
///
/// Ma za zadanie kodowac plik szyfrem Vigenere'a, z uzyciem klucza
void kodowanie(string nazwaInput, string nazwaKlucza, string nazwaOutput);

/// Funkcja "dwaPliki"
/// 
/// Ma za zadanie laczyc zawartosc dwoch plikow o rozszerzniu .txt w osobnym pliku o rozszerzeniu .txt
void dwaPliki(string nazwaPliku1, string nazwaPliku2, string nazwaPliku3);

/// Funkcja "napis"
/// 
/// Ma za zadanie wyswietlenie napisu "endeCRYPTION" oraz podstawowej instrukcji uzytkowania
void napis();

/// Klasa "elementy"
/// 
/// Przechowuje zmienne ktorych wartosc jest zmieniana w zaleznosci od tego jaka funkcjonalnosc wybierze uzytkownik
class elementy
{
public:
	/// Zmienna przechowujaca nazwe pliku wejsciowego
	string nazwaInput = "";
	/// Zmienna przechowujaca nazwe pliku wyjsciowego
	string nazwaOutput = "";
	/// Zmienna przechowujaca nazwe pliku z kluczem
	string nazwaKlucza = "";
	/// Zmienna przechowujaca nazwe pierwszego pliku do operacji laczenia
	string nazwaPliku1 = "";
	/// Zmienna przechowujaca nazwe drugiego pliku do operacji laczenia
	string nazwaPliku2 = "";
	/// Zmienna przechowujaca nazwe trzeciego pliku (pliku wyjscia) do operacji laczenia
	string nazwaPliku3 = "";
	/// Zmienna przechowujaca stan operacji laczenia plikow (wykonywac/ nie wykonywac)
	bool lacz = false;
	/// Zmienna przechowujaca stan operacji odszyfrowywania (odszyfrowywac/ nie odszyfrowywac)
	bool odszyfrowywanie = false;
	/// Zmienna przechowujaca stan operacji szyfrowania (szyfrowac/ nie szyfrowac)
	bool szyfrowanie = false;

	/// Przekazywanie zmiennych klasy "elementy" z parametrami wpisywanymi po uruchomieniu programu przez uzytkownika
	elementy(int argi, char* argj[]);
};


