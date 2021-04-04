#include "Tree.h"

Tree::Tree()
{
	this->root = NULL;
}

int Tree::height(Node* p)
{
	if (p != NULL)
		return p->height;
	else
		return 0;
}

int Tree::balancefactor(Node* p)
{
	return height(p->right) - height(p->left);
}

void Tree::fixheight(Node* p)
{
	int height_left = height(p->left);
	int height_right = height(p->right);
	if (height_left > height_right)
		p->height = height_left + 1;
	else p->height = height_right + 1;
}

Node* Tree::right_rotate(Node* p)
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

Node* Tree::left_rotate(Node* q)
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

Node* Tree::balance(Node* p)
{
	fixheight(p);
	if (balancefactor(p) == 2)
	{
		if (balancefactor(p->right) < 0)
			p->right = right_rotate(p->right);
		return left_rotate(p);
	}
	if (balancefactor(p) == -2)
	{
		if (balancefactor(p->left) > 0)
			p->left = left_rotate(p->left);
		return right_rotate(p);
	}
	return p;
}

Node* Tree::add(Node*& Root, Client data)
{
	if (Root == NULL)
	{
		Node* root = new Node{ data, NULL, NULL };
		Root = root;
		return Root;
	}
	if (data < Root->data)
		add(Root->left, data);
	else
		add(Root->right, data);
	Root = balance(Root);
	return Root;
}

void Tree::print_tree(Node* Root, int indent)
{
	if (!Root)
		return;
	indent += 5;//счетчик отступов
	print_tree(Root->right, indent);
	for (int i = 0; i < indent; i++)
		cout << " ";
	cout << Root->data.name << endl;
	print_tree(Root->left, indent);
	indent -= 5;
	return;
}

void Tree::put(Client data)
{
	root = add(root, data);
}

void Tree::print_tree()
{
	print_tree(root, 0);
}