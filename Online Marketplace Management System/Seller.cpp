#include "Seller.h"
#include "Admin.h"

static int ID = 1000;

Seller::Seller( string name, string email)
{
	per_id = ID;
	per_name = name;
	per_email = email;
	ID++;
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
void Seller::addPriduct(Admin admin,Product new_Product)
{
	//call Add_to_requested_products function() in Admin class() 
	admin.Add_to_requested_products(new_Product);
	seller_products.push_back(new_Product);
}

//return the seller product list 
vector<Product> Seller::getSellerProducts()
{
	return	seller_products;
}

void Seller::display_Seller_Products()
{
	cout << "Your Products is :\n______________________________";
	cout << "ID \t\tProduct Name \t \t Quntaty\n";
	for (int i = 0; i < seller_products.size(); i++)
	{
		cout << seller_products[i].get_id() << " \t\t" << seller_products[i].get_name() << " \t\t" << seller_products[i].get_quantity() << "\n";
	}
}
Seller::~Seller()
{
}

