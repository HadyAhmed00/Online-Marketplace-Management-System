#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include "Admin.h"
#include <string>
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
	// The list of the products that seller sele
	//vector <Product> seller_products;
	float profit = 0;

public:
	Seller();
	//Seller(string name, string password, string Email, string phone_number, string address);
	
	Seller(string, string,string);

	int getId();
	string getName();
	string getEmail();
	void setId(int);
	void setName(string);
	void setEmail(string);

	/*//void addProduct(Admin,Product);
	void addProduct(Admin admin, Product new_Product);
	vector<Product> getSellerProducts();
	~Seller();*/
	void seller_menu();
	void addPriduct(Admin&);
	vector<Product> getSellerProducts(vector<Product>, int);
	void display_Seller_Products(vector<Product>, int);
	~Seller();
};
