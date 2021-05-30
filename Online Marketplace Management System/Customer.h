#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include <windows.h>
#include "Validation.h"
#include "Seller.h"
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
    void Add_to_cart(Product&,vector<Product>&,vector<Seller>&);
    void customer_menu(vector<Product>&,vector<Seller>&);
	void remove_from_cart(int, vector<Product>&,vector<Seller>&);
    void search_by_name(vector<Product>&,vector<Seller>&);
	void display_category_products(string, vector<Product>&,vector<Seller>&);
    void display_cart_products(vector<Product>&,vector <Seller>&);
	void show_all_products(vector<Product>&, vector<Seller>&);
    void display_Receipt(vector<Seller>&);
    void Cancel(vector<Product>& products);

};
