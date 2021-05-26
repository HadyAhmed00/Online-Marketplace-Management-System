#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;
static int ID = 100;
Customer::Customer(){

}
Customer::Customer( string name, string email, string address, string phone)
{
	ID++;
	per_id = ID;
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

string Customer::get_phone_number()
{
	return phone_number;
}

//add to cart function: add product to customer cart
void Customer::Add_to_cart(Product &product,int quantity)
{
	bool found = false;
	int index;
	for (int i = 0; i < cart.size(); i++)
	{
		if (product.get_id == cart[i].pro.get_id)
		{
			found = true;
			index = i;
			break;
		}
		else
			found = false;
	}
	if (found)
	{
		cart[index].Quantity += quantity;
		product.set_quantity(product.get_quantity() - quantity);
		cout << "this product is already exist so the product quantity has been increased\n";
	}
	else
	{
		product_struct temp;
		temp.pro = product;
		temp.Quantity = quantity;
		cart.push_back(temp);
		product.set_quantity(product.get_quantity() - quantity);
		cout << "the product has been added to cart\n";
	}
}

// search for a product by entering its name
bool Customer::search_by_name(string Name, vector<Product>arr) {
	bool isFound = false;
	int index;
	for (int i = 0; i < arr.size(); i++)
	{
		if (Name == arr[i].get_name())
		{
			isFound = true;
			index = i;
			break;
		}
		else 
		{
			isFound = false;
			continue;
		}
		
	} 
	if (isFound)
	{
		arr[index].product_info();
		cout << endl;
		return true;
	}
	else
	{
		return false;
		cout << "product is not found\n";
	}

}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(Product &product)
{
	bool isFound = false;
	int index;
	for (int i = 0; i < cart.size(); i++)
	{
		if (product.get_id() == cart[i].pro.get_id()) 
		{
			isFound = true;
			index = i;
			break;
		}
		else
		{
			continue;
		}
	}
	if (isFound) 
	{
		product.set_quantity(product.get_quantity() + cart[index].Quantity);
		cart.erase(cart.begin()+index);
		cout << "the product " << cart[index].pro.get_name << " has been removed\n";
	}
	else 
	{
		cout << "This product"<<cart[index].pro.get_name<< " is not found" << endl;
	}
}
//display all elements in cart
void Customer::display_cart_products()
{
	for (int i = 0; i < cart.size(); i++)
	{
		cout << cart[i].pro.get_name() << "\t" << cart[i].Quantity<<endl;
	}
}

void Customer::display_category_products(vector <Product> products,string cat)
{
	bool isfound = false;
	int index;
	for (int i = 0; i < products.size(); i++)
	{
		if (cat == products[i].get_category())
		{
			products[i].product_info();
			cout << endl;
			continue;
		}
		else
		{
			continue;
		}
	}
	
}