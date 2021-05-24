#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
using namespace std;
class Customer : public Person
{
private:
	string Address;
	string phone_number;
	vector <Product> cart;

public :
	Customer(string name, string email, string address, string phone);
	string get_Address();
	string get_phone_number();
	void Add_to_cart(Product);
	void remove_from_cart(Product);
	bool search_by_name(string, vector<Product>);
	void display_category_products(vector<Product>, string);
};

