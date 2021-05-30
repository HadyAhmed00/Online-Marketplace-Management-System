#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include <windows.h>

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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
    Customer();
	Customer(string name, string email, string address, string phone, string password );
    void Add_to_cart(Product&,vector<Product>&);
    void customer_menu(vector<Product>&);
	void remove_from_cart(int, vector<Product>&);
    void search_by_name(vector<Product>&);
	void display_category_products(string, vector<Product>&);
    void display_cart_products(vector<Product>&);
	void show_all_products(vector<Product>&);
    void display_Receipt();
    void Cancel(vector<Product>& products);

};
