#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "Check_str.h"

using namespace std;

struct Client : Check_str
{
	std::string driver_license_number;    //номер водительского удостоверения
	std::string name;
	string passport;
	string adress;

	bool operator > (Client obj)
	{
		return this->driver_license_number > obj.driver_license_number ? true : false;
	}
	bool operator < (Client obj)
	{
		return this->driver_license_number < obj.driver_license_number ? true : false;
	}
	bool operator == (Client obj)
	{
		return this->driver_license_number == obj.driver_license_number ? true : false;
	}
	Client input()
	{
		Client object;
		std::cout << "	Данные о выдаче на прокат или возврате автомобилей от клиентов:" << std::endl << std::endl;
		object.driver_license_number = input_driver_license_number();
		std::cout << "Имя:   ";
		std::cin >> object.name;
		std::cout << "Паспорт:   ";
		std::cin >> object.passport;
		std::cout << "Адрес:   ";
		std::cin >> object.adress;
		return object;
	}
};

struct Node
{
	Client data;
	Node* left, * right;
	int height = 1;
};

class Tree
{
private:
	Node* root;
	int height(Node* p);
	void fixheight(Node* p);
	Node* right_rotate(Node* p);
	Node* left_rotate(Node* q);
	Node* balance(Node* p);
	int balancefactor(Node* p);
	Node* add(Node*& Root, Client data);
	void print_tree(Node* Root, int indent);
public:
	Tree();
	//static Client input();
	void put(Client data);
	void print_tree();
};



//int height(Tree* p);
//int balancefactor(Tree* p);
//void fixheight(Tree* p);
//Tree* right_rotate(Tree* p);
//Tree* left_rotate(Tree* q);
//Tree* balance(Tree* p);
//Tree* add(Tree*& Root, int data);
//void print_tree(Tree* Root, int indent);
//Tree* search(Tree* root, int value, int k);
//void print_child(Tree* R, Tree* parent);
//void print_parent(Tree* parent);
//void prev(Tree* R);
//Tree* find_min(Tree* p);
//Tree* delete_min(Tree* p);
//Tree* remove(Tree* p, int value);
//int Check_str(string st);
//void print_postfix(Tree* p);
//
//int height(Tree* p)
//{
//	if (p != NULL)
//		return p->height;
//	else
//		return 0;
//}
////разность высот левого и правого поддеревьев
//
//int balancefactor(Tree* p)
//{
//	return height(p->right) - height(p->left);
//}
////восстанавливает корректное значение поля height заданного узла
//void fixheight(Tree* p)
//{
//	int height_left = height(p->left);
//	int height_right = height(p->right);
//	if (height_left > height_right)
//		p->height = height_left + 1;
//	else p->height = height_right + 1;
//}
//
//Tree* right_rotate(Tree* p)
//{
//	Tree* q = p->left;
//	p->left = q->right;
//	q->right = p;
//	fixheight(p);
//	fixheight(q);
//	return q;
//}
//
//Tree* left_rotate(Tree* q)
//{
//	Tree* p = q->right;
//	q->right = p->left;
//	p->left = q;
//	fixheight(q);
//	fixheight(p);
//	return p;
//}
//
//Tree* balance(Tree* p)
//{
//	fixheight(p);
//	if (balancefactor(p) == 2)
//	{
//		if (balancefactor(p->right) < 0)
//			p->right = right_rotate(p->right);
//		return left_rotate(p);
//	}
//	if (balancefactor(p) == -2)
//	{
//		if (balancefactor(p->left) > 0)
//			p->left = left_rotate(p->left);
//		return right_rotate(p);
//	}
//	return p;
//}
//
//Tree* add(Tree*& Root, int data)
//{
//	if (Root == NULL)
//	{
//		Tree* root = new Tree{ data, NULL, NULL };
//		Root = root;
//		return Root;
//	}
//	if (data < Root->data)
//		add(Root->left, data);
//	else
//		add(Root->right, data);
//	Root = balance(Root);
//}
//
//void print_tree(Tree* Root, int indent)
//{
//	if (!Root)
//		return;
//	indent += 5;//счетчик отступов
//	print_tree(Root->right, indent);
//	for (int i = 0; i < indent; i++)
//		cout << " ";
//	cout << Root->data << endl;
//	print_tree(Root->left, indent);
//	indent -= 5;
//	return;
//}
//
//Tree* search(Tree* root, int value, int k)
//{
//	Tree* curr = root;
//	while (curr)
//	{
//		if (value == curr->data)
//		{
//			cout << "Кол-во шагов: " << k++ << endl;
//			return (curr);
//		}
//		k++;
//		if (value < curr->data)
//			curr = curr->left;
//		else
//			curr = curr->right;
//	}
//	return (0);
//}
//
//
//void print_child(Tree* child, Tree* parent)
//{
//	if (child == NULL || child == parent)
//		return;
//	print_child(child->left, parent);
//	print_child(child->right, parent);
//	cout << child->data << " ";
//}
//
//void print_parent(Tree* parent)
//{
//	cout << "Родитель: " << parent->data << "; Потомки: ";
//	if (parent->left != NULL)
//	{
//		Tree* child = parent->left;
//		print_child(child, parent);
//	}
//	if (parent->right != NULL)
//	{
//		Tree* child = parent->right;
//		print_child(child, parent);
//	}
//	cout << endl;
//}
//
//void prev(Tree* R)
//{
//	if (R == NULL || (R->left == NULL && R->right == NULL))
//		return;
//	prev(R->left);
//	prev(R->right);
//	print_parent(R);
//}
//
//
//Tree* find_min(Tree* p)
//{
//	if (p->left == NULL)
//		return p;
//	else
//		find_min(p->left);
//}
//
//Tree* delete_min(Tree* p)
//{
//	if (p->left == NULL)
//		return p->right;
//	p->left = delete_min(p->left);
//	return balance(p);
//}
//
//Tree* remove(Tree* p, int value)
//{
//	if (p == NULL)
//		return 0;
//	if (value < p->data)
//		p->left = remove(p->left, value);
//	else if (value > p->data)
//		p->right = remove(p->right, value);
//	else
//	{
//		Tree* left = p->left;
//		Tree* right = p->right;
//		delete p;
//		if (right == NULL)
//			return left;
//		Tree* min = find_min(right);
//		min->right = delete_min(right);
//		min->left = left;
//		return balance(min);
//	}
//	return balance(p);
//}
//
//int Check_str(string st) //проверка на строку
//{
//	int var;
//	cout << st;
//	cin >> var;
//	while (cin.fail() || cin.get() != '\n')
//	{
//		cin.clear();
//		cin.ignore(cin.rdbuf()->in_avail(), '\n');
//		cout << "Неправильно введено, вводить можно только числа!: ";
//		cin >> var;
//	}
//	return var;
//}
//
//void print_postfix(Tree* p)
//{
//	if (p == NULL)
//		return;
//	print_postfix(p->left);
//	print_postfix(p->right);
//	cout << p->data << " ";
//}


