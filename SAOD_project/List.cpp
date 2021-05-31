#include "List.h"

List::List()
{
	head = NULL;
}

List::~List()
{
	if (head != NULL)
	{
		while (head != NULL)
		{
			pop_front();
		}
	}
}

Car_rental_status List::input_elem()
{
    Car_rental_status object;
    std::cout << "	Данные о выдаче на прокат или возврате автомобилей от клиентов:" << std::endl << std::endl;
    object.driver_license_number = input_driver_license_number();
    object.state_registration_number = input_state_registration_number();
    object.date_receive = input_date("Дата выдачи машины ");
    object.date_return = input_date("Дата возврата машины ");
    return object;
}

void List::push_back(Car_rental_status elem)
{
    node* temp = new node;
	temp->data = elem;
    temp->next = NULL;
    node* p = head;
	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		while (p->next)
			p = p->next;
		p->next = temp;
	}
}

void List::push_front()
{
    Car_rental_status elem = input_elem();
    node* temp = new node;
	temp->data = elem;
	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void List::pop_back()
{
	if (head != NULL)
	{
        node* temp = head;
        node* toDelete;
		while (temp->next->next != NULL)
			temp = temp->next;
		toDelete = temp->next;
		temp->next = NULL;
	}
}

void List::pop_front()
{

    if (head)
    {
        node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}


void List::remove(std::string state_registration_number)
{
    node* temp = this->head;
    if (temp->data.state_registration_number == state_registration_number)
    {
        node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->next->data.state_registration_number == state_registration_number)
            {
                node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                break;
            }
            temp = temp->next;
        }
    }
}

bool List::search(std::string state_registration_number)
{
    node* temp = head;
    if (temp != NULL)
    {
        while (temp)
        {
            if (temp->data.state_registration_number == state_registration_number)
                return true;
            temp = temp->next;
        }
    }
    return false;
}

int List::size()
{
    node* temp = this->head;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

Car_rental_status List::get_item(int index)
{
    node* temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        //counter++;
        if (counter == index)
            return temp->data;
        counter++;
        temp = temp->next;
    }
}

void List::edit(Car_rental_status elem, int size)
{
    node* temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        if (counter == size)
        {
            temp->data = elem;
            break;
        }
        temp = temp->next;
        counter++;
    }
}

void List::output_list()
{
    node* p = this->head;
    if (p != NULL)
    {
        std::cout << " " << std::left << std::setw(35) << "номер водительского удостоверения" << std::setw(45) << "Государственный регистрационный номер" << std::setw(25)
            << "Дата выдачи машины" << std::setw(25) << "Дата возврата машины" << std::endl;
        while (p != NULL)
        {
            std::cout << " " << std::left << std::setw(35) << p->data.driver_license_number << std::setw(45) << p->data.state_registration_number << std::setw(35) << p->data.date_receive
                << std::setw(35) << p->data.date_return << std::endl;
            p = p->next;
        }
    }
    else std::cout << "Нет данных!";
}

void List::sort()
{
    Car_rental_status value;
    Car_rental_status prev; //предыдущий элемент
    int index = 0;
    int N = size();
    // Для всех элементов кроме начального
    for (int i = 1; i < N; i++)
    {
        value = get_item(i); // запоминаем значение элемента
        index = i;     // и его индекс
        while ((index > 0) && (get_item(index - 1) > value))
        {   // смещаем другие элементы к концу массива пока они меньше index
            
            prev = get_item(index - 1);
            edit(prev, index);
            index--;    // смещаем просмотр к началу массива
        }
        edit(value, index); // рассматриваемый элемент помещаем на освободившееся место
    }
}

std::string List::searchBy_driver_license(std::string driver_license_number)
{
    node* temp =  this->head;
    std::string str = "";
    if (temp != NULL)
    {
        while (temp)
        {
            if (temp->data.driver_license_number == driver_license_number)
            {
                str = driver_license_number;
                return str;
            }
            temp = temp->next;
        }
    }
    return str;
}

std::string List::search_number(std::string state_registration_number, std::string driver_license_number)
{
    node* temp = this->head;
    std::string str;
    if (driver_license_number != "")
        str = driver_license_number;
    else
        str = state_registration_number;
    if (temp != NULL)
    {
        while (temp)
        {
            if (temp->data.driver_license_number == str)
                return temp->data.state_registration_number;
            else if (temp->data.state_registration_number == str)
                return temp->data.driver_license_number;
            temp = temp->next;
        }
    }
    return str;
}

void List::removeByDriverLicense(std::string driver_license_number)
{
    node* temp = head;
    while (temp)
    {
        if (temp->data.driver_license_number == driver_license_number)
        {
            node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
            break;
        }
        temp = temp->next;
    }
}

Car_rental_status List::get(std::string state_registration_number)
{
    Car_rental_status elem;
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data.state_registration_number == state_registration_number)
            return temp->data;
        temp = temp->next;
    }
    return elem;
}

bool List::is_empty()
{
    return (this->head == NULL);
}

void List::clear()
{
    while (head)
        pop_front();
}