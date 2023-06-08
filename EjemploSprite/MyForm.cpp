#include "MyForm.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew EjemploSprite::MyForm);
}