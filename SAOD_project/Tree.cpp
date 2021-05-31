#include "Tree.h"

Tree::Tree()
{
	this->root = NULL;
}

Tree::~Tree()
{
	clear();
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
		std::cout << " ";
	std::cout << Root->data.name << std::endl;
	print_tree(Root->left, indent);
	indent -= 5;
	return;
}

void Tree::put(Client data)
{
	Client elem;
	elem = searchBy_driver_license(root, data.driver_license_number);
	if (elem.driver_license_number == "")
		root = add(root, data);
	else
	{
		while (elem.driver_license_number != "")
		{
			std::cout << "  Клиент с таким номером водительского удостоверения уже есть в базе!\n";
			data = data.input();
			elem = searchBy_driver_license(root, data.driver_license_number);
		}
		root = add(root, data);
	}
}

void Tree::print_tree()
{
	print_tree(root, 0);
}

Node* Tree::find_min(Node* p)
{
	if (p->left == NULL)
		return p;
	else
		find_min(p->left);
}

Node* Tree::delete_min(Node* p)
{
	if (p->left == NULL)
		return p->right;
	p->left = delete_min(p->left);
	return balance(p);
}

Node* Tree::remove(Node* p, std::string driver_license_number)
{
	if (p == NULL)
		return 0;
	if (driver_license_number < p->data.driver_license_number)
		p->left = remove(p->left, driver_license_number);
	else if (driver_license_number > p->data.driver_license_number)
		p->right = remove(p->right, driver_license_number);
	else
	{
		Node* left = p->left;
		Node* right = p->right;
		delete p;
		if (right == NULL)
			return left;
		Node* min = find_min(right);
		min->right = delete_min(right);
		min->left = left;
		return balance(min);
	}
	return balance(p);
}

void Tree::remove(std::string driver_license_number)
{	
	if (root == NULL)
	{
		std::cout << "Список клиентов пуст!\n";
	}
	else
		root = remove(root, driver_license_number);
}

Client Tree::searchBy_driver_license(Node* root, std::string driver_license_number)
{
	Node* curr = root;
	Client element;
	while (curr)
	{
		if (driver_license_number == curr->data.driver_license_number)
		{
			element = curr->data;
			return element;
		}
		if (driver_license_number < curr->data.driver_license_number)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return element;
}

bool Tree::search(std::string driver_license_number)
{
	Client element = searchBy_driver_license(root, driver_license_number);
	if (element.driver_license_number != "") {
		return true;
	}
	else
		return false;
}

Client Tree::searchBy_driver_license(std::string driver_license_number)
{
	Client element = searchBy_driver_license(root, driver_license_number);
	if (element.driver_license_number != "") {
		element.output(element);
	}
	return element;
}

void Tree::search_name(std::string driver_license_number) 
{
	Client element = searchBy_driver_license(root, driver_license_number);
	if (element.driver_license_number != "")
		std::cout << "ФИО: " << element.name << std::endl << std::endl << std::endl;
	else
		std::cout << "Клиента с таким водительским удостоверением отсутствует!\n\n\n";
}

std::string Tree::delete_space(std::string str)
{
	std::string new_str = "";
	for (char elem : str)
	{
		if (elem != ' ')
			new_str += elem;
	}
	return new_str;
}

void Tree::searchByName(Node* p, std::string name) //postfix
{
	if (p == NULL)
		return;
	searchByName(p->left, name);
	searchByName(p->right, name);
	if (p->data.name == name || boyer_moore(p->data.name, name) == 1)
	{
		Client elem;
		elem.output(p->data);
	}
}

void Tree::searchByName(std::string name)
{
	searchByName(root, name);
}

void Tree::searchByAdress(Node* p, std::string adress)
{
	if (p == NULL)
		return;
	searchByAdress(p->left, adress);
	searchByAdress(p->right, adress);
	if (p->data.adress == adress || boyer_moore(p->data.adress, adress) == 1)
	{
		Client elem;
		elem.output(p->data);
	}
}

void Tree::searchByAdress(std::string adress)
{
	searchByAdress(root, adress);
}

bool Tree::boyer_moore(std::string a_to, std::string pat)
{
	int table[256];

	int size_a = a_to.size();
	int size_pat = pat.size();

	if (size_a >= size_pat)
	{
		for (int i = 0; i < 256; i++)
			table[i] = size_pat;

		for (int i = 0; i < size_pat; i++)
			table[abs((int)pat.at(i))] = i;

		int s = 0;
		while (s <= (size_a - size_pat))
		{
			int j = size_pat - 1;

			while (j >= 0 && (a_to.at(s + j) == pat.at(j)))
				j--;

			if (j < 0)
				return true;
			s += std::max(1, j - table[abs((int)a_to.at(s + j))]);
		}
	}
	return false;
}


void Tree::print_postfix(Node* p)
{
	Client client;
	if (p == NULL)
		return;
	print_postfix(p->left);
	print_postfix(p->right);
	client.output(p->data);
}

void Tree::print_postfix()
{
	std::cout << "  Клиенты:\n";
	print_postfix(root);
	std::cout << std::endl << std::endl;
}

void Tree::clear(Node* root)
{
	if (root != nullptr) {
		clear(root->left);
		clear(root->right);
		delete root;
	}
}

void Tree::clear()
{
	clear(this->root);
	this->root = nullptr;
}