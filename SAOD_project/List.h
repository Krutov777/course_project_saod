#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Check_str.h"

struct Car_rental_status
{
	std::string driver_license_number;    //номер водительского удостоверения
	std::string state_registration_number;//Государственный регистрационный номер
	std::string date_receive;			  // Дата выдачи машины
	std::string date_return;			  // Дата возврата машины
	bool available;						  // Признак наличия

	bool operator > (Car_rental_status obj)
	{
		return this->state_registration_number > obj.state_registration_number ? true : false;
	}
	bool operator < (Car_rental_status obj)
	{
		return this->state_registration_number < obj.state_registration_number ? true : false;
	}
	bool operator == (Car_rental_status obj)
	{
		return this->state_registration_number == obj.state_registration_number ? true : false;
	}

	/*void output(Car_rental_status object)
	{
		std::cout << "Данные о выдаче на прокат или возврате автомобилей от клиентов:" << std::endl;
		std::cout << "номер водительского удостоверения: "; std::cout << object.driver_license_number;
		std::cout << "Государственный регистрационный номер: "; std::cout << object.state_registration_number;
		std::cout << "Дата выдачи машины "; std::cout << object.date_receive;
		std::cout << "Дата возврата машины "; std::cout << object.date_return;
		std::cout << "Признак наличия машины "; std::cout << object.available;
	}*/
};

struct node
{
	Car_rental_status data;
	node* next;
};

class List : public Check_str
{
private:
	node* head;
public:
	List();
	~List();
	Car_rental_status input_elem();
	void push_back();
	void push_front();
	void pop_back();
	void pop_front();
	void remove(std::string state_registration_number);
	bool search(std::string state_registration_number);
	int size();
	void edit(Car_rental_status elem, int index);
	void sort();
	void output_list();
	Car_rental_status get_item(int index);//index с 1
};

