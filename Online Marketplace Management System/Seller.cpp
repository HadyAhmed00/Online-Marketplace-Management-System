#include "Seller.h"
#include "Admin.h"

Seller::Seller()
{
}


Seller::Seller(int id, string name, string email)
{
	per_id = id;
	per_name = name;
	per_email = email;
}


//---------- Getters	--------------------

//@return the person id  AKA (Seller ID)
int Seller::getId()
{
	return per_id;
}
//@return the person Name  AKA (Seller Name)
string Seller::getName()
{
	return per_name;
}
//@return the person Email  AKA (Seller Email)
string Seller::getEmail()
{
	return per_email;
}


//----------------- Setters -------------------

//set the person id  AKA (Seller ID)
void Seller::setId(int id_val)
{
	per_id = id_val;
}
//set the person Name  AKA (Seller Name)
void Seller::setName(string name_val)
{
	per_name = name_val;
}
//set the person Email  AKA (Seller Email)
void Seller::setEmail(string Email_val)
{
	per_email = Email_val;
}


//-------- Seller functions ------------

// add the new product to the list of all products and to the list of the seller products
void Seller::addPriduct(vector<Product> all_products, Product new_Product)
{
	//call Add_to_requested_products function() in Admin class() 
	all_products.push_back(new_Product);
	seller_products.push_back(new_Product);
}

//return the seller product list 
vector<Product> Seller::getSellerProducts()
{
	return	seller_products;
}
Seller::~Seller()
{
}

