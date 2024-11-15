#pragma once
#pragma comment(lib, "user32.lib")
#include <WinUser.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <limits.h>
using namespace std;
namespace Project2 {
	static rbtree<int> T234;
	static _rbTreeNode<int> *cat2;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// </summary>
	public ref class Create234 : public System::Windows::Forms::Form
	{
	public:
		bool search2;
		Create234(void)
		{
			search2 = false;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Create234()
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
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button7;

	private: System::Windows::Forms::TextBox^  textBox3;
	protected: void colorNode(PaintEventArgs^ e, _rbTreeNode<int> *x)
	{

				   e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow), x->nodePosition.x, x->nodePosition.y, 50, 50);
				   RectangleF rec = RectangleF(x->nodePosition.x + 20, x->nodePosition.y + 20, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(x->key).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
	}
	protected: void drawRBtree(PaintEventArgs^ e, _rbTreeNode<int> *x, int low, int high, int height)
	{
				   SolidBrush^ S1;
				   if (x != T234.nil)
				   {
					   if (x != NULL)
					   {
						   if (x->color == true)
						   {
							   if (x == x->p->left)
							   {
								   x->nodePosition.x = x->p->nodePosition.x - 50;
								   x->nodePosition.y = x->p->nodePosition.y;
							   }
							   else if (x == x->p->right)
							   {
								   x->nodePosition.x = x->p->nodePosition.x + 50;
								   x->nodePosition.y = x->p->nodePosition.y;
							   }
						   }
						   else
						   {
							   x->nodePosition.x = (high + low) / 2;
							   x->nodePosition.y = (height);
						   }
						   
						   if (x->color == true)
							   S1 = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Turquoise);
						   else
							   S1 = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Turquoise);

						   height = height + 100;
						   if (x->p != NULL&&x->p != T234.nil)
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
					   }
					   if (x->left != NULL)
					   {

						   drawRBtree(e, x->left, low, (high + low) / 2, height);
					   }
					   if (x->right != NULL)
					   {
						   drawRBtree(e, x->right, (high + low) / 2, high, height);
					   }
					   e->Graphics->FillRectangle(S1, x->nodePosition.x, x->nodePosition.y, 50, 50);
					   RectangleF rec = RectangleF(x->nodePosition.x + 20, x->nodePosition.y + 20, 50, 50);
					   e->Graphics->DrawString(gcnew String(to_string(x->key).c_str()),
						   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
						   rec);
				   }
	}
				   

	protected: void OnPaint(PaintEventArgs^ e)  override
	{
				   Form::OnPaint(e);
				   if (T234.root != T234.nil)
					   drawRBtree(e, T234.root, 0, 1336, 100);
				   if (search2 == true)
				   {
					   if (cat2 != NULL)
					   {
						   colorNode(e, cat2);
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
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
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
			this->button1->Click += gcnew System::EventHandler(this, &Create234::whatever);
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
			this->button2->Click += gcnew System::EventHandler(this, &Create234::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(460, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 34);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Search";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Create234::button3_Click);
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
			this->button5->Click += gcnew System::EventHandler(this, &Create234::button5_Click);
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
			this->button4->Click += gcnew System::EventHandler(this, &Create234::button4_Click);
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
			this->button6->Location = System::Drawing::Point(996, 9);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(143, 37);
			this->button6->TabIndex = 10;
			this->button6->Text = L"Clear";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Create234::button6_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1216, 660);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(150, 50);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Back to Main";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Create234::button8_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1261, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Number of nodes";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(1255, 37);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 23;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1155, 12);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(94, 46);
			this->button7->TabIndex = 22;
			this->button7->Text = L"Random Generation";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Create234::button7_Click);
			// 
			// Create234
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 343);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Create234";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"2-3-4 Tree";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void whatever(System::Object^  sender, System::EventArgs^  e) {

				 string start = msclr::interop::marshal_as<string>(this->textBox1->Text);\
					 try
				 {
					 exception e;
					 for (int i = 0; i < start.size(); i++)
					 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
						 throw  e;

				 T234.insert(stoi(start));
				 Invalidate();
				 cat2 = NULL;
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
					 T234.erase(stoi(start));
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

				 if (T234.root == NULL)
					 int msgboxID = MessageBoxW(NULL, L"the tree is empty!", L"Congrats", MB_ICONEXCLAMATION);
				 else if (T234.root->key == stoi(start))
				 {
					 cat2 = T234.root;

					 search2 = true;
					 Invalidate();
					 int msgboxID = MessageBoxW(NULL, L"the value is found!", L"Congrats", MB_ICONEXCLAMATION);

				 }
				 else {
					 cat2 = T234.root;
					 search2 = true;
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
				 if (cat2->key < stoi(start))
				 {
					 if (cat2->right == NULL)
					 {
						 cat2 = NULL;
						 Invalidate();
						 int msgboxID = MessageBoxW(NULL, L"the value does not exist!", L"Congrats", MB_ICONEXCLAMATION);

					 }
					 else if (cat2->right->key == stoi(start))
					 {
						 cat2 = cat2->right;
						 Invalidate();
						 this->button4->Visible = true;
						 int msgboxID = MessageBoxW(NULL, L"the value is found!", L"Congrats", MB_ICONEXCLAMATION);
						 this->button5->Visible = false;
					 }
					 else
					 {
						 cat2 = cat2->right;
						 Invalidate();
						 this->button4->Visible = true;
					 }
				 }
				 else{
					 if (cat2->left == NULL)
					 {
						 cat2 = NULL;
						 Invalidate();
						 int msgboxID = MessageBoxW(NULL, L"the value does not exist!", L"Congrats", MB_ICONEXCLAMATION);
						 this->button5->Visible = false;
					 }
					 else if (cat2->left->key == stoi(start))
					 {
						 cat2 = cat2->left;
						 this->button5->Visible = false;
						 this->button4->Visible = true;
						 Invalidate();
						 int msgboxID = MessageBoxW(NULL, L"the value is found!", L"Congrats", MB_ICONEXCLAMATION);

					 }
					 else
					 {
						 cat2 = cat2->left;
						 Invalidate();
						 this->button4->Visible = true;
					 }
				 }
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (cat2->p != NULL)
				 {
					 cat2 = cat2->p;
					 Invalidate();
					 if (cat2->p == NULL)
						 this->button4->Visible = false;
				 }
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 T234.root = T234.nil;
				 T234.counter = 0;
				 Invalidate();
	}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 string s2 = msclr::interop::marshal_as<string>(this->textBox4->Text);
			 try
			 {
				 if (40 < T234.counter + stoi(s2)){
					 MessageBox::Show("Maximum 40 nodes");
					 return;
				 }
				 exception e;
				 for (int i = 0; i < s2.size(); i++)
				 if (s2[i]>'9' || s2[i]<'0'&&s2[i])
					 throw  e;
				 for (int i = 0; i < stoi(s2); i++)
				 {
					 int x = (rand() + time(0)) % 1000;
					 T234.insert(x);
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
