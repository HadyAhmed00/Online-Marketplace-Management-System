#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include <String>
#include <queue>
using namespace std;
class Admin:public Person
{
public:
	Admin(string,string);
	queue<Product>requested_products;
	void Add_to_requested_products(Product);
	void Accept_or_Reject(vector <Product>&);
};

