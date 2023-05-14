#include <fstream>
#include <list>
#include <vector>

#include "funkcje.h"
#include "widok.h"

int main(int argc, char* argv[])
{
	bool czyJest_i = false;
	bool czyJest_o = false;

	if (argv[1] == "-h" || argv[1] == NULL)
	{
		wyswietlPomoc();
	}
	if (argc != 5)
	{
		nieprawidloweParametry();
	}
	for (int i = 1; i < argc; i++)
	{
		std::string przelacznik = argv[i];
		if (przelacznik == "-i") czyJest_i = true;
		if (przelacznik == "-o") czyJest_o = true;
	}

	if (czyJest_i == false || czyJest_o == false) nieprawidloweParametry();
	
	if (argv[2] == "-i" || argv[2] == "-o" || argv[4] == "-i" || argv[4] == "-o")
	{
		nieprawidloweParametry();
	}
	for (int i = 1; i <= argc; i++)
	{
		for (int j = 1; j <= argc; j++)
		{
			if (argv[i] == argv[j] && i != j) nieprawidloweParametry();
		}
	}
	
	std::ifstream wejscie_graf;
	
	for (int i = 1; i < argc; i++)
	{
		std::string przelacznik = argv[i];
		if (przelacznik == "-i") wejscie_graf.open(argv[i + 1]);
	}

	//wczytywanie danych z pliku do wektorów
	std::vector<int> wierzcholek_poczatkowy;
	std::vector<int> wierzcholek_koncowy;
	std::vector<int> waga;
	std::vector<std::vector<int>> waga_wektora;
	int max = 0;									//najwiêksza wartoœæ wierzcho³ka

	if (wejscie_graf.is_open())
	{
		if (wejscie_graf.peek() == std::ifstream::traits_type::eof())
		{
			plikPusty();
		}
		importujDaneZPliku(wejscie_graf, wierzcholek_poczatkowy, wierzcholek_koncowy, waga, waga_wektora, max);
	}
	else
	{
		bladWczytaniaPlikuWejsciowego();
	}

	wejscie_graf.close();

	//inicjalizacja list scie¿ek
	std::list<int> najkrotsza_sciezka;		//minimalna œcie¿ka Hamiltona
	int suma_wag = 2147483647;	//najwiêksza liczba mo¿liwa do przechowania w zmiennej typu int
	int ile_sciezek = 0;
	int ile_sciezek_minimalnych = 0;

	if (czyIstniejeSciezka(waga_wektora, max, najkrotsza_sciezka, suma_wag, ile_sciezek, ile_sciezek_minimalnych) == true)
	{
		znalezionoSciezke(ile_sciezek, ile_sciezek_minimalnych);
	}
	else 
	{
		nieZnalezionoSciezki();
	}

	//eksport œcie¿ki Hamiltona do pliku wyjœciowego
	std::ofstream wyjscie_sciezka;
	std::string nazwa_pliku;
	for (int i = 1; i < argc; i++)
	{
		std::string przelacznik = argv[i];
		if (przelacznik == "-o")
		{
			wyjscie_sciezka.open(argv[i + 1]);
			std::string nazwa_pliku = argv[i + 1];
		}
	}

	if (wyjscie_sciezka.is_open())
	{
		eksportujSciezkeDoPliku(wyjscie_sciezka, najkrotsza_sciezka, ile_sciezek_minimalnych);
		pomyslnyEksport(ile_sciezek_minimalnych);
	}
	else
	{
		bladWczytaniaPlikuWyjsciowego();
	}

	wyjscie_sciezka.close();
}