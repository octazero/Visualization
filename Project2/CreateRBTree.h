#pragma once
#pragma comment(lib, "user32.lib")
#include "AnotherRBTree.h"
#include <WinUser.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <limits.h>
namespace Project2 {
	static rbtree<int> RB;
	static _rbTreeNode<int> *cat;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// </summary>
	public ref class CreateRBTree : public System::Windows::Forms::Form
	{
	bool search;
	public:
		CreateRBTree(void)
		{
			search = false;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateRBTree()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button8;



	private: System::Windows::Forms::TextBox^  textBox3;
			
	protected: void colorNode(PaintEventArgs^ e, _rbTreeNode<int> *x)
	{
				   
				   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow), x->nodePosition.x, x->nodePosition.y, 50, 50);
				   RectangleF rec = RectangleF(x->nodePosition.x + 20, x->nodePosition.y + 20, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(x->key).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
	}
	protected: void drawRBtree(PaintEventArgs^ e, _rbTreeNode<int> *x, int low, int high, int height)
	{
				   if (x != RB.nil)
				   {
					   if (x != NULL)
					   {

						   x->nodePosition.x = (high + low) / 2;
						   x->nodePosition.y = (height);
						   SolidBrush^ S;
						   if (x->color == true)
							   S = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
						   else
							   S = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);

						   height = height + 100;
						   if (x->p != NULL&&x->p!=RB.nil)
						   {

							   Pen^ p;

							   if (x->color == true)
								   p = gcnew Pen(Color::Red, 3.0f);
							   else
								   p = gcnew Pen(Color::Black, 3.0f);

							   Point p1, p2;
							   p1.X = x->nodePosition.x + 25;
							   p1.Y = x->nodePosition.y + 25;
							   p2.X = x->p->nodePosition.x + 25;
							   p2.Y = x->p->nodePosition.y + 25;
							   e->Graphics->DrawLine(p, p1, p2);

						   }
						   if (x->left != NULL)
						   {

							   drawRBtree(e, x->left, low, (high + low) / 2, height);
						   }
						   if (x->right != NULL)
						   {
							   drawRBtree(e, x->right, (high + low) / 2, high, height);
						   }
						   e->Graphics->FillEllipse(S, x->nodePosition.x, x->nodePosition.y, 50, 50);
						   RectangleF rec = RectangleF(x->nodePosition.x + 20, x->nodePosition.y + 20, 50, 50);
						   e->Graphics->DrawString(gcnew String(to_string(x->key).c_str()),
							   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
							   rec);
					   }
				   }
	}
	
