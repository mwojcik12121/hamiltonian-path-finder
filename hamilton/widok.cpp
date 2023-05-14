#include <iostream>

#include "funkcje.h"

void wyswietlPomoc()
{
	std::cout << "\nPomoc:\nBy prawidlowo uruchomic program, nalezy podac dwa parametry w postaci plikow o rozszerzeniu .txt poprzedzone odpowiednimi przelacznikami (-i dla pliku wejsciowego, -o dla pliku wyjsciowego) oraz rozdzielone pojedynczymi spacjami.\n\nPrzyklady:\nhamilton.exe -i graf.txt -o sciezka.txt\nhamilton.exe -o sciezka.txt -i graf.txt" << std::endl;
	exit(EXIT_FAILURE);
}

void nieprawidloweParametry()
{
	std::cout << "\nPodano nieprawidlowe parametry." << std::endl;
	wyswietlPomoc();
}

void plikPusty()
{
	std::cout << "Podany plik wejsciowy jest pusty. Program nie moze zostac wykonany";
	exit(EXIT_FAILURE);
}

void bladWczytaniaPlikuWejsciowego()
{
	std::cout << "Nie udalo sie otworzyc pliku z danymi wejsciowymi.";
	exit(EXIT_FAILURE);
}

void znalezionoSciezke(int ile_sciezek, int ile_sciezek_minimalnych)
{
	std::cout << "\nIlosc znalezionych sciezek Hamiltona: " << ile_sciezek << std::endl;
	std::cout << "\nIlosc minimalnych sciezek Hamiltona: " << ile_sciezek_minimalnych << std::endl;
}

void nieZnalezionoSciezki()
{
	std::cout << "\nGraf nie zawiera zadnych sciezek Hamiltona.";
}

void pomyslnyEksport(int ile_minimalnych)
{
	std::cout << "\nPomyslnie wyeksportowano minimalna sciezke do pliku wyjsciowego." << std::endl;
	if (ile_minimalnych > 1) std::cout << "\nUWAGA! - wystapilo wiecej niz jedna sciezka. W pliku znajduje sie tylko ta sciezka, ktora wystapila jako OSTATNIA przy permutacji mozliwych sciezek." << std::endl;
}

void bladWczytaniaPlikuWyjsciowego()
{
	std::cout << "Nie udalo sie otworzyc pliku wyjsciowego.";
	exit(EXIT_FAILURE);
}