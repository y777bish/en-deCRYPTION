#include "plik.h"
#include <iostream>
using namespace std;

elementy::elementy(int argi, char* argj[])
{
	for (int i{}; i < argi; i++)
	{
		if (string(argj[i]) == "-od")
		{
			odszyfrowywanie = true;
		}
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
		else if (string(argj[i]) == "-m")
		{
			if (i + 1 < argi)
			{
				lacz = true;
				nazwaPliku1 = argj[i + 1];
				nazwaPliku2 = argj[i + 2];
				nazwaPliku3 = argj[i + 3];
			}
		}
	}

}

int main(int argi, char* argj[])
{
	setlocale(LC_CTYPE, "Polish");
	napis();
	
	elementy konsola(argi, argj);

	if	((konsola.odszyfrowywanie && konsola.szyfrowanie && konsola.lacz) || (!konsola.odszyfrowywanie && !konsola.szyfrowanie && !konsola.lacz))
	{
		cerr << "Zle dane!" << endl;
		return 1;
	}
	else if (!istnieje(konsola.nazwaInput) || !istnieje(konsola.nazwaKlucza))
	{
		cerr << "Zle dane!" << endl;
		return 1;
	}
	else { cout << "Wykonano!"; }

	if (konsola.lacz)
	{
		dwaPliki(konsola.nazwaPliku1, konsola.nazwaPliku2, konsola.nazwaPliku3);
	}
	else if (konsola.szyfrowanie)
	{

		kodowanie(konsola.nazwaInput, konsola.nazwaKlucza, konsola.nazwaOutput);
	}
	else if (konsola.odszyfrowywanie)
	{
		dekodowanieZkluczem(konsola.nazwaInput, konsola.nazwaKlucza, konsola.nazwaOutput);
	}

	return 0;
}