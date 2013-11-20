#include <iostream>
#include <fstream>
#include <string>


using namespace std;

/*funckja zwraca ilosc liczb w pliku*/
int ileLiczbWPliku(string sciezka)
{
	ifstream plik;
	plik.open(sciezka, ios::in);
	string line;
	int iloscLiczb= 0;

	if (plik.is_open() == true)
	{
		while (getline(plik, line))
			++iloscLiczb;

		return iloscLiczb;
	}
	else return -1;

	

	
}


/*funkcja wczytujaca liczby z pliku, wpisuje je do tablicy, ktora zwraca*/
int* wczytajPlik(string sciezka, int iloscElementow)
{
	fstream plik;
	plik.open(sciezka, ios::in);


	if (plik.is_open() == true)
	{
		int i = 0;
		int j = iloscElementow;
		int *tab;
		tab = new int[j];

		int temp=0;


		while (!plik.eof())
		{

			plik >> temp;
			tab[i] = temp;
			cout << tab[i] << "\n";
			i++;

		}
		return tab;


	}
		else return nullptr;  // je¿eli nie uda³o siê otworzyæ pliku to zwracamy nullptr 
		plik.close();
	
	

}


