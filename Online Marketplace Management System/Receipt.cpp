#include "Receipt.h"

Receipt::Receipt(float total_price, float shipment_price)
{
	this->total_price = total_price;
	this->shipment_price = shipment_price;
}

Receipt::Receipt(float total_price)
{
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
