#include "Customer.h"
#include "Receipt.h"
#include <iostream>
#include <string>
using namespace std;
static int ID = 1000;
int choice;
Customer::Customer() {

}


Customer::Customer(string name, string email, string address, string phone, string password)
{
    ID++;
    per_id = ID;
    per_name = name;
    per_email = email;
    this->address = address;
    this->phone_number = phone;
    per_password = password;
}


//add to cart function: add product to customer cart
void Customer::Add_to_cart(Product& product, vector<Product>&products, vector<Seller>&sellers)
{
	int quantity;
	
	cout << "please enter quantity: ";
	quantity = Validation::isNumber();
	if (quantity > product.get_quantity())
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Sorry this quantity is unavailable right now :(\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		bool found = false;
		int index;
		for (int i = 0; i < cart.size(); i++)
		{
			if (product.get_id() == cart[i].pro.get_id())
			{
				found = true;
				index = i;
				break;
			}
			
		}
		if (found) //if the product is already in the cart
		{
			cart[index].Quantity += quantity;
			product.set_quantity(product.get_quantity() - quantity);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Now you have " << cart[index].Quantity << " of " <<"\""<< product.get_name()<<"\"" << "\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
		{
			product_struct temp;
			temp.pro = product;
			temp.Quantity = quantity;
			cart.push_back(temp);
			product.set_quantity(product.get_quantity() - quantity);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\""<<product.get_name()<<"\""<<" has been added to your cart successfully \n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	cout << "Press-->1 to add more quantity of this product\n";
	cout << "Press-->2 to search for another product\n";
	cout << "Press-->3 to go to customer menu\n";
	cout << "Press-->4 to log out\n";
	choice = Validation::isNumber();
	
	
	if (choice == 1)
	{
		Add_to_cart(product, products, sellers);
	}
	else if (choice == 2)
	{
		search_by_name(products, sellers);
	}
	else if (choice == 3)
	{
		customer_menu(products, sellers);
	}
	else if (choice == 4)
	{
		cout << "Logging out.........\n";
		Cancel(products);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...Please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		show_all_products(products, sellers);
	}
	
}

void Customer::customer_menu(vector<Product>&products,vector<Seller>&sellers)
{
	system("cls");
     
    string cat = "no cat";
    cout << "\t\t\t\t\t******************* Customer Menu *******************\n\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\n\t\t\t\t\t\t------------ Welcome -------------\n\n" <<  endl;
	SetConsoleTextAttribute(hConsole, 15);
    cout << "Press 1 to go to cart\n\n";
    cout << "Press 2 to show Appliances products\n\n";
    cout << "Press 3 to show Books products\n\n";
    cout << "Press 4 to show Fashion products\n\n";
    cout << "Press 5 to show Food & Beverage products\n\n";
    cout << "Press 6 to show Smartphones, Laptops & Accessories products\n\n";
	cout << "Press 7 to show all products\n\n";
    cout << "Press 8 to search for a product by its name\n\n";
    cout << "Press 9 to log out\n\n";
	choice = Validation::isNumber();

    switch (choice) {
    case 1:
		display_cart_products(products, sellers);
        break;
    case 2:
		display_category_products("Appliances", products, sellers);
        break;
    case 3:
		display_category_products("Books", products, sellers);
        break;
    case 4:
		display_category_products("Fashion", products, sellers);
        break;
    case 5:
		display_category_products("Food & Beverage", products, sellers);
        break;
	case 6:
		display_category_products("SmartPhones, Laptops and Accessories", products, sellers);
		break;
    case 7:
		show_all_products(products, sellers);
        break;
    case 8:
		search_by_name(products, sellers);
        break;
    case 9:
        cout << "Logging out.......\n";
		Cancel(products);
        break;
    default:
		SetConsoleTextAttribute(hConsole, 4);
        cout << "Incorrect entry..Please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		customer_menu(products, sellers);
        break;
    }
    
}

// search for a product by entering its name
void Customer::search_by_name(vector<Product>&products, vector<Seller>&sellers) {
	
	system("cls");
	bool found = false;
	bool isFound = false;
	string aim;
	vector<Product> tmp;
	cout << "Enter the product name you are searching for :\n";
	getline(cin, aim);
	for (int i = 0; i < products.size(); i++)
	{
		if (regex_search(products[i].get_name(), regex(aim + "(.*)")))
		{
			found = true;
			tmp.push_back(products[i]);
		}
		else
		{
			found == false;
		}
	}
	if (!found)
	{
		SetConsoleTextAttribute(hConsole, 11);
		cout << "There is no product with that name in the market :(\n\n" ;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		for (int i = 0; i < tmp.size(); i++)
		{
			tmp[i].product_info();
			cout << "\n\n--------------------------------------------------------\n\n\n";
		}
	}
	cout << "Press-->1 to add a product to your cart\n";
	cout << "Press-->2 to stay on this page\n";
	cout << "Press-->3 to go back\n";
	cout << "Press-->4 to log out\n";

	choice = Validation::isNumber();
	bool fId = false;
	switch (choice) {
	case 1:
		cout << "\nPlease enter the product ID to add it to your cart\n";
		choice = Validation::isNumber();
		for (int i = 0; i < tmp.size(); i++)
		{
			if (choice == tmp[i].get_id())
			{
				fId = true;
				break;
			}
			else
			{
				fId = false;
			}
		}
		if (fId)
		{
			for (int i = 0; i < products.size(); i++)
			{
				if (products[i].get_id() == choice)
				{
					Add_to_cart(products[i], products, sellers);
					isFound = true;
					break;
				}
			}
			if (isFound == false) {
				SetConsoleTextAttribute(hConsole, 4);
				cout << "The product ID you have entered is not found\n";
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				show_all_products(products, sellers);
			}

		}
		else
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "The ID is not found :(\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			search_by_name(products, sellers);
		}
		break;
	case 2:
		search_by_name(products, sellers);
		break;
	case 3:
		customer_menu(products, sellers);
		break;
	case 4:
		cout << "Logging out.........\n";
		Cancel(products);
		break;
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...Please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		search_by_name(products, sellers);
	}

}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(int ind, vector<Product>&products, vector<Seller>&sellers)
{
	int quantity;
	
    bool isFound = false;
    int index;
	int id;
	id = cart[ind].pro.get_id();
	cout << "please enter quantity: "; quantity = Validation::isNumber();
	if (quantity>cart[ind].Quantity)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "The quantity you have entered to remove exceeds what you have\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		for (int i = 0; i < products.size(); i++)
		{
			if (id == products[i].get_id())
			{
				products[i].set_quantity(products[i].get_quantity() + quantity);
				cout << "\nProduct has been removed from your cart\n";

				break;
			}
		}
		if (cart[ind].Quantity == quantity)
		{
			cart.erase((cart.begin() + ind));
		}
		else
		{
			cart[ind].Quantity -= quantity;
		}
	}
	
	"\n\n";
	 
	cout << "Press-->1 to stay on this page\n";
	cout << "Press-->2 to go back\n";
	cout << "Press-->3 to log out\n";
	choice = Validation::isNumber();
	switch (choice) {
	case 1:
		remove_from_cart(ind, products, sellers);
		break;
	case 2:
		customer_menu(products, sellers);
		break;
	case 3:
		cout << "Logging out.........\n";
		Cancel(products);
		break;
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		display_cart_products(products, sellers);
	}
}
//display all elements in cart
void Customer::display_cart_products(vector<Product>&products,vector<Seller>&sellers)
{
	system("cls");
     
	bool isfound=false;
	int n;
    if (cart.size() == 0) {
		SetConsoleTextAttribute(hConsole, 11);
        cout << "Your cart is empty now \n\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Press-->1 to search for a product to add it to your cart\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to log out\n";

		choice = Validation::isNumber();
		switch (choice) {
		case 1:
			search_by_name(products, sellers);
			break;
		case 2:
			customer_menu(products, sellers);
			break;
		case 3:
			cout << "Logging out.........\n";
			Cancel(products);
			break;
		default:
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid Entry...Please try again!\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			display_cart_products(products, sellers);
		}
    }
    else {
		for (int i = 0; i < cart.size(); i++)
		{
			cout << i + 1 << "- " << "Product Name: " << cart[i].pro.get_name() << "\tProduct ID: "<<cart[i].pro.get_id() <<"\tPrice: "<< cart[i].pro.get_price()<<" EGP" << "\t\t Quantity:  " << cart[i].Quantity <<"\t\tTotal: "<< cart[i].pro.get_price()* cart[i].Quantity <<" EGP" << endl;
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
		}
			cout << "Press-->1 to search for a product to add it to your cart\n";
			cout << "Press-->2 to remove products from your cart\n";
			cout << "Press-->3 to go back\n";
			cout << "Press-->4 to confirm\n";
			cout << "Press-->5 to remove all products\n";
			cout << "Press-->6 to log out\n";

			choice = Validation::isNumber();
			switch (choice) {
			case 1:
				search_by_name(products, sellers);
				break;
			case 2:
				cout << "\nPlease enter the product ID to remove it\n";
				cin >> n;
				cin.ignore();
				for (int i = 0; i < cart.size(); i++)
				{
					if (cart[i].pro.get_id() == n) {
						remove_from_cart(i, products, sellers);
						SetConsoleTextAttribute(hConsole, 10);
						cout << "The product has been removed from your cart successfully \n";
						SetConsoleTextAttribute(hConsole, 15);
						isfound = true;
						break;
					}
				}
				if (isfound == false) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "The product ID you have entered is not found\n";
					SetConsoleTextAttribute(hConsole, 15);
					system("pause");
					display_cart_products(products, sellers);
				}
				break;
			case 3:
				customer_menu(products, sellers);
				break;
			case 4:
				display_Receipt(sellers);
				break;
			case 5:
				Cancel(products);
				cout << "\nAll products have been removed from your cart\n";
				break;
			case 6:
				cout << "Logging out.........\n";
				Cancel(products);
				break;
			default:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "Invalid Entry...Please try again!\n";
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				display_cart_products(products, sellers);
			}
    } 
}

