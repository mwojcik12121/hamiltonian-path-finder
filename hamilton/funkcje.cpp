#include <algorithm>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include "widok.h"

int najwyzszaWartoscWierzcholka(int wierz_pocz, int wierz_konc, int& max)
{
	//Uwaga! - funkcja zwraca najwy�szy warto�ciowo wierzcho�ek, nie ilo�� wierzcho�k�w!
	if (wierz_pocz > max)
	{
		return wierz_pocz;
	}
	if (wierz_konc > max)
	{
		return wierz_konc;
	}
	return max;
}

void wstawDoWektoraWektorow(std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, std::vector<std::vector<int>>& waga, int max)
{
	waga.resize(max + 1, std::vector<int>(max + 1));	//wyznaczanie rozmiaru ca�o�ci
	for (int i = 0; i < waga_wektor.size(); i++)
	{
		waga[wierzcholek_poczatkowy[i]][wierzcholek_koncowy[i]] = waga_wektor[i];
	}
}
void wstawDoWektorow(std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, int wierz_pocz, int wierz_konc, int waga)
{
	wierzcholek_poczatkowy.push_back(wierz_pocz);
	wierzcholek_koncowy.push_back(wierz_konc);
	waga_wektor.push_back(waga);
}

void importujDaneZPliku(std::ifstream& wejscie, std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, std::vector<std::vector<int>>& waga_wektora, int& max)		//funkcja s�u��ca do importu danych z pliku
{
	int wierz_pocz;
	int wierz_konc;
	int waga;
	std::string omin_niepotrzebne_znaki;		//zmienna s�u��ca do omini�cia znak�w niewykorzystywanych przez program

	while (!wejscie.eof())
	{
		//wczytywanie danych do zmiennych wierzcho�kowych oraz zmiennej wagi
		wejscie >> wierz_pocz;
		getline(wejscie, omin_niepotrzebne_znaki, '>');		//ka�da funkcja getline pozbywa si� "dodatkowych znak�w" z pliku tekstowego 
		wejscie >> wierz_konc;								//(np. spacje, entery, znaki nienale��ce si� do element�w danych)
		getline(wejscie, omin_niepotrzebne_znaki, '(');		
		wejscie >> waga;
		getline(wejscie, omin_niepotrzebne_znaki, ',');
		
		//wyznaczanie wierzcho�ka najwy�szej warto�ci
		max = najwyzszaWartoscWierzcholka(wierz_pocz, wierz_konc, max);
		//wstawianie danych tymczasowo do oddzielnych wektor�w
		wstawDoWektorow(wierzcholek_poczatkowy, wierzcholek_koncowy, waga_wektor, wierz_pocz, wierz_konc, waga);
	}
	//w�a�ciwe umieszczenie danych w wektorze wektor�w
	wstawDoWektoraWektorow(wierzcholek_poczatkowy, wierzcholek_koncowy, waga_wektor, waga_wektora, max);
}

int sumujWagi(int suma, int waga)
{
	return suma + waga;
}

bool czyMinimalna(int suma, int minimalna)
{
	return suma <= minimalna;
}

void zapiszMinimalnaNaLiscie(std::vector<int>& sciezka, std::list<int>& minimalnaSciezka, int suma, int& suma_wag_minimalnej, int max, int& ile_sciezek)
{
	minimalnaSciezka.clear();
	if (suma == suma_wag_minimalnej) ile_sciezek++;
	if (suma < suma_wag_minimalnej) ile_sciezek = 1;
	for (int i = 0; i < max + 1; i++)
	{
		minimalnaSciezka.push_back(sciezka[i]);
	}
	suma_wag_minimalnej = suma;
	
}

//wyznaczanie �cie�ki Hamiltonaza pomoc� permutacji
bool czyIstniejeSciezka(std::vector<std::vector<int>>& waga, int max, std::list<int>& minimalnaSciezka, int& suma_wag_minimalnej, int& ile_sciezek, int& ile_sciezek_minimalnych)
{
	std::vector<int> sciezka;	//wektor zawieraj�cy aktualnie badan� �cie�k�
	for (int i = 0; i < max + 1; i++) sciezka.push_back(i);		//wyznaczanie pierwszej �cie�ki (0, 1,...,n-1)
	do
	{
		bool czySciezka = true;
		int suma = 0;
		for (int i = 0; i < max; i++)
		{
			if (waga[sciezka[i]][sciezka[i + 1]] == 0)	//aktywuje si�, gdy kolejny etap scie�ki jest niemo�liwy do wykonania (wektor r�wny 0 - brak po��czenia)
			{
				czySciezka = false;
				break;
			}
			suma = sumujWagi(suma, waga[sciezka[i]][sciezka[i + 1]]);
		}
		if (czySciezka == true)	//aktywuje si� tylko wtedy, gdy uda�o si� znale�� �cie�k� Hamiltona
		{
			ile_sciezek++;
			if (czyMinimalna(suma, suma_wag_minimalnej) == true) zapiszMinimalnaNaLiscie(sciezka, minimalnaSciezka, suma, suma_wag_minimalnej, max, ile_sciezek_minimalnych);
		}
	} while (std::next_permutation(sciezka.begin(), sciezka.end()));
	if (ile_sciezek > 0) return true;
	else return false;
}

void eksportujSciezkeDoPliku(std::ofstream& wyjscie, std::list<int>& sciezka, int ile_minimalnych)
{
	for (const auto a : sciezka)
	{
		wyjscie << a << '\t';
	}
}