#pragma once

#include <string>
using namespace std;

class elementy
{
public:
	string nazwaInput = "";
	string nazwaOutput = "";
	string nazwaKlucza = "";
	string nazwaPliku1 = "";
	string nazwaPliku2 = "";
	bool odszyfrowywanie = false;
	bool odszyfrowywanieBezKlucza = false;
	bool szyfrowanie = false;

	elementy(int argi, char* argj[]);
};
