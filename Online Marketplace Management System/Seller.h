#pragma once

#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include "Admin.h"

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
	vector <Product> seller_products;
	
public:

	Seller(string ,string);

	int getId();
	string getName();
	string getEmail();
	void setId(int);
	void setName(string);
	void setEmail(string);

	void addPriduct(Admin,Product);
	vector<Product> getSellerProducts();
	~Seller();
};

