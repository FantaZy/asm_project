#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;







class ArrayToBeSort
{
private:	
	string sciezkaIn;
	string sciezkaOut;
	int iloscElementow;
	int* ptrToIn;
	int* ptrToOut;

public:

	
	void setSciezkaIn(string sciezka);
	void setSciezkaOut(string sciezka);
	int ileLiczbWPliku(string sciezka);
	int* wczytajPlik(string sciezka);

	ArrayToBeSort(string sciezkaI, string sciezkaO);
	~ArrayToBeSort();
};

