#include "Customer.h"
static int ID = 100;
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
void Customer::Add_to_cart(Product product)
{
	cart.push_back(product);
}

// search for a product by entering its name
//bool Customer::search_by_name(string Name, vector<Product>arr) {
//	bool isFound = false;
//	int index;
//	for (int i = 0; i < arr.size(); i++)
//	{
		//if (Name == arr[i].name)
		//{
	//	isFound = true;
	//	index = i;
	//	//Waiting for product class to implement display category function
	//	break;
	//}
	//else {
	//	continue;
	//}
//		
//	} 


//}
//remove from cart: remove product from customer cart
//void Customer::remove_from_cart(Product product)
//{
//	
//	bool isFound = false;
//	int index;
//	for (int i = 0; i < cart.size; i++)
//	{
//		if (product.id == cart[i].id) {
//			isFound = true;
//			index = i;
//		}
//		else
//		{
//			continue;
//		}
//	}
//	if (isFound == true) {
//		//call the function of Product Removal
//		cart.erase(cart.begin()+index);
//	}
//	else {
//		cout << "This product is not found" << endl;
//	}
//}

//void Customer::display_category_products(vector <Product> products,string cat) {
//	for (int i = 0; i < products.size; i++)
//	{
//		if (cat == products[i].category) {
//			//Calling display function
//			continue;
//		}
//	}
//}