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
	bool lacz = false;
	bool odszyfrowywanie = false;
	/*bool odszyfrowywanieBezKlucza = false;*/
	bool szyfrowanie = false;

	elementy(int argi, char* argj[]);
};

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
	cout << "\n \n" << endl;
	cout << "Do zaszyfrowania wpisz -sz -nin nazwa_wejscia.txt -nk nazwa_klucza -nout nazwa_wyjscia" << endl;
	cout << "Do odszyfrowania wpisz -od -nin nazwa_wejscia.txt -nk nazwa_klucza -nout nazwa_wyjscia" << endl;
}
