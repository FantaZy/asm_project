
#include <Windows.h>

#include <iostream>
using namespace std;

#include "plikCPP.h"


extern "C"
{
void __declspec(dllexport) __cdecl testfunc(int* array, int amount)
	{
		int i,j, swap;


		for (i = 0; i < (amount - 1) ; i++)
		{
			for (j = 0; j < amount - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap = array[j];
					array[j] = array[j + 1];
					array[j + 1] = swap;

				}
			}
		}
		cout << "funkcja testfunc() - dzia³a! " ;
	}

	
}

extern "C"
{
	void __declspec(dllexport) __cdecl Crap()
	{
		cout << "I'm called within a crappy DLL!";
	}
}
