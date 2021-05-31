#include "Product.h"
#include<string>
static int ID = 10000;
Product::Product()
{
}
Product::Product(int seller_id, int quantity, float price, string name, string category)
{
    ID++;
    this->id = ID;
    this->quantity = quantity;
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

void Product::set_quantity(int q)
{
    quantity = q;
}

void Product::set_name(string name)
{
    this->name = name;
}

void Product::set_categry(string category)
{
    this->category = category;
}

void Product::product_info()
{
    cout << "product Name: " << this->get_name() << "    product ID: " << this->get_id() << "    price: " << this->get_price() << " EGP     category: " << this->get_category() << "    quantity: " << this->get_quantity() << endl;
}