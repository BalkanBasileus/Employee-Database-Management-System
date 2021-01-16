#include "EmployeeDatabase.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //WinformCDemo is your project name
    EployeeDatabase::MyForm form;
    Application::Run(% form);

    return 0;
}
