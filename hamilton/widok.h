/** @file */
#ifndef widok
#define widok

/** Funkcja wy�wietla pomoc.*/
void wyswietlPomoc();

/** Funkcja wy�wietla komunikat o niepoprawnie wprowadzonych parametrach.*/
void nieprawidloweParametry();

/** Funkcja wy�wietla komunikat o pustym pliku wej�ciowym.*/
void plikPusty();

/** Funkcja wy�wietla komunikat o braku mo�liwo�ci wczytania pliku wej�ciowego.*/
void bladWczytaniaPlikuWejsciowego();

/** Funkcja wy�wietla komunikat o ilo�ci znalezionych �cie�ek Hamiltona i minimalnych �cie�ek Hamiltona.
@param ile_sciezek ilo�� �cie�ek przekazywana do komunikatu
@param ile_sciezek_minimalnych ilo�� �cie�ek minimalnych przekazywana do komunikatu
*/
void znalezionoSciezke(int ile_sciezek, int ile_sciezek_minimalnych);

/** Funkcja wy�wietla komunikat o braku �cie�ek Hamiltona w zaimportowanym grafie.*/
void nieZnalezionoSciezki();

/** Funkcja wy�wietla komunikat o wykonaniu eksportu minimalnej �cie�ki Hamiltona oraz wy�wietla komunikat o zapisaniu tylko jednej minimalnej �cie�ki, je�li by�o ich wi�cej ni� jedna.
@param ile_minimalnych warto�� przedstawiaj�ca ilo�� minimalnych �cie�ek Hamiltona w pliku*/
void pomyslnyEksport(int ile_minimalnych);

/** Funkcja wy�wietla komunikat o niepoprawnym wczytaniu pliku wyj�ciowego.*/
void bladWczytaniaPlikuWyjsciowego();

#endif