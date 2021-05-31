#pragma once
#include <iostream>
#include <regex>
#include <string>

class Check_str
{
private:
	std::string str;
public:
	std::string input_driver_license_number();
	std::string input_state_registration_number();
	std::string input_date(std::string line);
	std::string input_name();
	std::string input_passport();
	std::string input_adress();
	std::string input_brand();
	std::string input_color();
	int input_year_of_release();
};

