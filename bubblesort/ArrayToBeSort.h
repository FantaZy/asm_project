#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

typedef void __declspec(dllimport) (*__cdecl funkcja)(int* arr, int amount);

class ArrayToBeSort
{
private:	
	std::string sciezkaIn;
	std::string sciezkaOut;
	int iloscElementow;
	int* ptrToIn;
	int* ptrToOut;
	static int indeksPliku;
	
	HMODULE lib, libCpp;
	funkcja fun, funCpp;
	int init();
public:

	void sortujWAsm();
	void sortujWCPP();
	void setSciezkaIn(std::string sciezka);
	void setSciezkaOut(std::string sciezka);

	int ileLiczbWPliku(std::string sciezka);
	void kopiujTablice();
	void wczytajPlik();
	void zapiszPlik();
	void startCPP();
	void startASM();
	void operator=(const ArrayToBeSort &arr);

	ArrayToBeSort(std::string sciezkaI, std::string sciezkaO);
	ArrayToBeSort();
	~ArrayToBeSort();
};

