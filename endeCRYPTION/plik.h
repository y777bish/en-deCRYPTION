#pragma once

#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool istnieje(string sciezkaPliku);
vector<int> uzyskajKlucz(string nazwaKlucza);
void dekodowanieZkluczem(string nazwaInput, string nazwaKlucza, string nazwaOutput);
void kodowanie(string nazwaInput, string nazwaKlucza, string nazwaOutput);
void dwaPliki(string nazwaPliku1, string nazwaPliku2, string nazwaPliku3);
void napis();

class elementy
{
public:
	string nazwaInput = "";
	string nazwaOutput = "";
	string nazwaKlucza = "";
	string nazwaPliku1 = "";
	string nazwaPliku2 = "";
	string nazwaPliku3 = "";
	bool lacz = false;
	bool odszyfrowywanie = false;
	bool szyfrowanie = false;

	elementy(int argi, char* argj[]);
};


