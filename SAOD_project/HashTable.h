
#pragma once
#include <string>
#include <functional>
#include <iostream>
#include "Check_str.h"

struct Car : public Check_str
{
	std::string state_registration_number;//Государственный регистрационный номер
	std::string brand;
	std::string color;
	int year_of_release;
	bool available;						  // Признак наличия

	Car() : state_registration_number(""), brand(""), color(""),
		year_of_release(0), available(0) {};

	Car(std::string stRg_num, std::string brand, std::string color, int year_of_release, bool available)
	{
		this->state_registration_number = stRg_num;
		this->brand = brand;
		this->color = color;
		this->year_of_release = year_of_release;
		this->available = available;
	}

	bool operator >  (Car a)
	{
		return this->state_registration_number > a.state_registration_number ? true : false;
	}

	bool operator <  (Car a)
	{
		return this->state_registration_number < a.state_registration_number ? true : false;
	}

	bool operator == (Car a)
	{
		return this->state_registration_number == a.state_registration_number ? true : false;
	}

	Car input()
	{
		Car object;
		std::cout << "	Данные о авто:" << std::endl << std::endl;
		object.state_registration_number = input_state_registration_number();
		object.brand = input_brand();
		object.color = input_color();
		object.year_of_release = input_year_of_release();
		object.available = true;
		std::cout << std::endl;
		return object;
	}

	friend std::ostream& operator << (std::ostream& out, Car& a)
	{
		return out << "Государственный регистрационный номер: " << a.state_registration_number << std::endl <<
			"Марка: " << a.brand << std::endl << "Цвет: " << a.color << std::endl << "Год выпуска: " << a.year_of_release 
			<< std::endl << "Наличие: " << a.available << std::endl << std::endl << std::endl;
	}
};
//by @xin
class Pair
{
public:
	std::string key;
	Car data;

	Pair(std::string key, Car data)
	{
		this->data = data;
		this->key = key;
	};

	Pair()
	{
		this->data = Car();
		this->key = std::string();
	};

	bool operator==(Pair a)
	{
		return this->key == a.key ? true : false;
	}

	bool operator!=(Pair a)
	{
		return this->key != a.key ? true : false;
	}
};

class HashTable
{
private:

	int size; //размер таблицы
	int count;//кол-во элементов со значением
	Pair* arr;
	int c1 = 2, c2 = 3;

	int hashFun(std::string key);
	int collisionFix(int i, int n);
	bool isFree(int i);
	void resize();
	Pair pairByKey(std::string key);

public:
	HashTable();
	~HashTable();

	void clear();
	bool contains(std::string key);
	void add(std::string key, Car data);
	Car removeByKey(std::string key);
	Car& operator[](std::string key);
	void display();
	void findByBrand(std::string brand);
	Car findCarByKey(std::string key);
	void return_all_cars();
	int size_();
};
