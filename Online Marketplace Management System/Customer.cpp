#include "Customer.h"

Customer::Customer(int id, string name, string email, string address, string phone)
{
	per_id = id;
	per_name = name;
	per_email = email;
	Address = address;
	phone_number = phone;	
}

//Getters
string Customer::get_Address()
{
	return Address;
}

string Customer::get_phone_numper()
{
	return phone_number;
}

//add to cart function: add product to customer cart
void Customer::Add_to_cart(Product product)
{
	cart.push_back(product);
}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(Product product)
{
	
}

