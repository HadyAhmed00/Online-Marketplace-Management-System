#pragma once
#include <iostream>
#include "Product.h"
#include "Customer.h"

using namespace std;

class Receipt
{
private:
	int id;
	float total_price;
	float shipment_price;
	Customer cust;

public:

	Receipt(Customer, float total_price, float shipment_price);
	Receipt(Customer, float total_price);

	int get_id();
	float get_total_price();
	float get_shipment_price();

};
