#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include "Admin.h"
#include <string>
#include <windows.h>
#include "Validation.h"
using namespace std;

/*
	* This class is a sup class form Person class
	* The persone class have the commen attrebutes between this class and Customer class
		- Such As :
			person ID
			Person Name
			Person Email
*/
class Seller : public Person
{
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	float profit = 0;

public:
	Seller();
	//Seller(string name, string password, string Email, string phone_number, string address);
	
	Seller(string, string,string);
	void seller_menu(Admin&,vector<Product>);
	void addPriduct(Admin&, vector<Product>);
	vector<Product> getSellerProducts(vector<Product>, int);
	void display_Seller_Products(vector<Product>, int,Admin&);
	~Seller();
};
