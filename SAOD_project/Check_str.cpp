#include "Check_str.h"

//bool Check_str::check_driver_license_number(std::string str)
//{
//	std::regex regular("\\d{2}\\s[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{2}\\s[0-9]{6}");
//	return (regex_match(str.c_str(), regular)) ? true : false;
//}
//
//bool Check_str::check_state_state_registration_number(std::string str)
//{
//	std::regex regular("[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{1}\\d{3}[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{2}-\\d{2}");
//	return (regex_match(str.c_str(), regular)) ? true : false;
//}

std::string Check_str::input_driver_license_number()
{
	std::regex regular("\\d{2}\\s[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{2}\\s[0-9]{6}");
	do {
		std::cout << "Номер водительского удостоверения: ";
		/*std::cin.ignore();*/
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_state_registration_number()
{
	std::regex regular("[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{1}\\d{3}[А|В|Е|К|М|Н|О|Р|С|Т|У|Х]{2}-\\d{2}");
	do {
		std::cout << "Государственный регистрационный номер: ";
		std::cin.ignore();
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}

std::string Check_str::input_date(std::string line)
{
	std::regex regular("[0-9]{4}-(0[1-9]|[1][0-2])-(0[1-9]|[1-2][0-9]|3[0-1])");
	do {
		std::cout << line;
		std::cin.ignore();
		std::getline(std::cin, str);
	} while ((regex_match(str.c_str(), regular)) != true);
	return str;
}