	protected: void OnPaint(PaintEventArgs^ e)  override
	{
				   Form::OnPaint(e);
				   if (RB.root!=RB.nil)
				   drawRBtree(e, RB.root, 0, 1336, 100);
				   if (search == true)
				   {
					   if (cat != NULL)
					   {
						   colorNode(e,cat);
					   }
				   }
	}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"insert";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreateRBTree::whatever);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(117, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(239, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 34);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CreateRBTree::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(460, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 34);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Search";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CreateRBTree::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(552, 23);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(679, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(89, 37);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Next";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &CreateRBTree::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(774, 11);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(89, 37);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Back";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &CreateRBTree::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(330, 23);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 8;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1021, 9);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(143, 37);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Clear";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &CreateRBTree::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1216, 660);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(150, 50);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Back to Main";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &CreateRBTree::button7_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1276, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Number of nodes";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(1270, 31);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 20;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1170, 6);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(94, 46);
			this->button8->TabIndex = 19;
			this->button8->Text = L"Random Generation";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &CreateRBTree::button8_Click);
			// 
			// CreateRBTree
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 750);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"CreateRBTree";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RedBlack";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void whatever(System::Object^  sender, System::EventArgs^  e) {
				 string start = msclr::interop::marshal_as<string>(this->textBox1->Text);
				 try
				 {
					 exception e;
					 for (int i = 0; i < start.size(); i++)
					 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
						 throw  e;

				
				 RB.insert(stoi(start));
				 Invalidate();
				 cat = NULL;
				 }
				 catch (exception e1){
					 MessageBox::Show("check your input");
					 return;
				 }

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 string start = msclr::interop::marshal_as<string>(this->textBox2->Text);
				 try
				 {
					 exception e;
					 for (int i = 0; i < start.size(); i++)
					 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
						 throw  e;
					 RB.erase(stoi(start));
					 Invalidate();
				 }
				 catch (exception e1){ 
					 MessageBox::Show("check your input");
					 return;
				 }
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 string start = msclr::interop::marshal_as<string>(this->textBox3->Text);
				 try
				 {
					 exception e;
					 for (int i = 0; i < start.size(); i++)
					 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
						 throw  e;
					 if (RB.root == NULL)
					 int msgboxID = MessageBoxW(NULL, L"the tree is empty!", L"Congrats", MB_ICONEXCLAMATION);
				 else if (RB.root->key == stoi(start))
				 {
					 cat = RB.root;
					 
					 search = true;
					 Invalidate();
					 int msgboxID = MessageBoxW(NULL, L"the value is found!", L"Congrats", MB_ICONEXCLAMATION);

				 }
				 else {
					 cat = RB.root;
					 search = true;
					 this->button5->Visible = true;
					 Invalidate();
				 }
				 }
				 catch (exception e1){
					 MessageBox::Show("check your input");
					 return;
				 }

	}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 string start = msclr::interop::marshal_as<string>(this->textBox3->Text);
			 
			 for (int i = 0; i < start.size(); i++)
			 if (start[i]>'9' || start[i] < '0')
			 {
				 MessageBox::Show("check your input");
				 return;
			 }
			 if (cat->key < stoi(start))
			 {
				 if (cat->right == NULL)
				 {
					  cat = NULL;
					 Invalidate();
					 int msgboxID = MessageBoxW(NULL, L"the value does not exist!", L"Congrats", MB_ICONEXCLAMATION);

				 }
				 else if (cat->right->key == stoi(start))
				 {
					 cat = cat->right;
					 Invalidate();
					 this->button4->Visible = true;
					 int msgboxID = MessageBoxW(NULL, L"the value is found!", L"Congrats", MB_ICONEXCLAMATION);
					 this->button5->Visible = false;
				 }
				 else
				 {
					 cat = cat->right;
					 Invalidate();
					 this->button4->Visible = true;
				 }
			 }
			 else{
				 if (cat->left == NULL)
				 {
					  cat = NULL;
					 Invalidate();
					 int msgboxID = MessageBoxW(NULL, L"the value does not exist!", L"Congrats", MB_ICONEXCLAMATION);
					 this->button5->Visible = false;
				 }
				 else if (cat->left->key == stoi(start))
				 {
					 cat = cat->left;
					 this->button5->Visible = false;
					 this->button4->Visible = true;
					 Invalidate();
					 int msgboxID = MessageBoxW(NULL, L"the value is found!", L"Congrats", MB_ICONEXCLAMATION);

				 }
				 else
				 {
					 cat = cat->left;
					 Invalidate();
					 this->button4->Visible = true;
				 }
			 }
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (cat->p != NULL)
			 {
				 cat = cat->p;
				 Invalidate();
				 if (cat ->p == NULL)
					 this->button4->Visible = false;
			 }
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

			 RB.root = RB.nil;
			 RB.counter = 0;
			 Invalidate();
}

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 string s2 = msclr::interop::marshal_as<string>(this->textBox4->Text);
			 try
			 {
				 if (20 < RB.counter+ stoi(s2)){
					 MessageBox::Show("Maximum 20 nodes");
					 return;
				 }
				 exception e;
				 for (int i = 0; i < s2.size(); i++)
				 if (s2[i]>'9' || s2[i]<'0')
					 throw  e;
				 for (int i = 0; i < stoi(s2); i++)
				 {
					 int x = (rand() + time(0)) % 1000;
					 RB.insert(x);
					 Invalidate();
				 }
				 
			 }
			 catch (exception e){
				 MessageBox::Show("check your input!!");
				 return;
			 }
}
};
}
