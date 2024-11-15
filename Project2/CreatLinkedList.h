
#pragma once
#pragma comment(lib, "user32.lib")
#include "LinkedList.h"
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <limits.h>
#include <time.h>
namespace Project2 {
	static LinkedList L;
	static LinkedList count;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for CreateQueue
	/// </summary>
	public ref class CreateLinkedList : public System::Windows::Forms::Form
	{
		int sort; int x, y, z, w, boundi, sleep; bool sorted;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	public:
		CreateLinkedList(void)
		{
			sleep = 200;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:void Merge(PaintEventArgs^ e, int low, int high, int mid)
	{
				  int i = low, k = low, j = mid + 1, c[100];
				  int x = 100, y = 500;

				  while (i <= mid && j <= high)
				  {
					  if (L.get(i) < L.get(j))
					  {
						  c[k] = L.get(i);
						  i++;
						  k++;
						  x += 100;
					  }
					  else
					  {
						  c[k] = L.get(j);
						  j++;
						  k++;
						  x += 100;
					  }
				  }
				  while (j <= high)
				  {
					  c[k] = L.get(j);
					  j++;
					  x += 100;
					  k++;
				  }
				  while (i <= mid)
				  {
					  c[k] = L.get(i);
					  x += 100;
					  i++;
					  k++;
				  }
				  for (int i = low; i < k; i++)
				  {
					  L.set(i, c[i]);
				  }

	}
	protected:void mergesort(PaintEventArgs^ e, int l, int h)
	{


				  if (l < h)
				  {
					  int mid;
					  mid = (l + h) / 2;
					  for (int i = mid + 1; i <= h; i++)
					  {
						  e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), L.getn(i)->nodePosition.x, L.getn(i)->nodePosition.y, 50, 50);
						  RectangleF rec = RectangleF(L.getn(i)->nodePosition.x + 20, L.getn(i)->nodePosition.y + 20, 50, 50);
						  e->Graphics->DrawString(gcnew String(to_string(L.get(i)).c_str()),
							  this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), rec);
					  }
					  Sleep(1000);
					  mergesort(e, l, mid);
					  for (int i = l; i <= mid; i++)
					  {
						  e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), L.getn(i)->nodePosition.x, L.getn(i)->nodePosition.y, 50, 50);
						  RectangleF rec = RectangleF(L.getn(i)->nodePosition.x + 20, L.getn(i)->nodePosition.y + 20, 50, 50);
						  e->Graphics->DrawString(gcnew String(to_string(L.get(i)).c_str()),
							  this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), rec);
					  }
					  Sleep(1000);
					  for (int i = mid + 1; i <= h; i++)
					  {
						  e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), L.getn(i)->nodePosition.x, L.getn(i)->nodePosition.y, 50, 50);
						  RectangleF rec = RectangleF(L.getn(i)->nodePosition.x + 20, L.getn(i)->nodePosition.y + 20, 50, 50);
						  e->Graphics->DrawString(gcnew String(to_string(L.get(i)).c_str()),
							  this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), rec);
					  }
					  Sleep(1000);
					  mergesort(e, mid + 1, h);
					  for (int i = l; i <= mid; i++)
					  {
						  e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), L.getn(i)->nodePosition.x, L.getn(i)->nodePosition.y, 50, 50);
						  RectangleF rec = RectangleF(L.getn(i)->nodePosition.x + 20, L.getn(i)->nodePosition.y + 20, 50, 50);
						  e->Graphics->DrawString(gcnew String(to_string(L.get(i)).c_str()),
							  this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), rec);
					  }
					  Sleep(1000);
					  Merge(e, l, h, mid);
				  }
	}
		void InsertionSort(PaintEventArgs^ g)
		{
			int temp;
			for (int i = 0; i < L.mySize; i++)
			{
				ColorNodehigh(g, i, "<-sorted");
				Sleep(sleep);
				for (int j = i; j > 0; j--)
				{
					ColorNodelow(g, j, "insert");
					Sleep(sleep);
					if (L.get(j - 1) > L.get(j))
					{

						temp = L.get(j);
						L.set(j, L.get(j - 1));
						L.set(j - 1, temp);
						ColorRestore(g, j-1);
						PevotRestore(g, j-1);
						ColorRestore(g, j);
						PevotRestore(g, j);
					}
					else
					{
						PevotRestore(g, j);
						break;
					}
				}
				PevotRestore(g, i);
				ColorRestore(g,i);
			}
		}
	protected:void selectionSort(PaintEventArgs^ g)
	{
				  if (L.mySize > 1)
				  {
					  int i, j, minIndex=-1, tmp;
					  for (i = 0; i < L.mySize - 1; i++)
					  {
						  ColorNodelow(g, i, "select");
						  Sleep(sleep);
						  if (minIndex!=-1)
						  ColorRestore(g, minIndex);
						  minIndex = i;
						  ColorNodehigh(g, minIndex, "minIndex");
						  for (j = i + 1; j < L.mySize; j++){
							  if (L.get(j) < L.get(minIndex))
							  {
								  Sleep(sleep);
								  ColorRestore(g, minIndex);
								  minIndex = j; 
								  ColorNodehigh(g, minIndex, "minIndex");
							  }
						  }
						  if (minIndex != i)
						  {
							  Sleep(sleep);
							  ColorRestore(g, minIndex);
							  tmp = L.get(i);
							  L.set(i,L.get(minIndex));
							  ColorRestore(g, i);
							  L.set(minIndex,tmp);
							  ColorNodehigh(g, minIndex, "minIndex");
						  }
						  PevotRestore(g, i);
					  }
					  
				  }

	}

	protected: void Quicksort(int high, int low,PaintEventArgs^ g )
	{

				   if (low > high)
					   return;
				   else
				   {

					   int p = low;
					   int i = low; int j = high;
					   if (i <= j)
					   {
						   ColorNodehigh(g, i, "Low");
						   ColorNodehigh(g, j, "High");
						   ColorNodelow(g, p, "Pevot");
					   }
					   while (i <= j)
					   {

						   if (L.get(j) <= L.get(p) && L.get(i) > L.get(p))
						   {
							   ColorRestore(g, j);
							   ColorRestore(g, i);
							   int temp = L.get(j);
							   L.set(j, L.get(i));
							   L.set(i, temp);
						   }
						   if (L.get(i) <= L.get(p))
						   {
							   if (i < j){
								   ColorRestore(g, i);
								   i++;
								   ColorNodehigh(g, i, "low");
								   Sleep(sleep);
							   }
							   else break;
						   }
							   
						   if (L.get(j) > L.get(p))
						   {
							   if (i < j){
								   ColorRestore(g, j);
								   j--;
								   ColorNodehigh(g, j, "high");
								   Sleep(sleep);
							   }
							   else break;
						   }
					   }
					   
					   if (L.get(p) > L.get(j))
					   {
						   
						   int temp = L.get(p);
						   L.set(p, L.get(j));
						   L.set(j, temp);
						   j++;
					   }
					   PevotRestore(g,p);
					   if (L.mySize>j && j>=0)
						   ColorRestore(g, j);
					   if (L.mySize>i && i>=0)
					   ColorRestore(g, i);
					   Quicksort(j - 1, low,g);
					   if (j+1 > high)
						   return;
					   Quicksort(high, j,g);
				   }
	}
	protected: void drawNode(PaintEventArgs^ e, int iterator, int x, int y, int prevx, int prevy, int adder)
	{
				   if (prevx != -1)
				   {
					   Pen^ p = gcnew Pen(Color::CadetBlue, 3.0f);

					   Point p1, p2;
					   p1.X = x + 25;
					   p1.Y = y + 25;
					   p2.X = prevx + 25;
					   p2.Y = prevy + 25;
					   e->Graphics->DrawLine(p, p1, p2);
					   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), prevx, prevy, 50, 50);
					   RectangleF rec = RectangleF(prevx + 15, prevy + 15, 50, 50);
					   e->Graphics->DrawString(gcnew String(to_string(L.get(iterator - 1)).c_str()),
						   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
						   rec);
					   rec = RectangleF(prevx + 20, prevy - 11, 50, 50);
					   e->Graphics->DrawString(gcnew String(to_string(iterator-1).c_str()),
						   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
						   rec);
				   }
				   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), x, y, 50, 50);
				   RectangleF rec = RectangleF(x + 15, y + 15, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(L.get(iterator)).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
					   rec);
				   rec = RectangleF(x + 20, y - 11, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(iterator ).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
				   L.getn(iterator)->nodePosition.x = x;
				   L.getn(iterator)->nodePosition.y = y;
				   iterator = iterator + 1;
				   if (iterator < L.mySize)
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
	protected: void ColorNodehigh(PaintEventArgs^ e, int node,string l)
	{
				   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow), L.getn(node)->nodePosition.x, L.getn(node)->nodePosition.y, 50, 50);
				   RectangleF rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y + 20, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(L.get(node)).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
				   rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y - 25, 50, 50);
				   e->Graphics->DrawString(gcnew String(l.c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
	}
			   void ColorRestore(PaintEventArgs^ e, int node)
			   {
				   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), L.getn(node)->nodePosition.x, L.getn(node)->nodePosition.y, 50, 50);
				   RectangleF rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y + 20, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(L.get(node)).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
				   rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y - 25, 50, 50);
				   e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(Form::BackColor),
					   L.getn(node)->nodePosition.x + 20,
					   L.getn(node)->nodePosition.y - 25,
						60,15);
			   }
			   void PevotRestore(PaintEventArgs^ e, int node)
			   {
					RectangleF rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y - 25, 50, 50);
				   e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(Form::BackColor),
					   L.getn(node)->nodePosition.x + 20,
					   L.getn(node)->nodePosition.y + 55,
					   60, 15);
			   }
	protected: void ColorNodelow(PaintEventArgs^ e, int node,string l)
	{
				   e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), L.getn(node)->nodePosition.x, L.getn(node)->nodePosition.y, 50, 50);
				   RectangleF rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y + 20, 50, 50);
				   e->Graphics->DrawString(gcnew String(to_string(L.get(node)).c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);
				   rec = RectangleF(L.getn(node)->nodePosition.x + 20, L.getn(node)->nodePosition.y +55, 50, 50);
				   e->Graphics->DrawString(gcnew String(l.c_str()),
					   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					   rec);

	}
			   protected:void BS(PaintEventArgs^ e, int low, int high, int key)
			   {

							 if (low > high)
							 {
								 return ;
							 }
							 int index = (high + low) / 2;
							 e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red), (L.getn(index)->nodePosition.x), 
								 (L.getn(index)->nodePosition.y), 50, 50);
							 RectangleF rec = RectangleF((L.getn(index)->nodePosition.x) + 15, (L.getn(index)->nodePosition.y) + 15, 50, 50);
							 e->Graphics->DrawString(gcnew String(to_string(L.get(index)).c_str()),
								 this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
								 rec);

							 if (L.get(index) == key)
							 {
								 MessageBox::Show("Found at "+index);
								 e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), (L.getn(index)->nodePosition.x),
									 (L.getn(index)->nodePosition.y), 50, 50);
								 RectangleF rec = RectangleF((L.getn(index)->nodePosition.x) + 15, (L.getn(index)->nodePosition.y) + 15, 50, 50);
								 e->Graphics->DrawString(gcnew String(to_string(L.get(index)).c_str()),
									 this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
									 rec);
							 }
							 else
							 {
								 if (L.get(index) > key)
								 {
									 Sleep(1000);
									 e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), (L.getn(index)->nodePosition.x),
										 (L.getn(index)->nodePosition.y), 50, 50);
									 RectangleF rec = RectangleF((L.getn(index)->nodePosition.x) + 15, (L.getn(index)->nodePosition.y) + 15, 50, 50);
									 e->Graphics->DrawString(gcnew String(to_string(L.get(index)).c_str()),
										 this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
										 rec);
									 BS(e, low, index - 1, key);

								 }
								 else
								 {
									 Sleep(1000);
									 e->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::CadetBlue), (L.getn(index)->nodePosition.x),
										 (L.getn(index)->nodePosition.y), 50, 50);
									 RectangleF rec = RectangleF((L.getn(index)->nodePosition.x) + 15, (L.getn(index)->nodePosition.y) + 15, 50, 50);
									 e->Graphics->DrawString(gcnew String(to_string(L.get(index)).c_str()),
										 this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
										 rec);
									 BS(e, index + 1, high, key);
								 }
							 }
			   }
	protected: void OnPaint(PaintEventArgs^ e)  override
	{
				   String ^ s = comboBox1->Text;

				   if (!L.empty())
					   drawNode(e, 0, 110, 100, -1, -1, 100);
				   if (sort == 2)
				   {
					   //MessageBox::Show("check your inputss!!");
					   string s2 = msclr::interop::marshal_as<string>(this->textBox5->Text);
					   BS(e, 0, L.mySize - 1, stoi(s2));
					   sort = 1;
				   }
				   if (sort == 3&&!L.empty())
				   {

					   if (s == L"Quick")
					   {
						   Quicksort( L.mySize - 1,0, e);
						   drawNode(e, 0, 110, 100, -1, -1, 100);

					   }
					   else if (s == L"Selection")
					   {
						   selectionSort(e);
						   drawNode(e, 0, 110, 100, -1, -1, 100);
					   }
					   else if (s == L"Insertion ")
					   {
						   InsertionSort(e);
						   drawNode(e, 0, 110, 100, -1, -1, 100);
					   }
					   else
					   {
						   mergesort(e, 0, L.mySize - 1);
						   drawNode(e, 0, 110, 100, -1, -1, 100);
					   }
					   sorted = true;
					   sort = 1;
				   }
				   
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateLinkedList()
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button3;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Insert";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreateLinkedList::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(226, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(61, 43);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CreateLinkedList::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(78, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(68, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(92, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Value";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(166, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Index";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(152, 35);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(68, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(307, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Index";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(293, 35);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(68, 20);
			this->textBox4->TabIndex = 6;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Insertion ", L"Selection", L"Quick", L"Merge" });
			this->comboBox1->Location = System::Drawing::Point(563, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(594, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Sort Type";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(496, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 43);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Sort";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CreateLinkedList::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1216, 660);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 50);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Back to Main";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &CreateLinkedList::button4_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1164, 10);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(94, 46);
			this->button6->TabIndex = 16;
			this->button6->Text = L"Random Generation";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &CreateLinkedList::button6_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1264, 35);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1270, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Number of nodes";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(438, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Value";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(422, 35);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(68, 20);
			this->textBox5->TabIndex = 20;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(367, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(49, 43);
			this->button5->TabIndex = 19;
			this->button5->Text = L"BinarySearch";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &CreateLinkedList::button5_Click);
			// 
			// CreateLinkedList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 356);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"CreateLinkedList";
			this->Text = L"Linked List";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 string s1 = msclr::interop::marshal_as<string>(this->textBox1->Text);
				 string s2 = msclr::interop::marshal_as<string>(this->textBox2->Text);
				 try
				 {
					 exception e;
					 for (int i = 0; i < s2.size(); i++)
					 if (s2[i]>'9' || s2[i]<'0' && s2[i] != '-')
						 throw  e;
					 for (int i = 0; i < s1.size(); i++)
					 if (s1[i]>'9' || s1[i]<'0' && s1[i] != '-')
						 throw  e;
					 sorted = false;
					 L.insert(stoi(s1 ), stoi(s2));
					 Invalidate();
				 }
				 catch (exception e){
					 MessageBox::Show("check your input!!");
					 return;
				 }
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 string s2 = msclr::interop::marshal_as<string>(this->textBox4->Text);
				 try
				 {
					 exception e;
					 for (int i = 0; i < s2.size(); i++)
					 if (s2[i]>'9' || s2[i]<'0' && s2[i] != '-')
						 throw  e;
					 sorted = false;
					 L.erase(stoi(s2));
					 Invalidate();
				 }
				 catch (exception e){ 
					 MessageBox::Show("check your input!!");
					 return; }
	}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^ s =comboBox1->Text;
			 if (sorted)
			 {
				 MessageBox::Show("Array  is  Already sorted");
				 return;
			 }
			 try{
			 sort = 3;
			 Invalidate();
			 
			 
			 }
			 catch (exception e){
				 MessageBox::Show("check your input!!");
				 return;
			 }
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 string s2 = msclr::interop::marshal_as<string>(this->textBox3->Text);
			 try
			 {
				 if (78 < L.mySize+stoi(s2)){
					 MessageBox::Show("Maximum 78 nodes");
					 return;
				 }
				 exception e;
				 for (int i = 0; i < s2.size(); i++)
				 if (s2[i]>'9' || s2[i]<'0' )
					 throw  e;
				 for (int i = 0; i < stoi(s2); i++)
				 {
					 sorted = false;
					 int x = (rand() + time(0)) % 1000;
					 L.insert(x, 0);
					 Invalidate();
				 }
			 }
			 catch (exception e){
				 MessageBox::Show("check your input!!");
				 return;
			 }
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (!sorted)
			 {
				 MessageBox::Show("sort first!!");
				 return;
			 }
			 try
			 {
				 string s2 = msclr::interop::marshal_as<string>(this->textBox5->Text);
				 exception e;
				 for (int i = 0; i < s2.size(); i++)
					 if (s2[i]>'9' || s2[i] < '0' && s2[i] != '-')
					 {
						 throw  e;
					 }
				 MessageBox::Show("AR!!");
				 sort = 2;
				 
				 	 Invalidate();
					 
			 }
			 catch (exception e){
				 MessageBox::Show("check your input!!");
				 return;
			 }
}
};
}
