#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Check_str.h"
# define NO_OF_CHARS 256

struct Client : Check_str
{
	std::string driver_license_number;    //номер водительского удостоверения
	std::string name;
	std::string passport;
	std::string adress;

	Client() : driver_license_number(""), name(""), passport(""),
		adress("") {};

	Client(std::string driver_license_number, std::string name, std::string passport, std::string adress)
	{
		this->driver_license_number = driver_license_number;
		this->name = name;
		this->passport = passport;
		this->adress = adress;
	}

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
		std::cout << "	Данные о клиенте:" << std::endl << std::endl;
		object.driver_license_number = input_driver_license_number();
		object.name = input_name();
		object.passport = input_passport();
		object.adress = input_adress();
		std::cout << std::endl;
		return object;
	}
	void output(Client object)
	{
		std::cout << "  Данные о клиенте:" << std::endl;
		std::cout << "Номер водительского удостоверения: "; std::cout << object.driver_license_number << std::endl;
		std::cout << "ФИО:   "; std::cout << object.name << std::endl;
		std::cout << "Паспорт:   "; std::cout << object.passport << std::endl;
		std::cout << "Адрес:   "; std::cout << object.adress << std::endl << std::endl;
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
	Node* remove(Node* p, std::string driver_license_number);
	Node* find_min(Node* p);
	Node* delete_min(Node* p);
	Client searchBy_driver_license(Node* root, std::string driver_license_number);
	void searchByName(Node* p, std::string name);
	void searchByAdress(Node* p, std::string adress);
	void print_postfix(Node* p);
	std::string delete_space(std::string str);
	bool boyer_moore(std::string a_to, std::string pat);
	void clear(Node* root);
public:
	Tree();
	~Tree();
	void put(Client data);
	void print_tree();
	void remove(std::string driver_license_number);
	Client searchBy_driver_license(std::string driver_license_number);
	void search_name(std::string driver_license_number);
	void searchByName(std::string name);
	void searchByAdress(std::string adress);
	void print_postfix();
	bool search(std::string driver_license_number); 
	void clear();
};
