#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <windows.h> 


using namespace std;



class Validation
{
public:
	Validation();
	static bool Email_check(string);
	static string passwordValidation();
	static int isNumber();
	static float isFloat();
	static string emailValidation();
	static string phoneValidation();
	~Validation();
};
