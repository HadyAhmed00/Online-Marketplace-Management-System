#pragma once
#include <iostream>
using namespace std;
class Product
{
private:
    int id, seller_id, quantity;
    float price;
    string name, category;
public:
    Product();
    Product(int seller_id, int quantity, float price, string name, string category);
    string get_name();
    string get_category();
    float get_price();
    int get_id();
    int get_quantity();
    int get_sellerId();
    void set_quantity(int); \
        void set_name(string);
    void set_categry(string);
    void product_info();
};