void Customer::display_category_products(string cat, vector<Product>&products, vector<Seller>&sellers)
{
	system("cls");
	 
    bool isfound = false;
    int index;
	int pro_num = 1;
	cout << "\n";
	cout <<"\t\t\t\t\t------------------ " << cat << " ------------------\n\n";
    for (int i = 0; i < products.size(); i++)
    {
		if (cat == products[i].get_category() && products[i].get_quantity()!=0)
		{
			cout << "Product Number: " << pro_num <<" ";
			products[i].product_info();
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
			cout << endl;
			isfound = true;
			pro_num++;
			continue;
		}
    }
	if (isfound==false)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "There are no available products of this category right now :(\n\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	cout << "Press-->1 to Add product to cart\n";
	cout << "Press-->2 to go back\n";
	cout << "Press-->3 to log out\n";
	
	choice = Validation::isNumber();
	isfound = false;
	switch (choice) {
	case 1:		
		cout << "\nPlease enter the product ID to add it to your cart\n";
		choice = Validation::isNumber();
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].get_id() == choice && products[i].get_category() == cat) {
				Add_to_cart(products[i], products, sellers);
				isfound = true;
				break;
			}			
		}
		if (isfound == false) {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "The product ID you have entered is not found\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			display_category_products(cat, products, sellers);
		}
		
		break;
	case 2:
		customer_menu(products, sellers);
		break;
	case 3:
		cout << "Logging out.........\n";
		Cancel(products);
		break;
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		display_category_products(cat, products, sellers);
	}

}

