#include "MainForm.h"
System::Void Project2::CreateGraph::button12_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	MainForm^ CG = gcnew MainForm();
	CG->ShowDialog();
	this->~CreateGraph();
}