#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "plik.h"
using namespace std;

bool istnieje(string sciezkaPliku)
{
	ifstream plik;
	plik.open(sciezkaPliku.c_str());

	return bool(plik);
}

vector<int> uzyskajKlucz(string nazwaKlucza)
{
	ifstream klucz;

	vector<int> kluczInt;
	vector<char> kluczChar;

	klucz.open(nazwaKlucza);
	char kluczChar_data;
	klucz >> kluczChar_data;

	while (!klucz.eof())
	{
		kluczChar.push_back(toupper(kluczChar_data));
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
		if (isalpha(aktualnyZnak))
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

void dwaPliki(string nazwaPliku1, string nazwaPliku2, string nazwaPliku3)
{
	ifstream in1(nazwaPliku1);
	ifstream in2(nazwaPliku2);
	ofstream out(nazwaPliku3);
	string line;

	while (getline(in1, line))
	{
		out << line << " ";
	}

	cout << " ";

	while (getline(in2, line))
	{
		out << line << " ";
	}
}

void napis()
{
	cout << "\n" << endl;
	cout << "                                       `+ys:                      `-:::-.`    ````````      ````       ```   ````````      `````````````   ```        `.-::::.`        ````       ``` " << endl;
	cout << "                                       `dMMy                   `/ymNNMMNNd+  -dNNNNNNmds/` `smNm/    `omNm- -dNNNNNmmhs:` oNNNNNNNNNNNNm: :mNm-     -sdNNMMMNNmh/`    +mNNms`    `yNN+" << endl;
	cout << "                                       `dMMy                  .yMMMh+::/sdd` :NMMdyyydMMMh  `hMMm:   oNMN+  /NMMdyyymMMNy`/yyyydMMMhyyys- /MMM:   `sNMMdo/::ohMMMy.   sMMMMMh`   `dMMo" << endl;
	cout << "  `-oyhhhs/.    :+/`.+yhhs:`     :shhho:dMMy    `:ohhhho:`   `hMMN+`     `.  :NMM+   `hMMM-  .hMMm- /NMNo   /NMMo   .hMMN-     oMMN-      /MMM:   oMMMo`     `oNMMs   sMMhdMMy.  `dMMo " << endl;
	cout << " .hNMNddmMMm:  `hMNhmmdmMMNy   .yNMNmdNNMMMy   -dNMmddmMNd-  :NMMy           :NMM+```:dMMm`   .dMMh/mMM+`   /NMMo   `hMMN-     oMMN-      /MMM:  -mMMd`       .dMMN`  sMMy-mMMh. `dMMo" << endl;
	cout << "`hMMh-``.oMMm. `hMMN+.`.sMMN-  sMMN/``.sNMMy  .dMMy.``.yMMd  oMMM+           :NMMmdddNMmy-     .dMMNMNo     /NMMdoosdMMNs      oMMN-      /MMM:  :NMMs        `yMMM.  sMMy -dMMh.`dMMo " << endl;
	cout << "-NMMhssssyMMM: `hMMh    :MMM: `mMMh    `dMMy  /MMMhsssshMMM. oMMMo           :NMMmhdNMMy.       .dMMMo`     /NMMNNNmmhs-       oMMN-      /MMM:  :NMMy        `hMMM.  sMMy  -mMMh-hMMo" << endl;
	cout << ":MMMdhhhhhhhy. `hMMh    :MMM: `mMMh    `dMMy  +MMMdhhhhhhhs` :NMMd`          :NMM+  -mMMd-       oMMM.      /NMMs...`          oMMN-      /MMM:  .mMMm`       -mMMh`  sMMy   -dMMhdMMo" << endl;
	cout << ".mMMy.`   ```  `hMMh    :MMM:  yMMN:` `+NMMy  :NMMs`    ```  `yMMMy-`   `.:  :NMM+   :mMMd`      oMMM.      /NMMo              oMMN-      /MMM:   +MMMy-`   `:dMMm:   sMMy    -dMMMMMo" << endl;
	cout << " :mMMmhhhhdms  `hMMh    :MMM:  -mMMNhhmNNMMy   +NMMmhhhhdm+   `oNMMNdhhhmNm. :NMM+    +MMMy`     oMMM.      /NMMo              oMMN-      /MMM:    +mMMNdhhhmMMNh-    sMMy     -mMMMMo" << endl;
	cout << "  ./ydmmmmdy:   /ss/    .sso.   `ohmmds:-ss:    .+ydmmmmhy-     ./sdmmmdhs/  .oss-     +sso.     -sso`      .oss-              -sso`      .sso.     `/shmmmmdy+-      :ss:      .+sso." << endl;
	cout << "\n \n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Aby zaszyfrowaæ wpisz: -sz -nin nazwa_wejœcia.txt -nk nazwa_klucza -nout nazwa_wyjœcia" << endl;
	cout << "Aby odszyfrowaæ z kluczem wpisz: -od -nin nazwa_wejœcia.txt -nk nazwa_klucza -nout nazwa_wyjœcia" << endl;
	cout << "Aby po³¹czyæ dwa pliki tekstowe wpisz: -m nazwa_wejœcia1.txt nazwa_wejœcia2.txt nazwa_wyjœcia.txt" << endl;
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}