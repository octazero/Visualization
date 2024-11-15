#pragma once

#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <cereal\types\vector.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <limits.h>
#include "BST.h"
using namespace std;

static BST::NodePointer newNode;
static BST::NodePointer parent;
static BST tree;
static int num;
//vector<BST :: NodePointer> nodes(0);
//vector<int> dataOfNodes(0);
//vector<int*> points(0);
//vector <BST::Point> points(0);


namespace Project2{
	
	static System::Drawing::Point p1, p2;
	static string s;
	static string l = "data";
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CreateBinaryTree : public System::Windows::Forms::Form
	{
	public:
		CreateBinaryTree(void)
		{
			num = -1;
			InitializeComponent();
		}
	protected:
		~CreateBinaryTree()
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button9;
	protected:

	private:
		System::ComponentModel::Container ^components;
		void inorder(BST::NodePointer p, PaintEventArgs^ g)
		{
			if (p != NULL)
			{
				inorder(p->left, g);
				g->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow), p->p.x, p->p.y, 50, 50);
				Sleep(1000);
				label1->Text += p->data.ToString() + " ";
				RectangleF rec = RectangleF(p->p.x + 20, p->p.y + 20, 50, 50);
				g->Graphics->DrawString(gcnew String(to_string(p->data).c_str()),
					this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					rec);
				inorder(p->right, g);
			}
			l = " ";
			//label1->Text = " ";
			if (p == NULL) return;
		}
		void preorder(BST::NodePointer p, PaintEventArgs^ g)
		{
			if (p != NULL)
			{
				g->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow), p->p.x, p->p.y, 50, 50);
				Sleep(1000);
				label1->Text += p->data.ToString() + " ";
				RectangleF rec = RectangleF(p->p.x + 20, p->p.y + 20, 50, 50);
				g->Graphics->DrawString(gcnew String(to_string(p->data).c_str()),
					this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					rec);
				preorder(p->left, g);
				preorder(p->right, g);
			}
			l = " ";
			//label1->Text = " ";
			if (p == NULL) return;
		}
		void postorder(BST::NodePointer p, PaintEventArgs^ g)
		{
			if (p != NULL)
			{
				postorder(p->left, g);
				postorder(p->right, g);
				g->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow), p->p.x, p->p.y, 50, 50);
				Sleep(1000);
				label1->Text += p->data.ToString() + " ";
				RectangleF rec = RectangleF(p->p.x + 20, p->p.y + 20, 50, 50);
				g->Graphics->DrawString(gcnew String(to_string(p->data).c_str()),
					this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					rec);
			}
			l = " ";
			//label1->Text = " ";
			if (p == NULL) return;
		}
		void draw(PaintEventArgs^ g, BST::Node* n1, BST::Node* n2)
		{
			if (!tree.isEmpty())
			{
				Pen^ p = gcnew Pen(Color::Black, 2.0f);

				if (n1 != NULL)
				{
					p1.X = n1->p.x; p1.Y = n1->p.y;
					p2.X = n2->p.x; p2.Y = n2->p.y;
				}
				/*int * arr;
				arr = new int[4];

				p1.X += 25; p1.Y += 25;
				p2.X += 10; p2.Y += 10;

				if (n1 != NULL && n2 != NULL)
				{
				//g->Graphics->DrawLine(p, p1, p2);
				arr[0] = p1.X;
				arr[1] = p1.Y;
				arr[2] = p2.X;
				arr[3] = p2.Y;
				tree.points.push_back(arr);
				}*/
			}
		}
		void DrawCircles(PaintEventArgs^ e, vector<BST::NodePointer> pins)
		{
			if (pins.size() >= 1)
			{
				int i = 0;
				while (i < pins.size())
				{
					reDraw(e, pins[i]);
					i++;
				}
			}
		}
		void reDraw(PaintEventArgs^ g, BST::Node* n2)
		{
			Pen^ p = gcnew Pen(Color::Black, 2.0f);
			if (n2->p.x != 0 && n2->p.y != 0)
			{
				g->Graphics->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::DeepSkyBlue), n2->p.x, n2->p.y, 50, 50);
				RectangleF rec = RectangleF(n2->p.x + 20, n2->p.y + 20, 50, 50);
				g->Graphics->DrawString(gcnew String(to_string(n2->data).c_str()),
					this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black),
					rec);
			}
		}
		void DrawLines(PaintEventArgs^ g, vector<int *> pointt)
		{
			int i = 0;
			try{
				Pen^ p = gcnew Pen(Color::Black, 2.0f);

				while (i < pointt.size())
				{
					p1.X = pointt[i][0];
					p1.Y = pointt[i][1];
					p2.X = pointt[i][2];
					p2.Y = pointt[i][3];
					g->Graphics->DrawLine(p, p1, p2);
					i++;
				}
			}
			catch (exception e)
			{

			};
		}
		protected: void drawRBtree(PaintEventArgs^ e, BST::Node *x, BST::Node *Parent, int low, int high, int height)
		{
					 
						   if (x != NULL)
						   {

							   x->p.x = (high + low) / 2;
							   x->p.y = (height);
							   SolidBrush^ S = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);

							   height = height + 100;
							   if (Parent != NULL)
							   {

								   Pen^ p = gcnew Pen(Color::Black, 3.0f);

								   Point p1, p2;
								   p1.X = x->p.x + 25;
								   p1.Y = x->p.y + 25;
								   p2.X = Parent->p.x + 25;
								   p2.Y = Parent->p.y + 25;
								   e->Graphics->DrawLine(p, p1, p2);

							   }
							   if (x->left != NULL)
							   {

								   drawRBtree(e, x->left,x, low, (high + low) / 2, height);
							   }
							   if (x->right != NULL)
							   {
								   drawRBtree(e, x->right,x, (high + low) / 2, high, height);
							   }
							   e->Graphics->FillEllipse(S, x->p.x, x->p.y, 50, 50);
							   RectangleF rec = RectangleF(x->p.x + 20, x->p.y + 20, 50, 50);
							   e->Graphics->DrawString(gcnew String(to_string(x->data).c_str()),
								   this->Font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
								   rec);
						   }
					   
		}


	protected: virtual void OnPaint(PaintEventArgs^ e)  override
	{
				   if (label1->Text == "in-order Nodes")
				   {
					   inorder(tree.root, e);
					   l = "in-order Nodes";
					   //label1->Text = " ";
					   return;
				   }
				   if (label1->Text == "pre-order Nodes")
				   {
					   preorder(tree.root, e);
					   l = "pre-order Nodes";
					   //label1->Text = " ";
					   return;
				   }
				   if (label1->Text == "post-order Nodes")
				   {
					   postorder(tree.root, e);
					   l = "post-order Nodes";
					   //label1->Text = " ";
					   return;
				   }

				   if (!tree.isEmpty())
				   {
					   drawRBtree(e, tree.root, NULL, 0, 1336,100);
					 /*  try{
						   draw(e, parent, newNode);
					   }
					   catch (exception e)
					   {
						   MessageBox::Show("Error Occurred");
					   };
					   try{

						   DrawLines(e, tree.points);
						   DrawCircles(e, tree.nodes);
					   }
					   catch (exception e)
					   {
						   MessageBox::Show("Error Occurred");
					   };*/
				   }
	}
