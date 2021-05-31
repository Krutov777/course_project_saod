#include "HashTable.h"

HashTable::HashTable()
{
	this->size = 2;
	this->arr = new Pair[size]();
}

HashTable::~HashTable()
{
	delete[] arr;
}

void HashTable::clear()
{
	for (int i = 0; i < this->size; i++)
	{
		/*if (arr[i].data.available == true)  //условие для удаления только не занятых авто
		{*/
			arr[i] = Pair();
			/*this->count--;*/
		/*}*/
	}
	this->count = 0;
}

bool HashTable::contains(std::string key)
{
	/*Pair check = pairByKey(key);
	return !(check == Pair()) && check.key == key;*/
	return !(arr[hashFun(key)] == Pair()) && arr[hashFun(key)].key == key;
}

void HashTable::add(std::string key, Car data)
{
	int i = hashFun(key);
	if (isFree(i))
		this->arr[i] = Pair(key, data);
	else
	{
		int n = 1;
		do
		{
			i = collisionFix(i, n++);
		} while (!isFree(i));

		this->arr[i] = Pair(key, data);
	}
	this->count++;
	resize();
}

Pair HashTable::pairByKey(std::string key)
{
	int i = hashFun(key);

	int try_n = 1;
	while (arr[i].key != key && try_n != this->count) {
		i = collisionFix(i, try_n++);
	}
	if (try_n != this->count)
		return arr[i];
	return Pair();
}

Car HashTable::removeByKey(std::string key)
{
	int i = hashFun(key);
	Car car;
	int n = 1;
	while (arr[i].key != key && n != this->count) {
		i = collisionFix(i, n++);
	}
	if (n != this->count)
	{
		car = this->arr[i].data;
		this->arr[i] = Pair();
		this->count--;
	}
	return car;
	
}

//by @qveex
int HashTable::hashFun(std::string key)
{
	/*return std::hash<std::string>{}(key) % this->size;*/
	unsigned int hash(0);
	int key_size = key.size();

	for (int i = 0; i < key_size; i++)
		key += pow(key.at(i), 2);
	hash *= key.at(5) + key.at(4) - key.at(1)* key.at(7) + key.at(8);
	hash += key.at(4) + key.at(0) * key.at(3);
	hash += pow(key.at(5), 3) + pow(key.at(2), 2);
	hash += pow(key.at(3), 4) - pow(key.at(4), 3);
	hash -= key.at(0) + (key.at(1) * 2) - pow(key.at(2), 2);

	return hash % this->size;
}

Car& HashTable::operator[](std::string key)
{
	return arr[hashFun(key)].data;
}

int HashTable::collisionFix(int i, int n)
{
	int res = i + c1 * n + c2 * n * n;
	if (res < this->size)
		return res;
	else
		return res % this->size;
}

bool HashTable::isFree(int i)
{
	return arr[i] == Pair();
}

void HashTable::resize()
{

	if ((double)count / (double)size >= 0.7)
	{
		this->size *= 2;

		Pair* new_arr = new Pair[size]();
		for (int i = 0; i < size; i++)
			new_arr[i] = Pair();

		for (int i = 0; i < this->size / 2; i++)
		{
			if (this->arr[i] == Pair())
				continue;
			else
			{
				int j = hashFun(arr[i].key);

				if (new_arr[j] == Pair())
					new_arr[j] = Pair(arr[i].key, arr[i].data);
				else
				{
					int try_n = 1;
					do
					{
						j = collisionFix(j, try_n++);
					} while (!(new_arr[j] == Pair()));

					new_arr[j] = Pair(arr[i].key, arr[i].data);
				}
			}

		}

		delete[] this->arr;

		this->arr = new_arr;
	}
	
}

void HashTable::display() {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].data.state_registration_number != "") {
			Car data = arr[i].data;
			std::cout << count + 1 << "  " << data << std::endl;
			count++;
		}
	}
	if (count == 0)
		std::cout << "Хеш-таблица пустая" << std::endl;
	std::cout<<"размер таблицы: " << this->size << std::endl;
	std::cout << "кол-во элементов со значением: " << this->count << std::endl;
}

void HashTable::return_all_cars() {
	for (int i = 0; i < size; i++) {
			arr[i].data.available = true;
		}
}

void HashTable::findByBrand(std::string brand) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].data.brand == brand) {
			std::cout << count + 1 << "  " << arr[i].data << std::endl;
			count++;
		}
	}
	if (count == 0)
		std::cout << "Хеш-таблица не содержит автомобилей с данной маркой (-_-)" << std::endl;
}

Car HashTable::findCarByKey(std::string key) {
	if (contains(key) == 1) {
		return arr[hashFun(key)].data;
	}
	else {
		Car elem;
		return elem;
	}
}

int HashTable::size_()
{
	return this->size;
}
