#pragma once
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Validation
{
public:
	Validation();
	bool Email_check(string );
	string passwordValidation();
	string emailValidation();
	~Validation();
};

