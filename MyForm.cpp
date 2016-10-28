#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	if (!loadRecipes()) return;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project_Recipe::MyForm form;
	Application::Run(%form);

	returnMemory();
}
