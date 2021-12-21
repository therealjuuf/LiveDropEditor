#include "LiveDropEditorGUI.h"





using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]





void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	LiveDropEditor::LiveDropEditorGUI frm;
	Application::Run(% frm);


}