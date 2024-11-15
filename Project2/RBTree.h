#pragma once
#include <stdio.h>
#include <tchar.h>

using namespace std;


class RBtree
{
public:
	struct Point
	{
		int x;
		int y;
	};
	struct node
	{
		int key;
		node *parent;
		char color;
		node *left;
		node *right;
		Point nodePosition;
	};
	node *root;
	node *q;

public:
	RBtree()
	{
		q = NULL;
		root = NULL;
	}

	void RBtree::insert(int z)
	{
		int i = 0;
		node *p, *q;
		node *t = new node;
		t->key = z;
		t->left = NULL;
		t->right = NULL;
		t->color = 'r';
		p = root;
		q = NULL;
		if (root == NULL)
		{
			root = t;
			t->parent = NULL;
		}
		else
		{
			while (p != NULL)
			{
				q = p;
				if (p->key < t->key)
					p = p->right;
				else
					p = p->left;
			}
			t->parent = q;
			if (q->key < t->key)
				q->right = t;
			else
				q->left = t;
		}
		insertfix(t);
	}
	void RBtree::insertfix(node *t)
	{
		node *u;
		if (root == t)
		{
			t->color = 'b';
			return;
		}
		if (t->parent != NULL&&t->parent->color == 'r')
		{
			if (t->parent->parent == NULL)
				return;
			node *g = t->parent->parent;
			if (g->left == t->parent)
			{
				if (g->right != NULL)
				{
					u = g->right;
					if (u->color == 'r')
					{
						t->parent->color = 'b';
						u->color = 'b';
						g->color = 'r';
						t = g;
					}
				}
				else
				{
					if (t->parent->right == t)
					{
						t = t->parent;
						leftrotate(t);
					}
					t->parent->color = 'b';
					g->color = 'r';
					rightrotate(g);
				}
			}
			else
			{
				if (g->left != NULL)
				{
					u = g->left;
					if (u->color == 'r')
					{
						t->parent->color = 'b';
						u->color = 'b';
						g->color = 'r';
						t = g;
					}
				}
				else
				{
					if (t->parent->left == t)
					{
						t = t->parent;
						rightrotate(t);
					}
					t->parent->color = 'b';
					g->color = 'r';
					leftrotate(g);
				}
			}
			root->color = 'b';
			if (t->parent == NULL)
				return;
			insertfix(t->parent);
		}
	}
	int RBtree::del(int x)
	{
		if (root == NULL)
		{

			return -1; //for empty
		}
		node *p;
		p = root;
		node *y = NULL;
		node *q = NULL;
		int found = 0;
		while (p != NULL&&found == 0)
		{
			if (p->key == x)
				found = 1;
			if (found == 0)
			{
				if (p->key < x)
					p = p->right;
				else
					p = p->left;
			}
		}
		if (found == 0)
		{
			return 0; //for not found
		}
		else
		{
			if (p->left == NULL || p->right == NULL)
				y = p;
			else
				y = successor(p);
			if (y->left != NULL)
				q = y->left;
			else
			{
				if (y->right != NULL)
					q = y->right;
				else
					q = NULL;
			}
			if (q != NULL)
				q->parent = y->parent;
			if (y->parent == NULL)
				root = q;
			else
			{
				if (y == y->parent->left)
					y->parent->left = q;
				else
					y->parent->right = q;
			}
			if (y != p)
			{
				p->color = y->color;
				p->key = y->key;
			}
			if (y->color == 'b')
				delfix(q);
		}
	}

	void RBtree::delfix(node *p)
	{
		node *s;
		while (p != root&&p->color == 'b')
		{
			if (p->parent->left == p)
			{
				s = p->parent->right;
				if (s->color == 'r')
				{
					s->color = 'b';
					p->parent->color = 'r';
					leftrotate(p->parent);
					s = p->parent->right;
				}
				if (s->right->color == 'b'&&s->left->color == 'b')
				{
					s->color = 'r';
					p = p->parent;
				}
				else
				{
					if (s->right->color == 'b')
					{
						s->left->color == 'b';
						s->color = 'r';
						rightrotate(s);
						s = p->parent->right;
					}
					s->color = p->parent->color;
					p->parent->color = 'b';
					s->right->color = 'b';
					leftrotate(p->parent);
					p = root;
				}
			}
			else
			{
				s = p->parent->left;
				if (s->color == 'r')
				{
					s->color = 'b';
					p->parent->color = 'r';
					rightrotate(p->parent);
					s = p->parent->left;
				}
				if (s->left->color == 'b'&&s->right->color == 'b')
				{
					s->color = 'r';
					p = p->parent;
				}
				else
				{
					if (s->left->color == 'b')
					{
						s->right->color = 'b';
						s->color = 'r';
						leftrotate(s);
						s = p->parent->left;
					}
					s->color = p->parent->color;
					p->parent->color = 'b';
					s->left->color = 'b';
					rightrotate(p->parent);
					p = root;
				}
			}
			p->color = 'b';
			root->color = 'b';
		}
	}
	void RBtree::leftrotate(node *p)
	{
		if (p->right == NULL)
			return;
		else
		{
			node *y = p->right;
			if (y->left != NULL)
			{
				p->right = y->left;
				y->left->parent = p;
			}
			else
				p->right = NULL;
			if (p->parent != NULL)
				y->parent = p->parent;
			if (p->parent == NULL)
				root = y;
			else
			{
				if (p == p->parent->left)
					p->parent->left = y;
				else
					p->parent->right = y;
			}
			y->left = p;
			p->parent = y;
		}
	}
	void RBtree::rightrotate(node *p)
	{
		if (p->left == NULL)
			return;
		else
		{
			node *y = p->left;
			if (y->right != NULL)
			{
				p->left = y->right;
				y->right->parent = p;
			}
			else
				p->left = NULL;
			if (p->parent != NULL)
				y->parent = p->parent;
			if (p->parent == NULL)
				root = y;
			else
			{
				if (p == p->parent->left)
					p->parent->left = y;
				else
					p->parent->right = y;
			}
			y->right = p;
			p->parent = y;
		}
	}

	node* RBtree::successor(node *p)
	{
		node *y = NULL;
		if (p->left != NULL)
		{
			y = p->left;
			while (y->right != NULL)
				y = y->right;
		}
		else
		{
			y = p->right;
			while (y->left != NULL)
				y = y->left;
		}
		return y;
	}
	Point RBtree::search(int x)
	{
		if (root == NULL)
		{
			return Point();
		}

		node *p = root;
		int found = 0;
		while (p != NULL&& found == 0)
		{
			if (p->key == x)
				found = 1;
			if (found == 0)
			{
				if (p->key < x)
					p = p->right;
				else
					p = p->left;
			}
		}
		if (found == 0)
			return Point();
		else
		{
			p->nodePosition;
		}
	}
};