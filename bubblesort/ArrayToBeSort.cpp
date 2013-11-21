#include "ArrayToBeSort.h"
#include <Windows.h>


typedef int* (*__stdcall funkcja)(int* arr, int amount);

HMODULE lib = LoadLibrary("plikASM.dll");
//if (lib == NULL)
//return -1;

funkcja fun = (funkcja)GetProcAddress(lib, "sort");
//if (fun == NULL)
//return -1;

HMODULE libCpp = LoadLibrary("plikCPP.dll");
//if (libCpp == NULL)
//return -1;

funkcja funCPP = (funkcja)GetProcAddress(libCpp, "testfunc");
//if (funCPP == NULL)
//return -1;

ArrayToBeSort::ArrayToBeSort(string sciezkaI, string sciezkaO)
{
	setSciezkaIn(sciezkaI);
	setSciezkaOut(sciezkaO);
	iloscElementow = ileLiczbWPliku(sciezkaIn);
}


ArrayToBeSort::~ArrayToBeSort()
{
}


/*funckja zwraca ilosc liczb w pliku*/
int ArrayToBeSort::ileLiczbWPliku(string sciezka)

{
	ifstream plik;
	plik.open(sciezka, ios::in);
	string line;
	int iloscLiczb = 0;

	if (plik.is_open() == true)
	{
		while (getline(plik, line))
			++iloscLiczb;

		return iloscLiczb;
	}
	else return -1;
	
}


/*funkcja wczytujaca liczby z pliku, wpisuje je do tablicy, ktora zwraca*/
int* ArrayToBeSort::wczytajPlik(string sciezka)
{
	fstream plik;
	plik.open(sciezka, ios::in);


	if (plik.is_open() == true)
	{
		int i = 0;
		int j = this->ileLiczbWPliku(sciezka);
		int *tab;
		tab = new int[j];
		this->ptrToIn = tab;

		int temp = 0;


		while (!plik.eof())
		{

			plik >> temp;
			tab[i] = temp;
			cout << tab[i] << "\n";
			i++;

		}
		return tab;
		this->ptrToOut = tab;


	}
	else return nullptr;  // je¿eli nie uda³o siê otworzyæ pliku to zwracamy nullptr 
	plik.close();



}


void ArrayToBeSort::setSciezkaIn(string sciezka)
{
	sciezkaIn = sciezka;
}

void ArrayToBeSort::setSciezkaOut(string sciezka)
{
	sciezkaOut = sciezka;
}