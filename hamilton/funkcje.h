/** @file */
#ifndef funkcje
#define funkcje

#include <list>
#include <vector>

/** Funkcja wyznacza najwi�ksz� warto�� wierzcho�ka we wczytywanym grafie.
@param  wierzcholek_poczatkowy warto�� obecnie sczytanego wierzcho�ka pocz�tkowego z pliku
@param  wierzcholek_koncowy warto�� obecnie sczytanego wierzcho�ka ko�cowego z pliku
@return najwi�ksza warto�� wierzcho�ka zawartego w grafie
*/
int najwyzszaWartoscWierzcholka(int wierzcholek_poczatkowy, int wierzcholek_koncowy, int& max);

/** Funkcja tymczasowo wstawia aktualnie wczytane warto�ci ze strumienia wej�ciowego do wektor�w.
@param  wierzcholek_poczatkowy wektor tymczasowo przechowuj�cy wierzcho�ki pocz�tkowe pobrane z pliku
@param  wierzcholek_koncowy wektor tymczasowo przechowuj�cy wierzcho�ki ko�cowe pobrane z pliku
@param  waga_wektor wektor tymczasowo przechowuj�cy wagi wektor�w pobrane z pliku
@param  wierz_pocz liczba przedstawiaj�ca numer obecnie sczytanego wierzcho�ka pocz�tkowego z pliku
@param  wierz_konc liczba przedstawiaj�ca numer obecnie sczytanego wierzcho�ka ko�cowego z pliku
@param  waga warto�� obecnie sczytanej wagi wektora z pliku
*/
void wstawDoWektorow(std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, int wierz_pocz, int wierz_konc, int waga);

/** Funkcja ustala rozmiar w�a�ciwej struktury i wstawia elementy grafu do odpowiednich miejsc.
@param  wierzcholek_poczatkowy wektor tymczasowo przechowuj�cy wierzcho�ki pocz�tkowe pobrane z pliku
@param  wierzcholek_koncowy wektor tymczasowo przechowuj�cy wierzcho�ki ko�cowe pobrane z pliku
@param  waga_wektor wektor tymczasowo przechowuj�cy wagi wektor�w pobrane z pliku
@param  waga wektor wektor�w przechowuj�cy wagi wektor�w z grafu w indeksack kolejno przedstawiaj�cych wierzcho�ek pocz�tkowy i wierzcho�ek ko�cowy grafu z pliku
@param  max warto�� wierzcho�ka o najwi�kszym numerze wyst�puj�cego w grafie
*/
void wstawDoWektoraWektorow(std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, std::vector<std::vector<int>>& waga, int max);

/** Funkcja importuje elementy grafu (wierzcho�ki i wektory) zawarte w pliku. 
@param  wejscie strumie� wej�ciowy pliku z grafem
@param  wierzcho�ek_pocz�tkowy wektor tymczasowo przechowuj�cy wierzcho�ki ko�cowe pobrane z pliku
@param  wierzcholek_koncowy wektor tymczasowo przechowuj�cy wierzcho�ki ko�cowe pobrane z pliku
@param  waga_wektor wektor tymczasowo przechowuj�cy wagi wektor�w pobrane z pliku
@param  waga_wektora wektor wektor�w przechowuj�cy wagi wektor�w z grafu w indeksack kolejno przedstawiaj�cych wierzcho�ek pocz�tkowy i wierzcho�ek ko�cowy grafu z pliku
@param  max warto�� wierzcho�ka o najwi�kszym numerze wyst�puj�cego w grafie
*/
void importujDaneZPliku(std::ifstream& wejscie, std::vector<int>& wierzcholek_poczatkowy, std::vector<int>& wierzcholek_koncowy, std::vector<int>& waga_wektor, std::vector<std::vector<int>>& waga_wektora, int& max);

/** Funkcja sumuje wagi wektora do sumy og�lnej aktualnie sprawdzanej �cie�ki.
@param  suma dotychczasowa suma wag dla aktualnej �cie�ki
@param  waga warto�� aktualnie dodawanej wagi
@return ��czna suma wag dla aktualnie sprawdzanej �cie�ki
*/
int sumujWagi(int suma, int waga);

/** Funkcja importuje elementy grafu (wierzcho�ki i wektory) zawarte w pliku.
@param  suma warto�� sumy wektor�w dla aktualnej �cie�ki
@param  minimalna dotychczasowa najmniejsza suma wektor�w
@return zwraca informacj�, czy suma wag dla aktualnej �cie�ki jest mniejsza ni� dotychczasowe minimum
*/
bool czyMinimalna(int suma, int minimalna);

/** Funkcja zapisuje dotychczasow� minimaln� �cie�k� do listy.
@param  sciezka wektor przechowuj�cy minimaln� �cie�k� Hamiltona
@param  minimalnaSciezka lista, na kt�rej zostanie zapisana minimalna �cie�ka Hamiltona
@param  suma warto�� sumy wag dla aktualnej minimalnej �cie�ki 
@param  suma_wag_minimalnej przechowuje sum� wag dla dotychczasowej minimalnej �cie�ki
@param  max ilo�� wierzcho�k�w w grafie
*/
void zapiszMinimalnaNaLiscie(std::vector<int>& sciezka, std::list<int>& minimalnaSciezka, int suma, int& suma_wag_minimalnej, int max, int& ile_sciezek);

/** Funkcja sprawdza, czy graf zawiera �cie�ki Hamiltona poprzez permutacj� wszystkich mo�liwych �cie�ek.
@param  waga struktura zawieraj�ca wszystkie elementy grafu
@param  max ilo�� wierzcho�k�w w grafie
@param  minimalnaSciezka lista, na kt�rej zostanie zapisana minimalna �cie�ka Hamiltona
@param  suma_wag_minimalnej przechowuje sum� wag dla dotychczasowej minimalnej �cie�ki
@param  ile_sciezek przechowuje informacje o ilo�ci �cie�ek w grafie
@param  ile_sciezek_minimalnych przechowuje informacje o ilo�ci minimalnych �cie�ek w grafie
@return zwraca informacj�, czy graf zawiera �cie�ki Hamiltona
*/
bool czyIstniejeSciezka(std::vector<std::vector<int>>& waga, int max, std::list<int>& minimalnaSciezka, int& suma_wag_minimalnej, int& ile_sciezek, int& ile_sciezek_minimalnych);

/** Funkcja eksportuje minimaln� �cie�k� Hamiltona do pliku wyj�ciowego.
@param[out]  wyjscie strumie� wej�ciowy z plikiem, do kt�rego zostanie zapisana �cie�ka
@param  sciezka minimalna �cie�ka
@param  ile_minimalnych ilo�� minimalnych �cie�ek, kt�re wyst�pi�y w grafie
*/
void eksportujSciezkeDoPliku(std::ofstream& wyjscie, std::list<int>& sciezka, int ile_minimalnych);

#endif