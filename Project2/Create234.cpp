#include "MainForm.h"
System::Void Project2::Create234::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	MainForm^ CG = gcnew MainForm();
	CG->ShowDialog();
	this->~Create234();
}
