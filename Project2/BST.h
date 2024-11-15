#include <iostream>
#include <windows.h>
#include <fstream>
#include <limits.h>
using namespace std;
class BST
{
public:
	template <class Archive>
	void serialize(Archive & ar)
	{
		for (int i = 0; i < nodes.size(); i++)
			ar(nodes[i]);
		ar(nodes);
	}
	struct Point
	{
		int x;
		int y;
	};
	class Node
	{
	public:
		Node(int value)
		{
			data = value;
			left = NULL;
			right = NULL;
		}
		Point p;
		Node* left;
		Node* right;
		int data;
	};
	Node* root;
	typedef Node* NodePointer;
public:
	vector<NodePointer> nodes;
	vector<int*> points;
	vector<int> dataOfNodes;
	BST()
	{
		root = NULL;
	}
	void Clear(NodePointer N)
	{
		/*NodePointer n = N;
		if (n->left != NULL)
			Clear(n->left);
		if (n->right != NULL)
			Clear(n->right);
		delete n;
		*N = NULL;*/
		delete root;
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void insert(int);
};
