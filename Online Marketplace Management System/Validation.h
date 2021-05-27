#pragma once
#include <iostream>
#include <string>
#include <regex>



using namespace std;



class Validation
{
public:
	Validation();
	static bool Email_check(string);



	static string passwordValidation();



	static string emailValidation();
	~Validation();
};
