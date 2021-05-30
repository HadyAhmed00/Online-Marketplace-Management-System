#include "Receipt.h"
static int Id = 10000000;
Receipt::Receipt(Customer c, float total_price, float shipment_price)
{
	Id++;
    id = Id;
	cust = c;
	this->total_price = total_price;
	this->shipment_price = shipment_price;
}

Receipt::Receipt(Customer c, float total_price)
{
	Id++;
	id = Id;
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


/*void Receipt::display_Receipt(vector<Product>& products)
{
	cout << "************ Wellcome! ************";
	for (int i = 0; i < cart.size(); i++) {
		cout << i + 1 << "-  " << "product name: " << cart[i].pro.get_name() << "\t\tprice: " << cart[i].pro.get_price() << " EGP" << "\t\t quantity:  " << cart[i].Quantity << "\t\ttotal: " << cart[i].pro.get_price() * cart[i].Quantity << " EGP" << endl;
	}
	}*/

