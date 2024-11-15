#include "MainForm.h"
System::Void Project2::CreateLinkedList::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	MainForm^ CG = gcnew MainForm();
	CG->ShowDialog();
	this->~CreateLinkedList();
}