#pragma region Windows Form Designer generated code
			   void InitializeComponent(void)
			   {
				   this->button1 = (gcnew System::Windows::Forms::Button());
				   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				   this->button2 = (gcnew System::Windows::Forms::Button());
				   this->button3 = (gcnew System::Windows::Forms::Button());
				   this->label1 = (gcnew System::Windows::Forms::Label());
				   this->button4 = (gcnew System::Windows::Forms::Button());
				   this->button5 = (gcnew System::Windows::Forms::Button());
				   this->button6 = (gcnew System::Windows::Forms::Button());
				   this->button7 = (gcnew System::Windows::Forms::Button());
				   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
				   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				   this->button8 = (gcnew System::Windows::Forms::Button());
				   this->label3 = (gcnew System::Windows::Forms::Label());
				   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				   this->button9 = (gcnew System::Windows::Forms::Button());
				   this->SuspendLayout();
				   // 
				   // button1
				   // 
				   this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
				   this->button1->Location = System::Drawing::Point(667, 16);
				   this->button1->Name = L"button1";
				   this->button1->Size = System::Drawing::Size(75, 37);
				   this->button1->TabIndex = 0;
				   this->button1->Text = L"Insert";
				   this->button1->UseVisualStyleBackColor = true;
				   this->button1->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button1_Click);
				   // 
				   // textBox1
				   // 
				   this->textBox1->Location = System::Drawing::Point(316, 18);
				   this->textBox1->Name = L"textBox1";
				   this->textBox1->Size = System::Drawing::Size(345, 20);
				   this->textBox1->TabIndex = 1;
				   this->textBox1->TextChanged += gcnew System::EventHandler(this, &CreateBinaryTree::textBox1_TextChanged);
				   // 
				   // button2
				   // 
				   this->button2->Location = System::Drawing::Point(748, 16);
				   this->button2->Name = L"button2";
				   this->button2->Size = System::Drawing::Size(75, 37);
				   this->button2->TabIndex = 2;
				   this->button2->Text = L"Clear all";
				   this->button2->UseVisualStyleBackColor = true;
				   this->button2->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button2_Click);
				   // 
				   // button3
				   // 
				   this->button3->Location = System::Drawing::Point(200, 9);
				   this->button3->Name = L"button3";
				   this->button3->Size = System::Drawing::Size(75, 37);
				   this->button3->TabIndex = 3;
				   this->button3->Text = L"In-Order";
				   this->button3->UseVisualStyleBackColor = true;
				   this->button3->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button3_Click);
				   // 
				   // label1
				   // 
				   this->label1->ForeColor = System::Drawing::SystemColors::Desktop;
				   this->label1->Location = System::Drawing::Point(25, 60);
				   this->label1->Name = L"label1";
				   this->label1->Size = System::Drawing::Size(268, 22);
				   this->label1->TabIndex = 4;
				   this->label1->Text = L" ";
				   this->label1->Click += gcnew System::EventHandler(this, &CreateBinaryTree::label1_Click);
				   // 
				   // button4
				   // 
				   this->button4->Location = System::Drawing::Point(38, 9);
				   this->button4->Name = L"button4";
				   this->button4->Size = System::Drawing::Size(75, 37);
				   this->button4->TabIndex = 5;
				   this->button4->Text = L"Pre-Order";
				   this->button4->UseVisualStyleBackColor = true;
				   this->button4->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button4_Click);
				   // 
				   // button5
				   // 
				   this->button5->Location = System::Drawing::Point(119, 9);
				   this->button5->Name = L"button5";
				   this->button5->Size = System::Drawing::Size(75, 37);
				   this->button5->TabIndex = 6;
				   this->button5->Text = L"Post-Order";
				   this->button5->UseVisualStyleBackColor = true;
				   this->button5->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button5_Click);
				   // 
				   // button6
				   // 
				   this->button6->Location = System::Drawing::Point(829, 16);
				   this->button6->Name = L"button6";
				   this->button6->Size = System::Drawing::Size(75, 37);
				   this->button6->TabIndex = 7;
				   this->button6->Text = L"Save";
				   this->button6->UseVisualStyleBackColor = true;
				   this->button6->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button6_Click);
				   // 
				   // button7
				   // 
				   this->button7->Location = System::Drawing::Point(910, 16);
				   this->button7->Name = L"button7";
				   this->button7->Size = System::Drawing::Size(75, 37);
				   this->button7->TabIndex = 8;
				   this->button7->Text = L"Load";
				   this->button7->UseVisualStyleBackColor = true;
				   this->button7->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button7_Click);
				   // 
				   // openFileDialog1
				   // 
				   this->openFileDialog1->FileName = L"openFileDialog1";
				   // 
				   // button8
				   // 
				   this->button8->Location = System::Drawing::Point(1216, 660);
				   this->button8->Name = L"button8";
				   this->button8->Size = System::Drawing::Size(150, 50);
				   this->button8->TabIndex = 9;
				   this->button8->Text = L"Back to Main";
				   this->button8->UseVisualStyleBackColor = true;
				   this->button8->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button8_Click);
				   // 
				   // label3
				   // 
				   this->label3->AutoSize = true;
				   this->label3->Location = System::Drawing::Point(1268, 11);
				   this->label3->Name = L"label3";
				   this->label3->Size = System::Drawing::Size(88, 13);
				   this->label3->TabIndex = 24;
				   this->label3->Text = L"Number of nodes";
				   // 
				   // textBox4
				   // 
				   this->textBox4->Location = System::Drawing::Point(1262, 35);
				   this->textBox4->Name = L"textBox4";
				   this->textBox4->Size = System::Drawing::Size(100, 20);
				   this->textBox4->TabIndex = 23;
				   // 
				   // button9
				   // 
				   this->button9->Location = System::Drawing::Point(1162, 9);
				   this->button9->Name = L"button9";
				   this->button9->Size = System::Drawing::Size(94, 46);
				   this->button9->TabIndex = 22;
				   this->button9->Text = L"Random Generation";
				   this->button9->UseVisualStyleBackColor = true;
				   this->button9->Click += gcnew System::EventHandler(this, &CreateBinaryTree::button9_Click);
				   // 
				   // CreateBinaryTree
				   // 
				   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				   this->BackColor = System::Drawing::SystemColors::Control;
				   this->ClientSize = System::Drawing::Size(1366, 746);
				   this->Controls->Add(this->label3);
				   this->Controls->Add(this->textBox4);
				   this->Controls->Add(this->button9);
				   this->Controls->Add(this->button8);
				   this->Controls->Add(this->button7);
				   this->Controls->Add(this->button6);
				   this->Controls->Add(this->button5);
				   this->Controls->Add(this->button4);
				   this->Controls->Add(this->label1);
				   this->Controls->Add(this->button3);
				   this->Controls->Add(this->button2);
				   this->Controls->Add(this->textBox1);
				   this->Controls->Add(this->button1);
				   this->ForeColor = System::Drawing::SystemColors::Desktop;
				   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				   this->Name = L"CreateBinaryTree";
				   this->ShowIcon = false;
				   this->Text = L"Binary Tree";
				   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				   this->ResumeLayout(false);
				   this->PerformLayout();

			   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^  e)
	{
				 if (num == -1){
					 s = msclr::interop::marshal_as<string>(this->textBox1->Text);

					 try
					 {
						 exception el;
						 for (int i = 0; i < s.size(); i++)
						 if (s[i]>'9' || s[i]<'0' && s[i] != '-')
							 throw  e;
						 num = stoi(s);
					 }
					 catch (exception e){
						 MessageBox::Show("check your input!!");
						 return;
					 }
				 }
				 if (tree.dataOfNodes.size() >= 1)
				 {
					 if (std::find(tree.dataOfNodes.begin(), tree.dataOfNodes.end(), num) != tree.dataOfNodes.end())
					 {
						 MessageBox::Show(num + " Already Exists in your Tree, Try Another one");
						 return;
					 }
				 }
				 newNode = new BST::Node(num);
				 tree.dataOfNodes.push_back(num);
				 tree.nodes.push_back(newNode);
				 parent = NULL;
				 if (tree.root == NULL)
				 {
					 tree.root = newNode;
					 tree.root->p.x = 650;
					 tree.root->p.y = 50;
				 }
				 else
				 {
					 BST::NodePointer current;
					 current = tree.root;
					 while (current)
					 {
						 parent = current;
						 if (newNode->data > current->data)
							 current = current->right;
						 else
							 current = current->left;
					 }
					 if (newNode->data < parent->data)
					 {
						 newNode->p.x = parent->p.x - parent->p.y;
						 newNode->p.y = parent->p.y + 80;
						 parent->left = newNode;
					 }
					 else if (newNode->data > parent->data)
					 {
						 newNode->p.x = parent->p.x + parent->p.y;
						 newNode->p.y = parent->p.y + 80;
						 parent->right = newNode;
					 }
					 int * arr;
					 arr = new int[4];
					 p1.X = newNode->p.x;
					 p1.Y = newNode->p.y;
					 p2.X = parent->p.x;
					 p2.Y = parent->p.y;
					 p1.X += 25; p1.Y += 25;
					 p2.X += 10; p2.Y += 10;
					 arr[0] = p1.X;
					 arr[1] = p1.Y;
					 arr[2] = p2.X;
					 arr[3] = p2.Y;
					 tree.points.push_back(arr);
				 }
				 num = -1;
				 Invalidate();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (tree.isEmpty() || tree.root->data == NULL)
					 MessageBox::Show("Tree is already Empty");
				 else
				 {
					 try
					 {
						 tree.Clear(tree.root);
						 tree.nodes.clear();
						 tree.dataOfNodes.clear();
						 tree.points.clear();
						 s.clear();
						 label1->Text = L"";
						 /*BST s;
						 tree = s;*/
						 Invalidate();
						 MessageBox::Show("Tree is Deleted");
						 //return;
					 }
					 catch (exception e)
					 {
						 MessageBox::Show("Error Occurred");
					 };
				 }
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 if ((s.size() == 0 && l == " ") || tree.isEmpty())
				 {
					 MessageBox::Show("Enter data first !");
					 return;
				 }
				 label1->Text = "in-order Nodes";
				 s.clear();
				 Invalidate();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 if ((s.size() == 0 && l == " ") || tree.isEmpty())
				 {
					 MessageBox::Show("Enter data first !");
					 return;
				 }
				 label1->Text = "post-order Nodes";
				 s.clear();
				 Invalidate();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if ((s.size() == 0 && l == " ") || tree.isEmpty())
				 {
					 MessageBox::Show("Enter data first !");
					 return;
				 }
				 label1->Text = "pre-order Nodes";
				 s.clear();
				 Invalidate();
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 int m;
					 string file = msclr::interop::marshal_as<string>(saveFileDialog1->FileName);
					 ofstream out;
					 out.open(file + ".cereal", ios::binary);
					 out << tree.dataOfNodes.size();
					 cereal::BinaryOutputArchive archive(out);
					 archive(tree.dataOfNodes);
					 out.close();
					 MessageBox::Show("AMR is a badass");
				 }
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 vector<BST::NodePointer> nod;
					 string file = msclr::interop::marshal_as<string>(openFileDialog1->FileName);
					 ifstream in;
					 int dataSize;
					 in.open(file, ios::binary);
					 in >> dataSize;
					 tree.dataOfNodes.resize(dataSize);
					 cereal::BinaryInputArchive archive(in);
					 archive(tree.dataOfNodes);
					 BST t = tree;
					 for (int i = 0; i < tree.dataOfNodes.size(); i++)
					 {
						 newNode = new BST::Node(tree.dataOfNodes[i]);
						 //tree.dataOfNodes.push_back(tree.dataOfNodes[i]);
						 tree.nodes.push_back(newNode);
						 parent = NULL;
						 if (tree.isEmpty())
						 {
							 tree.root = newNode;
							 tree.root->p.x = 650;
							 tree.root->p.y = 50;
						 }
						 else
						 {
							 int * arr;
							 arr = new int[4];
							 BST::NodePointer current;
							 current = tree.root;
							 while (current)
							 {
								 parent = current;
								 if (newNode->data > current->data)
									 current = current->right;
								 else
									 current = current->left;
							 }
							 if (newNode->data < parent->data)
							 {
								 newNode->p.x = parent->p.x - parent->p.y;
								 newNode->p.y = parent->p.y + 80;
								 parent->left = newNode;
							 }
							 else if (newNode->data > parent->data)
							 {
								 newNode->p.x = parent->p.x + parent->p.y;
								 newNode->p.y = parent->p.y + 80;
								 parent->right = newNode;
							 }
							 p1.X = newNode->p.x;
							 p1.Y = newNode->p.y;
							 p2.X = parent->p.x;
							 p2.Y = parent->p.y;
							 p1.X += 25; p1.Y += 25;
							 p2.X += 10; p2.Y += 10;
							 arr[0] = p1.X;
							 arr[1] = p1.Y;
							 arr[2] = p2.X;
							 arr[3] = p2.Y;
							 tree.points.push_back(arr);
						 }
						 t = tree;
					 }
					 in.close();
					 Invalidate();
					 /*nodes.resize(nod.size());
					 memcpy(&nodes.at(0), &nod.at(0), nod.size());
					 MessageBox::Show("AMR dh agmd wa7d fena");*/
				 }
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 string s4 = msclr::interop::marshal_as<string>(this->textBox4->Text);
			 try
			 {
				 if (20 < RB.counter + stoi(s4)){
					 MessageBox::Show("Maximum 20 nodes");
					 return;
				 }
				 exception el;
				 for (int i = 0; i < s4.size(); i++)
				 if (s4[i]>'9' || s4[i]<'0')
					 throw  el;
				 for (int i = 0; i < stoi(s4); i++)
				 {
					 int x = (rand() + time(0)) % 1000;
					 num = x;
					 button1_Click(sender, e);
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