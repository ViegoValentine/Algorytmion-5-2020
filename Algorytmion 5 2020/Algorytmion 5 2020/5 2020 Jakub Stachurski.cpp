/*Napisz program, który dla zadanych dwóch liczb zmiennoprzecinkowych zwróci iloczyn tych liczb.
UWAGA: program (oczywiœcie) nie mo¿e korzystaæ z mno¿enia, nie mo¿e równie¿ u¿ywaæ
innych (poza dodawaniem) funkcji matematycznych (np. mno¿enie, dzielenie, potêga, pierwiastek, czêœæ ca³kowita, zaokr¹glenie, operacja modulo, itd.). */

#include <iostream>
#include <string>

using namespace std;

void czyUjemne(long double A, long double B, long int ileUjemnych, string liczbaA, string liczbaB) {
	//usuniêcie i zapamietanie ile jest minusów.
	if (A < 0) {
		liczbaA.erase(0, 1);
		ileUjemnych = ileUjemnych + 1;
	}
	if (B < 0) {
		liczbaB.erase(0, 1);
		ileUjemnych = ileUjemnych + 1;
	}
}

void sumujemyA(long int* dlugoscA, long int* kontrolneA, long int* licznikA, string* liczbaA, string* liczbaK1, long double* sumaA, long int* pomocneA, long double* malaA) {
	//pomocniczeA-ilosc znaków przed przecinkiem.
	//kontrolneA-kiedy wystapila kropka.
	//licznikA-ilosc znaków po przecinku.
	string redline = *liczbaA;
	for (int i = 1; i < *dlugoscA; i++) {
		if (*kontrolneA == 0) {
			*pomocneA = *pomocneA + 1;
		}
		if (redline[i] == '.') {
			*kontrolneA = 1;
		}
		else if (*kontrolneA == 1) {
			*licznikA = *licznikA + 1;
		}
	}
	//wyliczanie potegi 10 potrzebnej do zmiany na ca³kowit¹ liczbê (3.1->31 daje 10).
	for (int i = 1; i < *licznikA + 1; i++) {
		*liczbaK1 = *liczbaK1 + "0";
	}
	//zamiana stringa z potêg¹ 10 na inta i wyliczenie mno¿enia liczby A * potrzebna potêga 10.
	int a = stoi(*liczbaK1);
	for (int i = 1; i < a + 1; i++) {
		*sumaA = *sumaA + *malaA;
	}
}

//to samo co w liczbie A tylko ¿e dla B.
void sumujemyB(long int* dlugoscB, long int* kontrolneB, long int* licznikB, string* liczbaB, string* liczbaK2, long double* sumaB, long int* pomocneB, long double* malaB) {
	string howl = *liczbaB;
	for (int i = 1; i < *dlugoscB; i++) {
		if (*kontrolneB == 0) {
			*pomocneB = *pomocneB + 1;
		}
		if (howl[i] == '.') {
			*kontrolneB = 1;
		}
		else if (*kontrolneB == 1) {
			*licznikB = *licznikB + 1;
		}
	}
	for (int i = 1; i < *licznikB + 1; i++) {
		*liczbaK2 = *liczbaK2 + "0";
	}
	int b = stoi(*liczbaK2);
	for (int i = 1; i < b + 1; i++) {
		*sumaB = *sumaB + *malaB;
	}
}

void zaokr¹glanieSuma(long double sumaA, long double sumaB, long long int* zmiennaA1, long long int* zmiennaB1, long long int* sumaL1, long int* licznikA, long int* licznikB) {
	//z racji ¿e double nie umie w liczby i z 12.345 po dodaniu jej 1000 razy daje 12344.9999 zaokr¹glamy poprzez dodawanie 1 do liczby któr¹ daliœmy na pocz¹tku.
	string decimator = to_string(* zmiennaA1);
	if (decimator[* licznikA + 1]=='9') {
		while (*zmiennaA1 < sumaA) {
			*zmiennaA1 = *zmiennaA1 + 1;
		}
	}
	if (decimator[*licznikB + 1] == '9') {
		while (*zmiennaB1 < sumaB) {
			*zmiennaB1 = *zmiennaB1 + 1;
		}
	}
	//wynik mno¿enia liczb ca³kowitych np 2.1*3.1 -> 21*31.
	int fgh = 0;
	do {
		*sumaL1 = *sumaL1 + *zmiennaB1;
		fgh++;
	} while (fgh < *zmiennaA1);
}

