#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
using namespace std;
struct product_struct {
	Product pro;
	int Quantity;
};
class Customer : public Person
{
private:
	string Address;
	string phone_number;
	vector <product_struct> cart;

public :
	Customer();
	Customer(string name, string email, string address, string phone);
	string get_Address();
	string get_phone_number();
	void Add_to_cart(Product&,int);
	void remove_from_cart(Product&);
	bool search_by_name(string, vector<Product>);
	void display_category_products(vector<Product>, string);
	void display_cart_products();
};

