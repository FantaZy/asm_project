#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;







class ArrayToBeSort
{
public:	
	string sciezkaIn;
	string sciezkaOut;
	int iloscElementow;
	int* ptrToIn;
	int* ptrToOut;
	static int indeksPliku;

public:

	void sortujWAsm();
	void sortujWCPP();
	void setSciezkaIn(string sciezka);
	void setSciezkaOut(string sciezka);

	int ileLiczbWPliku(string sciezka);
	void kopiujTablice();
	void wczytajPlik();
	void zapiszPlik();
	void startCPP();
	void startASM();
	int* getPtrToIn(){ return ptrToIn; }
	void operator=(const ArrayToBeSort &arr);

	ArrayToBeSort(string sciezkaI, string sciezkaO);
	ArrayToBeSort(){}
	~ArrayToBeSort();
};