void wypisanie(long int* licznikA, long int* licznikB, long double* malaA, long double* malaB, long int* empress, long int* chromaticAberration, long int* hyperBeast, string* sumaL2) {
	//tutaj wypisuje "pomno¿on¹" liczbê
	int g = 0, z = 1, x, kropka = 0;
	long double suma = 0;
	string sumaL22 = *sumaL2;
	//dla dwóch liczb bez przecinka
	if (*licznikA == 0 && *licznikB == 0) {
		for (int i = 0; i < *malaA; i++) {
			suma = suma + *malaB;
		}
		cout << suma << endl;
	}
	//dla jednej liczby z przecinkiem: A lub B ta która nie jest x.x idzie do pêtli, a liczba x.x jest dodawana
	else if (*licznikA != 0 && *licznikB == 0) {
		for (int i = 0; i < *malaB; i++) {
			suma = suma + *malaA;
		}
		cout << suma << endl;
	}
	else if (*licznikA == 0 && *licznikB != 0) {
		for (int i = 0; i < *malaA; i++) {
			suma = suma + *malaB;
		}
		cout << suma << endl;
	}
	//dla dwóch z przecinkiem
	else if (*licznikA != 0 && *licznikB != 0) {
		x = *empress;
		//wypisywanie 0 gdy warunek ró¿nicy iloœci znaków od miejsc przed i po przecinku jest spe³niony, stawia kropke po sprawdzeniu warunku,
		while (x < *chromaticAberration + 1 || x < *hyperBeast + 1) {
			cout << 0;
			if (kropka != 1) {
				cout << ".";
				kropka = 1;
			}
			x++;
			z++;
		}
		//sprawdza czy mozna postawic liczbe wieksza od 0 przed przecinkiem i je wypisuje
		while ((z < *chromaticAberration && z < *hyperBeast + 1) || (*hyperBeast > *chromaticAberration && z < *hyperBeast)) {
			cout << sumaL22[g];
			z++;
			g++;
		}
		//stawia przecinek i blokuje mozliwosc postawienia go pozniej
		if (kropka == 0) {
			cout << ".";
		}
		//stawia reszte znaków po przecinku i wczesniej postawionych zerach (chyba)
		do {
			cout << sumaL22[g];
			g++;
		} while (g < *empress);
	}
}

int main() {
	//pobranie wartoœci od u¿ytkownika i zrzutowanie je na stringa ni¿ej by zobaczyæ d³ugoœæ liczby.
	string A1{}, B1{};
	cout << "podaj A: ";
	cin >> A1;
	cout << "podaj B: ";
	cin >> B1;

	//inicjalizacja sumy kontrolnej dla liczby ujemnej, konwersjê double>string, w³¹czenie liczb potêgi 10.
	long int ileUjemnych = 0;
	string liczbaA = A1, liczbaK1 = "1", liczbaB = B1, liczbaK2 = "1";
	long double A = stod(A1), B = stod(B1);

	czyUjemne(A, B, ileUjemnych, liczbaA, liczbaB);

	//inicjalizacja kolejnych zmiennych takich jak dlugosc czy liczby kontrolne.
	long double sumaA = 0, sumaB = 0, malaA = A, malaB = B;
	long int kontrolneA = 0, licznikA = 0, pomocneA = 0, kontrolneB = 0, licznikB = 0, pomocneB = 0, dlugoscA = A1.length(), dlugoscB = B1.length();
	//wskaŸniki na A (prosze nie zgub siê).
	long int* dlugoscA1 = &dlugoscA, * kontrolneA1 = &kontrolneA, * licznikA1 = &licznikA, * pomocneA1 = &pomocneA;
	long double* sumaA1 = &sumaA, * malaA1 = &malaA;
	string* liczbaA1 = &liczbaA, * liczbaK11 = &liczbaK1;
	//wskaŸniki na B (tego te¿ nie zgub).
	long int* dlugoscB1 = &dlugoscB, * kontrolneB1 = &kontrolneB, * licznikB1 = &licznikB, * pomocneB1 = &pomocneB;
	long double* sumaB1 = &sumaB, * malaB1 = &malaB;
	string* liczbaB1 = &liczbaB, * liczbaK21 = &liczbaK2;

	sumujemyA(dlugoscA1, kontrolneA1, licznikA1, liczbaA1, liczbaK11, sumaA1, pomocneA1, malaA1);
	sumujemyB(dlugoscB1, kontrolneB1, licznikB1, liczbaB1, liczbaK21, sumaB1, pomocneB1, malaB1);

	//podwójna konwersja double>string>int ¿eby wyeliminowæ zaokr¹glanie które psu³o program (XD?) PS. nie dzia³a.
	string xA = to_string(sumaA), xB = to_string(sumaB);
	long long int zmiennaA1 = stol(xA), zmiennaB1 = stol(xB);
	long long int sumaL1 = 0;

	//wska¿niki do funkcji zaokraglanie.
	long long int* zmiennaA11 = &zmiennaA1, * zmiennaB11 = &zmiennaB1, * sumaL11 = &sumaL1;

	zaokr¹glanieSuma(A, B, zmiennaA11, zmiennaB11, sumaL11, licznikA1, licznikB1);

	//konwersja int>string, utworzone dodatkowe zmienne pomocnicze u¿ywane póŸniej g-ilosc 0, z-znaki przed ".", x-ile zer zostalo, kropka - blokuje jej dublowanie.
	string sumaL2 = to_string(sumaL1);

	//reszta zmiennych pomocniczych u¿ytych na pocz¹tku czyli ilosc znakow, ilosc znakow przed kropka (razem), ilosc znakow po kropce (razem).
	long int empress = sumaL2.length(), chromaticAberration = (licznikA + licznikB), hyperBeast(pomocneA + pomocneB);
	long int* empress1 = &empress, * chromaticAberration1 = &chromaticAberration, * hyperBeast1 = &hyperBeast;
	string* sumaL22 = &sumaL2;

	//wypisanie - jesli liczba jest ujemna
	if (ileUjemnych == 1) {
		cout << "-";
	}

	wypisanie(licznikA1, licznikB1, malaA1, malaB1, empress1, chromaticAberration1, hyperBeast1, sumaL22);
	return 0;
}