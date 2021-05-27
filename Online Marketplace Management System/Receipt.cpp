#include "Receipt.h"

Receipt::Receipt(Customer c, float total_price, float shipment_price)
{
	cust = c;
	this->total_price = total_price;
	this->shipment_price = shipment_price;
}

Receipt::Receipt(Customer c, float total_price)
{
	cust = c;
	this->total_price = total_price;
	shipment_price = 30.0f;
}

int Receipt::get_id()
{
	return id;
}

float Receipt::get_total_price()
{
	return total_price;
}

float Receipt::get_shipment_price()
{
	return shipment_price;
}
