#include "MainForm.h"
System::Void Project2::CreateQueue::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	MainForm^ CG = gcnew MainForm();
	CG->ShowDialog();
	this->~CreateQueue();
}
