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
#include <chrono>
#include <ctime>


#undef UNICODE
#include <Windows.h>


using namespace std;

const string FOLDER_OUT = ".\\folder_out\\";
const int ILOSC_PLIKOW_TESTOWYCH = 4;
const string FOLDER_IN = ".\\folder_in\\";






int main()
{

//GUI::MyForm f = gcnew MyForm();
	std::chrono::time_point<std::chrono::system_clock> start, end;
	/*pomocnicza zmienna przy wyznaczaniu liczby zalecanej ilosci watkow*/
	thread watki;

	/*ilosc watkow dla jakiej bedzie dzialal program*/
	int ileWatkow = watki.hardware_concurrency(); 

	/*zmienna pomocnicza*/
	int index = 0;

	/*zmienna pomocnicza*/
	int index2 = 0;

	/*	mutex niezbedny do przy zarzadzaniu pracy watkow,
	blokuje dostep do zasobu, tak aby dwa watki nie operowaly na tych samych danych	*/
	mutex sort_mutex;

	/*wektor w ktorym przechowujemy sciezki do plikow wejsciowych*/
	vector<string> listaSciezekPlikow;

	vector<ArrayToBeSort*> listaTablicDoSortowania;
	vector<thread> listaWatkow;
	/*petla for w ktorej wypelniamy tablice sciezkami do plikow*/
	for (int i = 0; i < ILOSC_PLIKOW_TESTOWYCH; i++)
	{
		string indeksPliku = to_string(i); //zmiana indeksu pliku na stringa
		listaSciezekPlikow.push_back(FOLDER_IN + indeksPliku + ".txt");
	}



	/*wype³nienie listyTablicDoSortowania tablicami liczb*/	
	int i = 0; // zmienna pomocnicza
	for (string &list : listaSciezekPlikow)
	{
		string tmp = to_string(index++);
		listaTablicDoSortowania.push_back(new ArrayToBeSort(list, FOLDER_OUT + tmp + ".txt"));						
		i++;
	}

	start = std::chrono::system_clock::now();

	for (int i = 0; i < ileWatkow; i++)	
		
		listaWatkow.push_back(
		thread([&listaTablicDoSortowania, &sort_mutex]
		{
			while (true)
			{
				sort_mutex.lock();
				if (listaTablicDoSortowania.empty())
				{
					sort_mutex.unlock();
					break;
				}
				ArrayToBeSort* tablicaDoSortowania = listaTablicDoSortowania.back();			
				tablicaDoSortowania->startCPP();
				delete tablicaDoSortowania;
				listaTablicDoSortowania.pop_back();
				sort_mutex.unlock();
			}
		}

	));	

	for (thread& th : listaWatkow)
		th.join();

	end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::chrono::duration<double> elapsed_seconds = end - start;
	cout << "<done>\n";
	cout << "czas: " << elapsed_seconds.count() << endl;
	cout << "\n<done2>\n";


	system("pause");

	return 0;
}