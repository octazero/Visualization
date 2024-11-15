#pragma once
#pragma comment(lib, "user32.lib")
#include "Queue.h"
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <limits.h>
#include <time.h>
namespace Project2 { 

	static myQueue Q;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for CreateQueue
	/// </summary>
	public ref class CreateQueue : public System::Windows::Forms::Form
	{
	public:
		CreateQueue(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected: void drawNode(PaintEventArgs^ e, int iterator, int x, int y,int prevx,int prevy,int adder)
	{
		if (prevx != -1)
		{
			Pen^ p= gcnew Pen(Color::CadetBlue, 3.0f);

			Point p1, p2;
			p1.X = x + 25;
			p1.Y = y + 25;
			p2.X = prevx + 25;
			p2.Y = prevy + 25;
			e->Graphics->DrawLine(p, p1, p2);
			e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), prevx, prevy, 50, 50);
			RectangleF rec = RectangleF(prevx + 15, prevy + 15, 50, 50);
			e->Graphics->DrawString(gcnew String(to_string(Q[iterator+1]).c_str()),
				this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
				rec);
			rec = RectangleF(prevx + 20, prevy - 11, 50, 50);
			e->Graphics->DrawString(gcnew String(to_string(iterator+1).c_str()),
				this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
				rec);
		}	   
		e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), x, y, 50, 50);
		RectangleF rec = RectangleF(x + 15, y + 15, 50, 50);
		e->Graphics->DrawString(gcnew String(to_string(Q[iterator]).c_str()),
			this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
			rec);
		rec = RectangleF(x + 20, y - 11, 50, 50);
		e->Graphics->DrawString(gcnew String(to_string(iterator).c_str()),
			this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
			rec);
		
		iterator = iterator - 1;
		if (iterator >= 0)
		{
			
			prevx = x;
			prevy = y;
			if (x == 1310)
			{
				y += 100;
				adder = -adder;
			}
			else if (x == 10)
			{
				y += 100;
				adder = -adder;
			}
				x += adder;
				drawNode(e, iterator, x, y, prevx, prevy, adder);


		}
	}
	protected: void OnPaint(PaintEventArgs^ e)  override
	{
				   if (!Q.empty())
				   drawNode(e,Q.size-1, 110, 100, -1, -1,100);
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateQueue()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button6;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"enQueue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreateQueue::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(252, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(133, 43);
			this->button2->TabIndex = 1;
			this->button2->Text = L"deQueue";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CreateQueue::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(151, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(95, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1216, 660);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 50);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Back to Main";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CreateQueue::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1268, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Number of nodes";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1262, 34);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 20;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1162, 9);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(94, 46);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Random Generation";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &CreateQueue::button6_Click);
			// 
			// CreateQueue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 750);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"CreateQueue";
			this->Text = L"CreateQueue";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &CreateQueue::CreateQueue_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 string start = msclr::interop::marshal_as<string>(this->textBox1->Text);
				 try
				 {
					 exception e;
					 for (int i = 0; i < start.size(); i++)
					 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
						 throw  e;
					 Q.Enqueque(stoi(start));
					 Invalidate();
				 }catch (exception e){
				 MessageBox::Show("check your input!!");
				 return;
			 }
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 try
				 {
					 Q.Dequeue();
					 Invalidate();
				 }
				 catch (exception e){
					 MessageBox::Show("check your input!!");
					 return;
				 }
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 string s2 = msclr::interop::marshal_as<string>(this->textBox3->Text);
			 try
				 {
				 if (78 < Q.size + stoi(s2)){
					 MessageBox::Show("Maximum 78 nodes");
					 return;
				 }
				 exception e;
				 for (int i = 0; i < s2.size(); i++)
				 if (s2[i]>'9' || s2[i]<'0' )
					 throw  e;
				 for (int i = 0; i < stoi(s2); i++)
				 {
					 
					 int x = (rand() + time(0)) % 1000;
					Q.Enqueque(x);
					 Invalidate();
				 }
			 }
			 catch (exception e){
				 MessageBox::Show("check your input!!");
				 return;
			 }
}
private: System::Void CreateQueue_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