void Customer::show_all_products(vector<Product>&products, vector<Seller>&sellers)
{
	system("cls");
	 
	bool isFound = false;
	int displayed_numbers=1;
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].get_quantity() != 0) {
			cout << endl;
			cout << displayed_numbers << "- ";
			products[i].product_info();
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
			displayed_numbers++;
		}
		
	}
	cout << "Press-->1 to Add product to cart\n";
	cout << "Press-->2 to go back\n";
	cout << "Press-->3 to log out\n";
	
	choice = Validation::isNumber();
	switch (choice) {
	case 1:
		cout << "\nPlease enter the product ID to add it to your cart\n";
		choice = Validation::isNumber();
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].get_id() == choice) {
				Add_to_cart(products[i], products, sellers);
				isFound = true;
				break;
			}
		}
		if (isFound == false) {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "The product ID you have entered is not found\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			show_all_products(products, sellers);
		}
		break;
	case 2:
		customer_menu(products, sellers);
		break;
	case 3:
		Cancel(products);
		cout << "Logging out.........\n";
		break;
	
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		show_all_products(products, sellers);
	}
}

void Customer::display_Receipt(vector<Seller>&sellers)
{
	float totalPrice=0;

	for (int i = 0; i < cart.size(); i++)
	{
		float profit_product = 0;
		profit_product += cart[i].pro.get_price()*cart[i].Quantity;
		for (int j = 0; j < sellers.size(); j++)
		{
			if (cart[i].pro.get_sellerId()==sellers[j].get_id())
			{
				sellers[j].set_profit(profit_product);
				break;
			}
		}
		totalPrice += cart[i].pro.get_price() * cart[i].Quantity;
		
	}
	
	Receipt receipt(*this,totalPrice);
	cout << "\t\t\t\t\t************ Welcome! ************\n\n\n" << "Receipt ID: " << receipt.get_id() << "\n\n";

	for (int i = 0; i < cart.size(); i++)
	{
		cout << i + 1 << "-  " << "product name: " << cart[i].pro.get_name() << "\t\tprice: " << cart[i].pro.get_price() << " EGP" << "\t\t quantity:  " << cart[i].Quantity << "\t\ttotal: " << cart[i].pro.get_price() * cart[i].Quantity << " EGP" << endl;
		cout << "\n--------------------------------------------------------------------------------------------------------\n";
		cout << endl;
	}
	if (totalPrice >= 1000)
	{
		cout << "Discount 5%: " << totalPrice * 0.05 << " EGP\n";
		totalPrice -= (totalPrice*0.05);
	  
	}
	cout << "Delivery Service: " << receipt.get_shipment_price() << " EGP\n";
	cout << "Total payment: " << totalPrice + receipt.get_shipment_price() << " EGP\n";
	cout << "Have a nice day....."<<"\n";
	while (!cart.empty())
	{
		cart.pop_back();
	}
}

void Customer::Cancel(vector<Product>& products)
{
	for (int j = 0; j < cart.size(); j++) {
		for (int i = 0; i < products.size(); i++)
		{
			if (cart[j].pro.get_id() == products[i].get_id())
			{
				products[i].set_quantity(products[i].get_quantity() + cart[j].Quantity);
				break;
			}
		}
	}
	while (!cart.empty())
	{
		cart.pop_back();
	}
	
}