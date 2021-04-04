#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
#include "Tree.h"

using namespace std;


int main()
{
	SetConsoleCP(1251); // ¬вод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);//вывод
	setlocale(LC_ALL, "RUS");
	Tree tree;
	Client elem;
	Node* root;
	for (int i = 0; i < 2; i++)
	{
		tree.put(elem.input());
		//tree.add(tree.root, elem.input());
	}
	tree.print_tree();
	/*list.output_list();
	list.sort();
	list.output_list();*/
	return 0;
}