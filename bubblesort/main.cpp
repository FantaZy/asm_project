#include "plikCPP.h"
#include "ArrayToBeSort.h"
#include <future>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <mutex>
#include <thread>
#include <list>


#undef UNICODE
#include <Windows.h>





const string FOLDER_OUT = ".\\folder_out\\";
const int ILOSC_PLIKOW_TESTOWYCH = 5;
const string FOLDER_IN = ".\\folder_in\\";

using namespace std;

int foo()
{
	return 0;
}

int main()
{

	int ileWatkow = 4; // tymczasowa ilosc watkow podana przez usera;
	int index = 0;
	int index2 = 0;
	
	mutex sort_mutex;
	/*
	//watki
	int* tab = createTable(30);	
	thread first(fun,tab,8);	
	first.join();*/

	vector<string> listaSciezekPlikow;
	vector<ArrayToBeSort> listaTablicDoSortowania;
	vector<thread> listaWatkow(ileWatkow);

	for (int i = 0; i < ILOSC_PLIKOW_TESTOWYCH; i++)
	{
		string indeksPliku = to_string(i); //zmiana indeksu pliku na stringa
		listaSciezekPlikow.push_back(FOLDER_IN + indeksPliku + ".txt");
	}

	/*wype³nienie listyTablicDoSortowania tablicami liczb*/
	
	for (string &list : listaSciezekPlikow)
	{
		string tmp = to_string(index);
		
		ArrayToBeSort tab(listaSciezekPlikow[index], FOLDER_OUT + tmp + ".txt");
		//tab.wczytajPlik();
		listaTablicDoSortowania.push_back(tab);				
		index++;					
	}
	
	for (int i = 0; i < ileWatkow; i++)
		listaWatkow.push_back(thread([&listaTablicDoSortowania, &sort_mutex ]{
			while (true)
			{
				sort_mutex.lock();
				if (listaTablicDoSortowania.empty())
				{
					sort_mutex.unlock();
					break;						
				}
				ArrayToBeSort tablicaDoSortowania = listaTablicDoSortowania.back();
				listaTablicDoSortowania.pop_back();
				
				tablicaDoSortowania.startASM();
				sort_mutex.unlock();
				
				
			}
	}
		
	));

	for (thread& th : listaWatkow)
		th.join();
	
	

	cout << "<done>\n";

	cout << "\n<done2>\n";
	
	
	system("pause");

	return 0;
}