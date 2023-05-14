/** @file */
#ifndef funkcje
#define funkcje

#include <list>
#include <vector>

/** Funkcja wyznacza najwiêksz¹ wartoœæ wierzcho³ka we wczytywanym grafie.
@param  wierzcholek_poczatkowy wartoœæ obecnie sczytanego wierzcho³ka pocz¹tkowego z pliku
@param  wierzcholek_koncowy wartoœæ obecnie sczytanego wierzcho³ka koñcowego z pliku
@return najwiêksza wartoœæ wierzcho³ka zawartego w grafie
*/
int najwyzszaWartoscWierzcholka(int wierzcholek_poczatkowy, int wierzcholek_koncowy, int& max);

/** Funkcja tymczasowo wstawia aktualnie wczytane wartoœci ze strumienia wejœciowego do wektorów.
@param  wierzcholek_poczatkowy wektor tymczasowo przechowuj¹cy wierzcho³ki pocz¹tkowe pobrane z pliku
@param  wierzcholek_koncowy wektor tymczasowo przechowuj¹cy wierzcho³ki koñcowe pobrane z pliku
@param  waga_wektor wektor tymczasowo przechowuj¹cy wagi wektorów pobrane z pliku
@param  wierz_pocz liczba przedstawiaj¹ca numer obecnie sczytanego wierzcho³ka pocz¹tkowego z pliku
@param  wierz_konc liczba przedstawiaj¹ca numer obecnie sczytanego wierzcho³ka koñcowego z pliku
@param  waga wartoœæ obecnie sczytanej wagi wektora z pliku
*/
void wstawDoWektorow(std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, int wierz_pocz, int wierz_konc, int waga);

/** Funkcja ustala rozmiar w³aœciwej struktury i wstawia elementy grafu do odpowiednich miejsc.
@param  wierzcholek_poczatkowy wektor tymczasowo przechowuj¹cy wierzcho³ki pocz¹tkowe pobrane z pliku
@param  wierzcholek_koncowy wektor tymczasowo przechowuj¹cy wierzcho³ki koñcowe pobrane z pliku
@param  waga_wektor wektor tymczasowo przechowuj¹cy wagi wektorów pobrane z pliku
@param  waga wektor wektorów przechowuj¹cy wagi wektorów z grafu w indeksack kolejno przedstawiaj¹cych wierzcho³ek pocz¹tkowy i wierzcho³ek koñcowy grafu z pliku
@param  max wartoœæ wierzcho³ka o najwiêkszym numerze wystêpuj¹cego w grafie
*/
void wstawDoWektoraWektorow(std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, std::vector<std::vector<int>>& waga, int max);

/** Funkcja importuje elementy grafu (wierzcho³ki i wektory) zawarte w pliku. 
@param  wejscie strumieñ wejœciowy pliku z grafem
@param  wierzcho³ek_pocz¹tkowy wektor tymczasowo przechowuj¹cy wierzcho³ki koñcowe pobrane z pliku
@param  wierzcholek_koncowy wektor tymczasowo przechowuj¹cy wierzcho³ki koñcowe pobrane z pliku
@param  waga_wektor wektor tymczasowo przechowuj¹cy wagi wektorów pobrane z pliku
@param  waga_wektora wektor wektorów przechowuj¹cy wagi wektorów z grafu w indeksack kolejno przedstawiaj¹cych wierzcho³ek pocz¹tkowy i wierzcho³ek koñcowy grafu z pliku
@param  max wartoœæ wierzcho³ka o najwiêkszym numerze wystêpuj¹cego w grafie
*/
void importujDaneZPliku(std::ifstream& wejscie, std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, std::vector<std::vector<int>>& waga_wektora, int& max);

/** Funkcja sumuje wagi wektora do sumy ogólnej aktualnie sprawdzanej œcie¿ki.
@param  suma dotychczasowa suma wag dla aktualnej œcie¿ki
@param  waga wartoœæ aktualnie dodawanej wagi
@return ³¹czna suma wag dla aktualnie sprawdzanej œcie¿ki
*/
int sumujWagi(int suma, int waga);

/** Funkcja importuje elementy grafu (wierzcho³ki i wektory) zawarte w pliku.
@param  suma wartoœæ sumy wektorów dla aktualnej œcie¿ki
@param  minimalna dotychczasowa najmniejsza suma wektorów
@return zwraca informacjê, czy suma wag dla aktualnej œcie¿ki jest mniejsza ni¿ dotychczasowe minimum
*/
bool czyMinimalna(int suma, int minimalna);

/** Funkcja zapisuje dotychczasow¹ minimaln¹ œcie¿kê do listy.
@param  sciezka wektor przechowuj¹cy minimaln¹ œcie¿kê Hamiltona
@param  minimalnaSciezka lista, na której zostanie zapisana minimalna œcie¿ka Hamiltona
@param  suma wartoœæ sumy wag dla aktualnej minimalnej œcie¿ki 
@param  suma_wag_minimalnej przechowuje sumê wag dla dotychczasowej minimalnej œcie¿ki
@param  max iloœæ wierzcho³ków w grafie
*/
void zapiszMinimalnaNaLiscie(std::vector<int>& sciezka, std::list<int>& minimalnaSciezka, int suma, int& suma_wag_minimalnej, int max, int& ile_sciezek);

/** Funkcja sprawdza, czy graf zawiera œcie¿ki Hamiltona poprzez permutacjê wszystkich mo¿liwych œcie¿ek.
@param  waga struktura zawieraj¹ca wszystkie elementy grafu
@param  max iloœæ wierzcho³ków w grafie
@param  minimalnaSciezka lista, na której zostanie zapisana minimalna œcie¿ka Hamiltona
@param  suma_wag_minimalnej przechowuje sumê wag dla dotychczasowej minimalnej œcie¿ki
@param  ile_sciezek przechowuje informacje o iloœci œcie¿ek w grafie
@param  ile_sciezek_minimalnych przechowuje informacje o iloœci minimalnych œcie¿ek w grafie
@return zwraca informacjê, czy graf zawiera œcie¿ki Hamiltona
*/
bool czyIstniejeSciezka(std::vector<std::vector<int>>& waga, int max, std::list<int>& minimalnaSciezka, int& suma_wag_minimalnej, int& ile_sciezek, int& ile_sciezek_minimalnych);

/** Funkcja eksportuje minimaln¹ œcie¿kê Hamiltona do pliku wyjœciowego.
@param[out]  wyjscie strumieñ wejœciowy z plikiem, do którego zostanie zapisana œcie¿ka
@param  sciezka minimalna œcie¿ka
@param  ile_minimalnych iloœæ minimalnych œcie¿ek, które wyst¹pi³y w grafie
*/
void eksportujSciezkeDoPliku(std::ofstream& wyjscie, std::list<int>& sciezka, int ile_minimalnych);

#endif