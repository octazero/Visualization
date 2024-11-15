#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MainForm form;
	Application::Run(%form);
}
System::Void Project2::MainForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 CreateGraph^ CG = gcnew CreateGraph();
			 CG->ShowDialog();
			 this->~MainForm();
}
System::Void Project2::MainForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 CreateRBTree^ CG = gcnew CreateRBTree();
			 CG->ShowDialog();
			 this->~MainForm();
}
System::Void Project2::MainForm::button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 CreateQueue^ CG = gcnew CreateQueue();
			 CG->ShowDialog();
			 this->~MainForm();
}
System::Void Project2::MainForm::button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 CreateStack^ CG = gcnew CreateStack();
			 CG->ShowDialog();
			 this->~MainForm();
}
System::Void Project2::MainForm::button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 CreateLinkedList^ CG = gcnew CreateLinkedList();
			 CG->ShowDialog();
			 this->~MainForm();
}
System::Void Project2::MainForm::button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 Create234^ CG = gcnew Create234();
			 CG->ShowDialog();
			 this->~MainForm();
}
System::Void Project2::MainForm::button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 CreateBinaryTree^ CG = gcnew CreateBinaryTree();
			 CG->ShowDialog();
			 this->~MainForm();
}