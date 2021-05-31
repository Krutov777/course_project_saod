#include "Check_str.h"


std::string Check_str::input_driver_license_number()
{
	std::regex regular("\\d{2}\\s[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{2}\\s[0-9]{6}");
	do {
		std::cout << "Номер водительского удостоверения: ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_state_registration_number()
{
	std::regex regular("[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{1}\\d{3}[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{2}-\\d{2}");
	do {
		std::cout << "Государственный регистрационный номер: ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_date(std::string line)
{
	std::regex regular("[0-9]{4}-(0[1-9]|[1][0-2])-(0[1-9]|[1-2][0-9]|3[0-1])");
	do {
		std::cout << line;
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_name()
{
	std::regex regular("[a-zA-ZА-Яа-я]{1,20}\\s[a-zA-ZА-Яа-я]{1,20}\\s[a-zA-ZА-Яа-я]{1,20}");
	do {
		std::cout << "ФИО:(через пробел, на слово 20 символов) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_passport()
{
	std::regex regular("[0-9]{2}\\s[0-9]{2}\\s[0-9]{6}");
	do {
		std::cout << "Паспортные данные:(ЦЦ ЦЦ ЦЦЦЦЦЦ, где Ц-цифра) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_adress()
{
	do {
		std::cout << "Адрес:(1-60 символов) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while (str.size() > 60 || str.size() < 1);
	return str;
}

std::string Check_str::input_brand()
{
	do {
		std::cout << "Бренд автомобиля:(1-60 символов) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while (str.size() > 60 || str.size() < 1);
	return str;
}

std::string Check_str::input_color()
{
	do {
		std::cout << "Цвет автомобиля:(1-60 символов) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while (str.size() > 60 || str.size() < 1);
	return str;
}

int Check_str::input_year_of_release()
{
	std::regex regular("[1-9][0-9]{3}");
	do {
		std::cout << "Год выпуска автомобиля:(4 цифры) ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return stoi(str);
}
