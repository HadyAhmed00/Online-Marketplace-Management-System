#include "Product.h"
#include<string>
static int ID = 10000;
Product::Product()
{
}
Product::Product(int seller_id,int quantity, float price, string name, string category)
{
	ID++;
	this->id = ID;
	this->quantity=quantity;
	this->seller_id = seller_id;
	this->price = price;
	this->category = category;
	this->name = name;
}

string Product::get_name()
{
	return name;
}

string Product::get_category()
{
	return category;
}

float Product::get_price()
{
	return price;
}

int Product::get_id()
{
	return id;
}

int Product::get_quantity()
{
	return quantity;
}

int Product::get_sellerId()
{
	return seller_id;
}

void Product::product_info(Product product)
{
	cout <<this->get_name()<< "\tt product id: "<< this->get_id()<<"\tt price: "<< this->get_price()<<" $\tt category: "<< this->get_category();
}
