#include "plikCPP.h"
#include "ArrayToBeSort.h"

#include <iostream>
#include <iostream>
#include <stdlib.h>

#include <thread>
#include <list>

#undef UNICODE
#include <Windows.h>
#include "funkcje.h"

#define FOLDER_IN ".\\folder_in\\"
#define FOLDER_OUT ".\\folder_out\\"


typedef int* (*__stdcall funkcja)(int* arr, int amount);

using namespace std;

//tworzenie tablicy dynamicznej o zadanej d³ugoœci - amount
int* createTable( int amount )
{
	
	int* tab = new int[amount];
	for (int i = 0; i < amount; i++)
	{
		int x = rand() % 1000;
		tab[i] = x;
	}
	return tab;
}
//wypisywanie przekazanej jako parametr tablicy ( wskaznik na tablicê + iloœæ elementów )
void printTable( int amount, int* tab )
{
	for (int j = 0; j < amount; j++)
	{
		cout << tab[j];
		cout << "\n";
	}
}


int main()
{

	HMODULE lib = LoadLibrary("plikASM.dll");
	if (lib == NULL)
		return -1;

	funkcja fun = (funkcja)GetProcAddress(lib, "sort");
	if (fun == NULL)
		return -1;

	HMODULE libCpp = LoadLibrary("plikCPP.dll");
	if (libCpp == NULL)
		return -1;

	funkcja funCPP = (funkcja)GetProcAddress(libCpp, "testfunc");
	if (funCPP == NULL)
		return -1;

	/*
	//watki
	int* tab = createTable(30);	
	thread first(fun,tab,8);	
	first.join();*/
	
	


	
//	int x = ileLiczbWPliku(FOLDER_IN "plik.txt");
	//int* t = new int[x];
	//t = wczytajPlik(FOLDER_IN "plik.txt", x);
	//fun( t,x );
	//funCPP(t, x);
//
	ArrayToBeSort tab(".\\folder_in\\plik.txt",".\\folder_out\\plik.txt" );
	tab.wczytajPlik();
	tab.sortujWCPP();
	tab.zapiszPlik();

	cout << "<done>\n";

	//printTable(x, t);
	

	cout << "\n<done2>\n";
	

	//delete[]t; // zwalniamy pamiêæ po tablicy


	system("pause");

	return 0;
}