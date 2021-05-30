#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include <windows.h>
#include <queue>
using namespace std;

class Admin :public Person
{
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Admin(string, string);
	queue<Product>requested_products;
	void Add_to_requested_products(Product);
	void Accept_or_Reject(vector <Product>&);
};
