#include "MyForm.h"
#include <iostream>
#include <stdlib.h>


using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<String^>^ args)

	{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUI::MyForm form;

	
	Application::Run(%form);
	}