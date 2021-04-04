#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <fstream>

class Check_str
{
private:
	std::string str;
public:
	std::string input_driver_license_number();
	std::string input_state_registration_number();
	std::string input_date(std::string line);
	/*bool check_state_state_registration_number(std::string str);
	bool check_driver_license_number(std::string str);*/
};

