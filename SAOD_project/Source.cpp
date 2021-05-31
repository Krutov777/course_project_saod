#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "Tree.h"
#include "HashTable.h"

//using namespace std;

int main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);//вывод
	setlocale(LC_ALL, "RUS");
	Tree tree;
	List list;
	HashTable table;
	Car car;
	Car_rental_status car_rental_status;
	Check_str string;
	Client client;
	std::string str;
	std::string state_registration_number;
	//car = Car( "А111АВ-11", "Бенцлер", "Черный", 1998, false );  ###ТЕСТОВЫЕ ДАННЫЕ###
	//table.add(car.state_registration_number, car);

	//car = Car("А111ВА-11", "Бенцлер", "Белый", 1991, false);
	//table.add(car.state_registration_number, car);

	//car = Car("А222АА-22", "Мерседес", "Россия", 1999, true);
	//table.add(car.state_registration_number, car);

	//car = Car("А333АА-33", "Ауди", "Беларусь", 2000, false);
	//table.add(car.state_registration_number, car);

	///*car = Car("А444АА-44", "Ауди", "Беларусь", 2000, true);
	//table.add(car.state_registration_number, car);*/


	//client = Client("10 АВ 123456", "Крутов Александр Владимирович", "40 17 831439", "спб");
	//tree.put(client);

	//client = Client("20 АВ 123456", "Зинатов Рахим Гамирович", "77 66 000000", "Казань");
	//tree.put(client);

	//client = Client("30 АВ 123456", "Молчанов Михаил Юрьевич", "55 44 111111", "Пенза");
	//tree.put(client);

	//client = Client("40 АВ 123456", "Нестеренко Михаил Юрьевич", "11 44 111111", "Пенза");
	//tree.put(client);

	//client = Client("50 АВ 123456", "Алексеев Михаил Юрьевич", "55 44 123456", "Пенза");
	//tree.put(client);

	//car_rental_status = { "10 АВ 123456" ,"А111АВ-11", "2020-05-05", "" };
	//list.push_back(car_rental_status);

	//car_rental_status = { "20 АВ 123456" ,"А111ВА-11", "2000-04-03", "" };
	//list.push_back(car_rental_status);

	//car_rental_status = { "40 АВ 123456" ,"А333АА-33", "2021-05-05", "" };
	//list.push_back(car_rental_status);
	int n = -1;
	// Меню пользователяир
	while (n != 0)
	{
		//system("cls");
		std::cout << std::endl <<
			" 1 - Регистрация нового клиента" << std::endl <<
			" 2 - Снятие с обслуживания клиента" << std::endl <<
			" 3 - Просмотр всех зарегистрированных клиентов" << std::endl <<
			" 4 - Очистка данных о клиентах" << std::endl <<
			" 5 - Поиск клиента по «номер водительского удостоверения»" << std::endl <<
			" 6 - Поиск клиента по фрагментам ФИО или адреса" << std::endl <<
			" 7 - Добавление нового автомобиля" << std::endl <<
			" 8 - Удаление сведений об автомобиле" << std::endl <<
			" 9 - Просмотр всех имеющихся автомобилей" << std::endl <<
			"10 - Очистка данных об автомобилях" << std::endl <<
			"11 - Поиск автомобиля по «Государственному регистрационному номеру»" << std::endl <<
			"12 - Поиск автомобиля по названию марки автомобиля" << std::endl <<
			"13 - Регистрация отправки автомобиля в ремонт" << std::endl << //car - наличие false
			"14 - Регистрация прибытия автомобиля из ремонта" << std::endl <<//car - наличие true
			"15 - Регистрация выдачи клиенту автомобиля на прокат" << std::endl <<
			"16 - Регистрация возврата автомобиля от клиентов" << std::endl <<
			"17 - Данные о выдаче на прокат или возврате автомобилей от клиентов" << std::endl <<
			"0 - Выход\nВыберите действие: ";
		std::cin >> n; std::cout << std::endl << std::endl << std::endl;

		while (std::cin.fail() || std::cin.get() != '\n' || (n < 0) || (n > 17))
		{
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
			std::cout << "Ошибка ввода, выберите действие: ";
			std::cin >> n;
		}
		switch (n)
		{
		case 1:
			client = client.input();
			if (tree.search(client.driver_license_number) == false)
			{
				tree.put(client);
				std::cout << "Клиент зарегистрирован.\n";
			}
			else
				std::cout << "Клиент с таким водительским удостоверением уже существует!\n";
			break;
		case 2:
			str = string.input_driver_license_number();
			if (tree.search(str) == false)             
				std::cout << "Клиент с таким водительским удостоверением отсутствует!\n";
			else
			{
				tree.remove(str);
				std::cout << "Сведения удалены\n";
				std::string state_reg_num = list.search_number("", str);
				if (list.search(state_reg_num) == true)
					list.remove(state_reg_num);
				Car car = table.findCarByKey(state_reg_num);
				if (car.state_registration_number != "" && car.available == false) {
					table.removeByKey(state_reg_num);
					car.available = true;
					table.add(car.state_registration_number, car);
				}
			}
			break;
		case 3:
			tree.print_postfix();
			break;
		case 4:
			tree.clear(); 
			table.return_all_cars();
			list.clear();
			break;
		case 5:
			str = string.input_driver_license_number();
			client = tree.searchBy_driver_license(str);
			if (list.search_number("", str) != "")
				std::cout << "Государственный регистрационный номер: " << list.search_number("", str); 
			break;
		case 6:
			std::cout << "0 - Поиск клиента по фрагментам ФИО:\n";
			std::cout << "1 - Поиск клиента по фрагментам адреса:\n2 - Выход\nВыберите действие : ";
			std::cin >> n;
			while (std::cin.fail() || std::cin.get() != '\n' || (n < 0) || (n > 1))
			{
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
				std::cout << "Ошибка ввода, выберите действие: ";
				std::cin >> n;
			}
			switch (n)
			{
			case 0:
				std::cout << "Введите ФИО: ";
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::getline(std::cin, str);
				tree.searchByName(str);
				break;
			case 1:
				std::cout << "Введите адрес: ";
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				std::getline(std::cin, str);
				tree.searchByAdress(str);
				break;
			case 2:
				break;
			}
			n = -1;
			break;
		case 7:
			car = car.input();
			if (table.contains(car.state_registration_number) == false)
			{
				table.add(car.state_registration_number, car);
				std::cout << "Автомобиль добавлен!\n";
			}
			else
				std::cout << "Автомобиль с таким гос номером уже существует!\n";
			break;
		case 8:
			str = string.input_state_registration_number(); 
			if (table.contains(str) == false)
				std::cout << "Автомобиль с таким государственным регистрационным номером отсутствует!\n";
			else
			{
				table.removeByKey(str);
				std::cout << "Сведения удалены\n";
				if (list.search(str) == true)
					list.remove(str);
			}
			break;
		case 9:
			table.display();
			break;
		case 10:
			list.clear();
			table.clear();
			std::cout << "Очистка данных прошла успешно\n";
			break;
		case 11:
			str = string.input_state_registration_number();
			car = table.findCarByKey(str);
			if (car.state_registration_number != "")
			{
				std::cout << car;
				str = list.search_number(str, "");
				std::cout << "Номер водительского удостоверения: " << str << std::endl;
				tree.search_name(str);
			}
			else
				std::cout << "Данного автомобиля не существует! " << std::endl;
			break;
		case 12:
			str = string.input_brand();
			table.findByBrand(str);
			break;
		case 13:
			std::cout << "Регистрация отправки автомобиля в ремонт:\n";
			str = string.input_state_registration_number();
			car = table.findCarByKey(str);
			if (car.state_registration_number == "")
				std::cout << "Данного автомобиля не существует! " << std::endl;
			else if (car.available == true)
			{
				table.removeByKey(str);
				car.available = false;
				table.add(str, car);
				std::cout << "Автомобиль отправлен в ремонт\n";
			}
			else
				std::cout << "Тачка уже поломана) " << std::endl;
			break;
		case 14:
			std::cout << "Регистрация прибытия автомобиля из ремонта:\n";
			str = string.input_state_registration_number();
			car = table.findCarByKey(str);
			if (car.state_registration_number == "")
				std::cout << "Данного автомобиля не существует! " << std::endl;
			else if (car.available == false)
			{
				table.removeByKey(str);
				car.available = true;
				table.add(str, car);
			}
			else
				std::cout << "Тачка уже на месте) " << std::endl;
			break;
		case 15:
			std::cout << "15 - Регистрация выдачи клиенту автомобиля на прокат" << std::endl;
			str = string.input_driver_license_number();
			client = tree.searchBy_driver_license(str);
			if (client.driver_license_number != "")
			{
				car = table.findCarByKey(string.input_state_registration_number());
				if (car.state_registration_number != "" && car.available == true)
				{
					table.removeByKey(car.state_registration_number);
					car.available = false;
					table.add(car.state_registration_number, car);
					str = string.input_date("Введите дату выдачи клиенту автомобиля на прокат: ");
					car_rental_status = { client.driver_license_number, car.state_registration_number, str, "" };
					list.push_back(car_rental_status);
					std::cout << "Автомобиль выдан на прокат\n";
				}
				else
					std::cout << "Такого автомобиля не существует в базе или он не доступен.\n";
			}
			else
				std::cout << "Клиент с таким номером водительского удостоверения не существует.\n";
			break;
		case 16:
			std::cout << "16 - Регистрация возврата автомобиля от клиентов" << std::endl;
			state_registration_number = string.input_state_registration_number();
			str = list.search_number(state_registration_number, ""); // str - номер вод уд клиента
			car = table.findCarByKey(state_registration_number);
			if (str != "" && car.available == false)
			{
					table.removeByKey(state_registration_number);
					car.available = true;
					table.add(state_registration_number, car);
					car_rental_status = list.get(state_registration_number);
					car_rental_status.date_return = string.input_date("Введите дату возврата автомобиля от клиента на прокат: ");
					list.remove(state_registration_number);
					list.push_back(car_rental_status);
					std::cout << "Автомобиль вернулся от клиента\n";
			}
			else
				std::cout << "Данный автомобиль не выдавался на прокат!\n";
			break;
		case 17:
			if (list.is_empty() != true)
			{
				list.sort();
				list.output_list();
			}
			else
				std::cout << "Список пуст\n";
			break;
		case 0:
			break;
		}
	}
	return 0;
}
