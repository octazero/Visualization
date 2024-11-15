#pragma once
#pragma comment(lib, "user32.lib")
#include "Graph.h"
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <cereal\types\vector.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <limits.h>
using namespace std;

namespace Project2 {
	
	static Graph G;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class CreateGraph : public System::Windows::Forms::Form
	{
		
		bool drawline; int sordorb;
		Label^ write; int count;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
			 
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	public:
		CreateGraph(void)
		{
			drawline = false;
			sordorb = 0;
			count = 0;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateGraph()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected: void drawmatrix(PaintEventArgs^ e)
	{
				   
				   Pen^ p = gcnew Pen(Color::DarkTurquoise, 3.0f);
				   Point p1, p2;
				   string text = to_string(G.matrix.size());
				   gcnew String(text.c_str());
				  
				   for (int i = 0; i < G.matrix.size(); i++)
				   for (int j = 0; j < G.matrix.size(); j++)
				   {

					   if (G.matrix[i][j] != 0 && G.matrix[i][j] != 32767){

						   p1.X = G.nodePosition[i].x + 25;
						   p1.Y = G.nodePosition[i].y + 25;
						   p2.X = G.nodePosition[j].x + 25;
						   p2.Y = G.nodePosition[j].y + 25;
						   
						   e->Graphics->DrawLine(p, p1, p2);

						   RectangleF rec = RectangleF((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2,
							   100, 100);
						  
						   e->Graphics->DrawString(gcnew String(to_string(G.matrix[i][j]).c_str()),
							   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
							   rec);
						  
					   }

				   }
				   for (int i = 0; i < G.matrix.size(); i++)
				   {

					   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkTurquoise), G.nodePosition[i].x, G.nodePosition[i].y, 50, 50);
					   RectangleF rec = RectangleF(G.nodePosition[i].x + 20, G.nodePosition[i].y + 20, 50, 50);
					   e->Graphics->DrawString(gcnew String(to_string(i).c_str()),
						   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
						   rec);
				   }
	}
	protected: void drawpath(PaintEventArgs^ e)
	{	
				   Pen^ p = gcnew Pen(Color::Green, 3.0f);
				   Point p1, p2;
				   vector<int> k;
				   vector<vector<int>> m;
				   m = G.matrix;
					   
					   for (int i = 0; i < G.paths.size(); i++)
						   k.push_back(G.paths[i]);
					   for (int i = 0; i < k.size() - 1; i++)
					   {
						   if (G.matrix[k[i]][k[i + 1]] != 32767 && G.matrix[k[i]][k[i + 1]] != 0){
							   p1.X = G.nodePosition[k[i]].x + 25;
							   p1.Y = G.nodePosition[k[i]].y + 25;
							   p2.X = G.nodePosition[k[i + 1]].x + 25;
							   p2.Y = G.nodePosition[k[i + 1]].y + 25;

							   e->Graphics->DrawLine(p, p1, p2);
							   RectangleF rec = RectangleF((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2,
								   100, 100);

							   e->Graphics->DrawString(gcnew String(to_string(G.matrix[k[i]][k[i + 1]]).c_str()),
								   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
								   rec);
						   }
					   }
				   

					   for (int i = 0; i < k.size(); i++)
					   {
						   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), G.nodePosition[k[i]].x, G.nodePosition[k[i]].y, 50, 50);
						   RectangleF rec = RectangleF(G.nodePosition[k[i]].x + 20, G.nodePosition[k[i]].y + 20, 100, 100);
						   e->Graphics->DrawString(gcnew String(to_string(k[i]).c_str()),
							   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
							   rec);
						   rec = RectangleF(G.nodePosition[k[i]].x + 20, G.nodePosition[k[i]].y -10 , 50, 50);
						   e->Graphics->DrawString(gcnew String(to_string(i).c_str()),
							   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
							   rec);
					   }

	}
	protected: void ColorNode(PaintEventArgs^ e,int node,int *k)
	{
				   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), G.nodePosition[k[node]].x, G.nodePosition[k[node]].y, 50, 50);
				   RectangleF rec = RectangleF(G.nodePosition[k[node]].x + 20, G.nodePosition[k[node]].y + 20, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(k[node]).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
				   rec = RectangleF(G.nodePosition[k[node]].x + 20, G.nodePosition[k[node]].y - 10, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(node).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
	}
	protected: void OnPaint(PaintEventArgs^ e)  override
		{
				
			drawmatrix(e);
			Form::OnPaint(e);
			if (sordorb != 0)
			{
				if (sordorb==3)
					drawpath(e);
				else if (sordorb == 2)
					ColorNode(e, count, G.DF);
				else
					ColorNode(e, count, G.BF);
			}
		}
	
	protected:
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 51);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Node";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreateGraph::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(85, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(208, 32);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(85, 20);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(417, 1);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 51);
			this->button2->TabIndex = 3;
			this->button2->Text = L"connect";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CreateGraph::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(126, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Start";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(234, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Arrival";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(312, 32);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(85, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &CreateGraph::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(336, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Weight";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(874, 1);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 51);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Use Mode";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CreateGraph::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1, 1);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(101, 51);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Breadth First";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &CreateGraph::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(101, 1);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(101, 51);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Depth First";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &CreateGraph::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(417, 1);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(107, 51);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Shortest Path";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &CreateGraph::button6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(530, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 42);
			this->label5->TabIndex = 13;
			this->label5->Visible = false;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(982, 1);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(107, 51);
			this->button7->TabIndex = 14;
			this->button7->Text = L"BACK";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &CreateGraph::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1090, 1);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(107, 51);
			this->button8->TabIndex = 15;
			this->button8->Text = L"NEXT";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &CreateGraph::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(690, 1);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(86, 50);
			this->button9->TabIndex = 16;
			this->button9->Text = L"Load";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &CreateGraph::button9_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &CreateGraph::openFileDialog1_FileOk);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(782, 1);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(86, 50);
			this->button10->TabIndex = 17;
			this->button10->Text = L"Save";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &CreateGraph::button10_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &CreateGraph::saveFileDialog1_FileOk);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(1203, 4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(100, 50);
			this->button11->TabIndex = 18;
			this->button11->Text = L"Clear Graph";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &CreateGraph::button11_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(5, 690);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(106, 17);
			this->checkBox1->TabIndex = 19;
			this->checkBox1->Text = L"check Distances";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(1216, 660);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(150, 50);
			this->button12->TabIndex = 20;
			this->button12->Text = L"Back to Main";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &CreateGraph::button12_Click);
			// 
			// CreateGraph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 750);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Name = L"CreateGraph";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Creation Mode";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 while (1)
				 {
					 if (GetAsyncKeyState(VK_RBUTTON))
					 {
						 POINT T1;
						 GetCursorPos(&T1);
						 T1.x -= 25; T1.y -= 25;						
							
						 G.addNode(T1);
						 Invalidate();
						 break;
						
					 }
					 Sleep(100);
				 }
				 
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			
				 string start = msclr::interop::marshal_as<string>(this->textBox1->Text);
				 string arrival = msclr::interop::marshal_as<string>(this->textBox2->Text);
				 string weight = msclr::interop::marshal_as<string>(this->textBox3->Text);
				 int x, y, z;
				 try
				 {
					 exception e;
					 for (int i = 0; i < start.size(); i++)
					 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
						 throw  e;
					 for (int i = 0; i < arrival.size(); i++)
					 if (arrival[i]>'9' || arrival[i]<'0' && arrival[i] != '-')
						 throw  e;
					 for (int i = 0; i < weight.size(); i++)
					 if (weight[i]>'9' || weight[i]<'0')
						 throw  e;
					 x = stoi(start);
					 y = stoi(arrival);
					 z = stoi(weight);
				 }
				 catch (exception e)
				 {
					 MessageBox::Show("check your inputs");
					 return;
				 };
				
				 if (G.nodePosition.size() < x || G.nodePosition.size() < y || y < 0 || x < 0 || x == y)
					 return;
				 G.addLength(x, y, z);
				 if (checkBox1->Checked)
				 G.adjustdistances(x, y);
				 Invalidate();
				
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (!drawline)
			 {
				 this->button4->Visible = true;
				 this->button5->Visible = true;
				 this->button6->Visible = true;
				 this->label5->Visible = true;
				 this->label5->Text = L"";
				 this->label2->Text = L"Start";
				 this->label3->Text = L"Arrival";
				 this->Text = L"Use Mode";
				 this->button3->Text = L"Creation Mode";
				 this->textBox1->Text = L"";
				 this->textBox2->Text = L"";
				 this->textBox3->Text = L"";
				 drawline = !drawline;
				 G.Floyd();
			 }
			 else
			 {
				 drawline = !drawline;
				 this->button4->Visible = false;
				 this->button5->Visible = false;
				 this->button6->Visible = false;
				 this->button7->Visible = false;
				 this->button8->Visible = false;
				 this->label5->Visible = false;
				 this->label2->Text = L"Arrival";
				 this->label3->Text = L"Weight";
				 this->Text = L"Creation Mode";
				 this->button3->Text = L"Use Mode";
				 this->textBox1->Text = L"";
				 this->textBox2->Text = L"";
				 this->textBox3->Text = L"";
				 sordorb = 0;
				 Invalidate();
			 }
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 string breadthfirst = msclr::interop::marshal_as<string>(this->textBox2->Text);
			 try
			 {
				 exception e;
				 for (int i = 0; i < breadthfirst.size(); i++)
				 if (breadthfirst[i]>'9' || breadthfirst[i]<'0' && breadthfirst[i] != '-')
					 throw  e;
				 int size = stoi(breadthfirst);
				 if (G.matrix.empty()||size>G.matrix.size()||size<0)
					 return;
				 G.BreadthFirst(size);
				 sordorb = 1;
				 count = 0;
				 Invalidate();
				 this->button7->Visible = true;
				 this->button8->Visible = true;
				 this->label5->Visible = false;
			 }
			 catch (exception e)
			 {
				 MessageBox::Show("check your inputs");
				 return;
			 };
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 string depthfirst = msclr::interop::marshal_as<string>(this->textBox2->Text);
			 try
			 {
				 exception e;
				 for (int i = 0; i < depthfirst.size(); i++)
				 if (depthfirst[i]>'9' || depthfirst[i]<'0' && depthfirst[i] != '-')
					 throw  e;
				 int size = stoi(depthfirst);
				 if (G.matrix.empty() || size>G.matrix.size() || size<0)
					 return;
				 G.DepthFirstStart(size);
				 sordorb = 2;
				 count = 0;
				 Invalidate();
				 this->button7->Visible = true;
				 this->button8->Visible = true;
				 this->label5->Visible = false;
			 }
			 catch (exception e)
			 {
				 MessageBox::Show("check your inputs");
				 return;
			 };
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 string start = msclr::interop::marshal_as<string>(this->textBox2->Text);
			 string arrival = msclr::interop::marshal_as<string>(this->textBox3->Text);
			 try
			 {
				 exception e;
				 for (int i = 0; i < start.size(); i++)
				 if (start[i]>'9' || start[i]<'0' && start[i] != '-')
					 throw  e;
				 for (int i = 0; i < arrival.size(); i++)
				 if (arrival[i]>'9' || arrival[i]<'0' && arrival[i] != '-')
					 throw  e;
				 int s = stoi(start), a = stoi(arrival);
				 if (G.matrix.empty() || s>=G.matrix.size() || s<0 || a>=G.matrix.size() || a<0)
					 return;
				 int dist = G.getDistance(s,a);
				 if (dist == 32767)
				 {
					 this->label5->Text = L"no path";
				 }
				 else
				 {
					 this->label5->Text ="="+gcnew String(to_string(dist).c_str());
					 sordorb = 3;
					 Invalidate();
				 }
			 }
			 catch (exception e)
			 {
				 MessageBox::Show("check your inputs");
				 return;
			 }; this->button7->Visible = false;
			 this->button8->Visible = false;
			 this->label5->Visible = true;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 if (sordorb == 2)
				 {
					 if (0 == count)
						 count = G.counterDF - 1;
					 else count--;
				 }
				 else
				 {
					 if (0 == count)
						 count = G.counterBF - 1;
					 else count--;
				 }
				 Invalidate();
				 this->label5->Visible = false;
			 }
			 catch (exception e)
			 {
				 MessageBox::Show("check your inputs");
				 return;
			 };
}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
				 if (sordorb == 2)
				 {
					 if (G.counterDF-1 == count)
						 count = 0;
					 else count++;
				 }
				 else
				 {
					 if (G.counterBF-1 == count)
						 count = 0;
					 else count++;
				 }
				 Invalidate();
				 this->label5->Visible = false;
				 }
				 catch (exception e)
				 {
					 MessageBox::Show("check your inputs");
					 return;
				 };
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 try{
					 string file = msclr::interop::marshal_as<string>(openFileDialog1->FileName);
					 ifstream in;
					 in.open(file, ios::binary);
					 int NodeS, mSize;
					 in >> NodeS;
					 in >> mSize;

					 G.nodePosition.resize(NodeS);
					 G.matrix.resize(mSize);
					 for (int i = 0; i < mSize; i++)
						 G.matrix[i].resize(mSize);
					 cereal::BinaryInputArchive archive(in);
					 archive(G);
					 in.close();
					 Invalidate();
					 MessageBox::Show("Load Successfully");
				 }
				 catch (exception e){ MessageBox::Show("Cannot Load file"); }
			 }
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {

			 //G.deletGraph();


			 Invalidate();
			 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 try{
				 string file = msclr::interop::marshal_as<string>(saveFileDialog1->FileName);
				 ofstream out;
				 out.open(file + ".cereal", ios::binary);
				 out << G.nodePosition.size() << ' ';
				 int m = G.matrix.size();
				 out << m;
				 Graph s = G;
				 cereal::BinaryOutputArchive archive(out);
				 archive(G);
				 out.close();
				 MessageBox::Show("Saved Successfully");
			 }
			 catch (exception e){ MessageBox::Show("Cannot Save file"); }
			 }
}
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e){
			 G.deletGraph();
			 sordorb = 0;
			 Invalidate();

}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}

