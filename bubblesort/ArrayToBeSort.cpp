#include "ArrayToBeSort.h"
#include <Windows.h>
using namespace std;



int ArrayToBeSort::init()
{

	lib = LoadLibrary("plikASM.dll");
	if (lib == NULL)
	return -1;

	fun = (funkcja)GetProcAddress(lib, "sort");
	if (fun == NULL)
	return -1;

	libCpp = LoadLibrary("plikCPP.dll");
	if (libCpp == NULL)
	return -1;

	funCpp = (funkcja)GetProcAddress(libCpp, "testfunc");
	if (funCpp == NULL)
	return -1;

}

ArrayToBeSort::ArrayToBeSort(string sciezkaI, string sciezkaO)
{
	setSciezkaIn(sciezkaI);
	setSciezkaOut(sciezkaO);
	iloscElementow = ileLiczbWPliku(sciezkaIn);
	ptrToIn = nullptr;
	ptrToOut = nullptr;
	init();
	
}


ArrayToBeSort::~ArrayToBeSort()
{
	delete[] ptrToIn;
	delete[] ptrToOut;
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
		plik.close();
		return iloscLiczb;
	}
	else return -1;
	
}


/*funkcja wczytujaca liczby z pliku, wpisuje je do tablicy, ktora zwraca*/
void ArrayToBeSort::wczytajPlik()
{

fstream plik;
	plik.open(this->sciezkaIn, ios::in);


	if (plik.is_open() == true)
	{
		int i = 0;
		int j = this->ileLiczbWPliku(this->sciezkaIn);
		//int *tab;
		//tab = new int[j];
		this->ptrToIn = new int[j];

		int temp = 0;


		while (!plik.eof())
		{

			plik >> temp;
			//tab[i] = temp;
			this->ptrToIn[i] = temp;
			cout << this->ptrToIn[i] << "\n";
			i++;

		}
		//return tab;
		


	}
	else cout << "blad przy wczytywaniu pliku";  // je¿eli nie uda³o siê otworzyæ pliku to zwracamy nullptr 
	plik.close();



}


void ArrayToBeSort::zapiszPlik()
{
	fstream plik;
	plik.open(this->sciezkaOut, fstream::out);

	for (int i = 0; i < this->iloscElementow; i++)
	{
		plik << this->ptrToOut[i] << "\n";
	}
	plik.close();
}

void ArrayToBeSort::sortujWAsm()
{
	this->kopiujTablice();
	fun(this->ptrToOut, this->iloscElementow);
}

void ArrayToBeSort::sortujWCPP()
{
	this->kopiujTablice();
	funCpp(this->ptrToOut, this->iloscElementow);
}

void ArrayToBeSort::kopiujTablice()
{
	this->ptrToOut = new int[this->iloscElementow];
	for (int i = 0; i < this->iloscElementow; i++)
	{
		this->ptrToOut[i] = this->ptrToIn[i];
	}
}


void ArrayToBeSort::setSciezkaIn(string sciezka)
{
	sciezkaIn = sciezka;
}

void ArrayToBeSort::setSciezkaOut(string sciezka)
{
	sciezkaOut = sciezka;
}

void ArrayToBeSort::startCPP()
{
	this->wczytajPlik();
	this->sortujWCPP();
	this->zapiszPlik();
}

void ArrayToBeSort::startASM()
{
	this->wczytajPlik();
	this->sortujWAsm();
	this->zapiszPlik();
}

void ArrayToBeSort::operator=(const ArrayToBeSort &arr)
{
	sciezkaIn = arr.sciezkaIn;
	sciezkaOut = arr.sciezkaOut;
	iloscElementow = arr.iloscElementow;
	ptrToIn = new int[iloscElementow];
	ptrToOut = new int[iloscElementow];
	memcpy((void*)ptrToIn, (void*)arr.ptrToIn, iloscElementow * sizeof(ptrToIn[0]));
	memcpy((void*)ptrToOut, (void*)arr.ptrToOut, iloscElementow * sizeof(ptrToOut[0]));
	//indeksPliku = arr.indeksPliku;

}