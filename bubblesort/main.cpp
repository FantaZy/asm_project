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

using namespace std;

const string FOLDER_OUT = ".\\folder_out\\";
const int ILOSC_PLIKOW_TESTOWYCH = 5;
const string FOLDER_IN = ".\\folder_in\\";





int main()
{

	int ileWatkow = 2; // tymczasowa ilosc watkow podana przez usera;
	int index = 0;
	int index2 = 0;

	mutex sort_mutex;


	vector<string> listaSciezekPlikow;
	vector<ArrayToBeSort*> listaTablicDoSortowania;
	vector<thread> listaWatkow;

	for (int i = 0; i < ILOSC_PLIKOW_TESTOWYCH; i++)
	{
		string indeksPliku = to_string(i); //zmiana indeksu pliku na stringa
		listaSciezekPlikow.push_back(FOLDER_IN + indeksPliku + ".txt");
	}

	/*wype³nienie listyTablicDoSortowania tablicami liczb*/
	ArrayToBeSort * tab[5];
	int i = 0;
	for (string &list : listaSciezekPlikow)
	{
		string tmp = to_string(index++);
		//listaTablicDoSortowania.push_back(new ArrayToBeSort(list, FOLDER_OUT + tmp + ".txt"));
		tab[i] = new ArrayToBeSort(list, FOLDER_OUT + tmp + ".txt");
		i++;
	}

	//for (int i = 0; i < ileWatkow; i++)
	//	
	//	
	//	listaWatkow.push_back(
	//	thread([&listaTablicDoSortowania, &sort_mutex]
	//	{
	//		while (true)
	//		{
	//			sort_mutex.lock();
	//			if (listaTablicDoSortowania.empty())
	//			{
	//				sort_mutex.unlock();
	//				break;
	//			}
	//			ArrayToBeSort* tablicaDoSortowania = listaTablicDoSortowania.back();
	//			
	//			
	//			tablicaDoSortowania->startCPP();
	//			
	//			delete tablicaDoSortowania;
	//			listaTablicDoSortowania.pop_back();
	//			sort_mutex.unlock();
	//		}
	//	}

	//));


	for (int i = 0; i < 5; i++)
		{
			//ArrayToBeSort* to = listaTablicDoSortowania.back();
			//to->startCPP();
			//delete to;
			//listaTablicDoSortowania.pop_back();
		tab[i]->startCPP();
		delete tab[i];
		}

	for (thread& th : listaWatkow)
		th.join();

	cout << "<done>\n";

	cout << "\n<done2>\n";


	system("pause");

	return 0;
}