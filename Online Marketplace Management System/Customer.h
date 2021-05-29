#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"

#include<string>
using namespace std;
struct product_struct {
    Product pro;
    int Quantity;
};
class Customer : public Person
{
private:
    vector <product_struct> cart;
	vector <Product> products;

public:
    Customer();
	Customer(string name, string email, string address, string phone, string password, vector <Product>& );
    void Add_to_cart(Product&);
    void customer_menu();
    void remove_from_cart(int);
    void search_by_name();
    void display_category_products( string);
    void display_cart_products();
	void show_all_products();
};
