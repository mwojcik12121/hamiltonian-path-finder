/** @file */
#ifndef widok
#define widok

/** Funkcja wyœwietla pomoc.*/
void wyswietlPomoc();

/** Funkcja wyœwietla komunikat o niepoprawnie wprowadzonych parametrach.*/
void nieprawidloweParametry();

/** Funkcja wyœwietla komunikat o pustym pliku wejœciowym.*/
void plikPusty();

/** Funkcja wyœwietla komunikat o braku mo¿liwoœci wczytania pliku wejœciowego.*/
void bladWczytaniaPlikuWejsciowego();

/** Funkcja wyœwietla komunikat o iloœci znalezionych œcie¿ek Hamiltona i minimalnych œcie¿ek Hamiltona.
@param ile_sciezek iloœæ œcie¿ek przekazywana do komunikatu
@param ile_sciezek_minimalnych iloœæ œcie¿ek minimalnych przekazywana do komunikatu
*/
void znalezionoSciezke(int ile_sciezek, int ile_sciezek_minimalnych);

/** Funkcja wyœwietla komunikat o braku œcie¿ek Hamiltona w zaimportowanym grafie.*/
void nieZnalezionoSciezki();

/** Funkcja wyœwietla komunikat o wykonaniu eksportu minimalnej œcie¿ki Hamiltona oraz wyœwietla komunikat o zapisaniu tylko jednej minimalnej œcie¿ki, jeœli by³o ich wiêcej ni¿ jedna.
@param ile_minimalnych wartoœæ przedstawiaj¹ca iloœæ minimalnych œcie¿ek Hamiltona w pliku*/
void pomyslnyEksport(int ile_minimalnych);

/** Funkcja wyœwietla komunikat o niepoprawnym wczytaniu pliku wyjœciowego.*/
void bladWczytaniaPlikuWyjsciowego();

#endif