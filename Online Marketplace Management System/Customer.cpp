#include "Customer.h"
#include "Receipt.h"
#include <iostream>
#include <string>
using namespace std;
static int ID = 1000;
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
void Customer::Add_to_cart(Product& product,vector<Product>&products)
{
	system("cls");
	int choice;
	int quantity;
	cout << "please enter quantity: "; cin >> quantity;
	cin.ignore();
	if (quantity > product.get_quantity())
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Sorry this quantity is unavailable right now\n";
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
			else
				found = false;
		}
		if (found)
		{
			cart[index].Quantity += quantity;
			product.set_quantity(product.get_quantity() - quantity);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Now you have " << cart[index].Quantity << " " << product.get_name() << "s\n";
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
	cout << "Press-->4 to Log Out\n";
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1:
		Add_to_cart(product, products);
		break;
	case 2:
		search_by_name(products);
		break;
	case 3:
		customer_menu(products);
		break;
	case 4:
		cout << "Logging out.........\n";
		break;
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		show_all_products(products);
	}
	
}

void Customer::customer_menu(vector<Product>&products)
{
	system("cls");
    int choice;
	int quantity;
    string cat = "no cat";
    cout << "\t\t\t\t\t*******************Customer Menu*******************\n\n";
    cout << "Press 1 to go to cart\n\n";
    cout << "Press 2 to show products of Category A\n\n";
    cout << "Press 3 to show products of Category B\n\n";
    cout << "Press 4 to show products of Category C\n\n";
    cout << "Press 5 to show products of Category D\n\n";
    cout << "Press 6 to show all products\n\n";
    cout << "Press 7 to search for a product by its name\n\n";
    cout << "Press 8 to Log Out\n\n";
    cin >> choice;
	cin.ignore();
    switch (choice) {
    case 1:
		display_cart_products(products);
        break;
    case 2:
		display_category_products("A", products);
        break;
    case 3:
		display_category_products("B", products);
        break;
    case 4:
		display_category_products("C",products);
        break;
    case 5:
		display_category_products("D", products);
        break;
    case 6:
		show_all_products(products);
        break;
    case 7:
		search_by_name(products);
        break;
    case 8:
        cout << "Logging out.......\n";
        break;
    default:
		SetConsoleTextAttribute(hConsole, 4);
        cout << "Incorrect entry..Please try again!!!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		customer_menu(products);
        break;
    }
    
}

// search for a product by entering its name
void Customer::search_by_name(vector<Product>&products) {
	system("cls");
    bool isFound = false;
    int index;
	string Name;
	cout << "\nPlease enter product name: \n\n";
	cin.ignore();
	getline(cin, Name);
	
	//char arr[] = Name ;
	for (int x = 0; x < Name.length(); x++)
		Name[x]= tolower(Name[x]);
	
	
    for (int i = 0; i < products.size(); i++)
    {
		for (int x = 0; x < products[i].get_name().length(); x++)
		{

			products[i].get_name()[x] = tolower(products[i].get_name()[x]);
		}

		if (Name== products[i].get_name())
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
        products[index].product_info();
        cout << endl;
		cout << "\n\n";
		int choice;
		cout << "Press-->1 to Add this product to cart\n";
		cout << "Press-->2 to stay on this page\n";
		cout << "Press-->3 to go back\n";
		cout << "Press-->4 to Log Out\n";

		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			Add_to_cart(products[index], products);
			break;
		case 2:
			search_by_name(products);
			break;
		case 3:
			customer_menu(products);
			break;
		case 4:
			cout << "Logging out.........\n";
			break;
		default:
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid Entry...please try again!\n";
			SetConsoleTextAttribute(hConsole, 15);
			display_cart_products(products);
		}
        
    }
    else
    {
		SetConsoleTextAttribute(hConsole, 4);
        cout << "Product is not found\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n";
		int choice;
		cout << "Press-->1 to stay on this page\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to Log Out\n";

		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			search_by_name(products);
			break;
		case 2:
			customer_menu(products);
			break;
		case 3:
			cout << "Logging out.........\n";
			break;
		default:
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid Entry...please try again!\n";
			SetConsoleTextAttribute(hConsole, 15);
			display_cart_products(products);
		}
    }
	

}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(int ind, vector<Product>&products)
{
    bool isFound = false;
    int index;
	int id;
	id = cart[ind].pro.get_id();
    
	for (int i = 0; i < products.size(); i++)
	{
		if (id == products[i].get_id())
		{
			products[i].set_quantity(products[i].get_quantity() + cart[ind].Quantity);
			cout << "\nproduct has been removed from your cart\n";
			break;
		}
	}
	cart.erase((cart.begin() + ind));
	cout << "\n\n";
	int choice;
	cout << "Press-->1 to stay on this page\n";
	cout << "Press-->2 to go back\n";
	cout << "Press-->3 to Log Out\n";
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1:
		remove_from_cart(ind, products);
		break;
	case 2:
		customer_menu(products);
		break;
	case 3:
		cout << "Logging out.........\n";
		break;
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		display_cart_products(products);
	}
}
//display all elements in cart
void Customer::display_cart_products(vector<Product>&products)
{
	system("cls");
    int choice;
	bool isfound=false;
	int n;
    if (cart.size() == 0) {
		SetConsoleTextAttribute(hConsole, 1);
        cout << "Your cart is empty now \n\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Press-->1 to search for a product to add it to your cart\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to Log Out\n";

		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:
			search_by_name(products);
			break;
		case 2:
			customer_menu(products);
			break;
		case 3:
			cout << "Logging out.........\n";
			break;
		default:
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid Entry...please try again!\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			display_cart_products(products);
		}
    }
    else {
		for (int i = 0; i < cart.size(); i++)
		{
			cout << i + 1 << "-  " << "product name: " << cart[i].pro.get_name() <<"\t\tprice: "<< cart[i].pro.get_price()<<" EGP" << "\t\t quantity:  " << cart[i].Quantity <<"\t\ttotal: "<< cart[i].pro.get_price()* cart[i].Quantity <<" EGP" << endl;
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
		}
			cout << "Press-->1 to search for a product to add it to your cart\n";
			cout << "Press-->2 to remove products from your cart\n";
			cout << "Press-->3 to go back\n";
			cout << "Press-->4 to confirm\n";
			cout << "Press-->5 to cancel\n";
			cout << "Press-->6 to Log Out\n";

			cin >> choice;
			cin.ignore();
			switch (choice) {
			case 1:
				search_by_name(products);
				break;
			case 2:
				cout << "\nPlease enter the product ID to remove it\n";
				cin >> n;
				cin.ignore();
				for (int i = 0; i < cart.size(); i++)
				{
					if (cart[i].pro.get_id() == n) {
						remove_from_cart(i, products);
						SetConsoleTextAttribute(hConsole, 10);
						cout << "the product has been removed from your cart successfully \n";
						SetConsoleTextAttribute(hConsole, 15);
						isfound = true;
						break;
					}
				}
				if (isfound == false) {
					SetConsoleTextAttribute(hConsole, 4);
					cout << "The product ID your have entered is not found\n";
					SetConsoleTextAttribute(hConsole, 15);
					system("pause");
					display_cart_products(products);
				}
				break;
			case 3:
				customer_menu(products);
				break;
			case 4:
				display_Receipt();
				break;
			case 5:
				Cancel(products);

				break;
			case 6:
				cout << "Logging out.........\n";
				break;
			default:
				SetConsoleTextAttribute(hConsole, 4);
				cout << "Invalid Entry...please try again!\n";
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				display_cart_products(products);
			}
    }
	///*cout << "Press-->1 to add products to your cart\n";*/
	//cout << "Press-->1 to remove products from your cart\n";
 //   cout << "Press-->2 to go back\n";
 //   cout << "Press-->3 to Log Out\n";
	//
 //   cin >> choice;
 //   switch (choice) {
	//case 1:
	//	cout << "\nPlease enter the product number to remove it\n";
	//	int n;
	//	cin >> n;
	//	n = n - 1;
	//	remove_from_cart(n);
	//	break;
 //   case 2:
 //       customer_menu();
 //       break;
 //   case 3:
 //       cout << "Logging out.........\n";
 //       break;
 //   default:
 //       cout << "Invalid Entry...please try again!\n";
	//	system("pause");
 //       display_cart_products();
 //   }

   
}

void Customer::display_category_products(string cat, vector<Product>&products)
{
	system("cls");
	int choice;
    bool isfound = false;
    int index;
	int pro_num = 1;
	int quantity_check;
	cout << "\n\n";
	cout <<"\t\t\t---------- Category " << cat << " ----------\n\n";
    for (int i = 0; i < products.size(); i++)
    {
		if (cat == products[i].get_category() && products[i].get_quantity()!=0)
		{
			
			/*quantity_check = products[i].get_quantity();*/

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
	cout << "Press-->3 to Log Out\n";
	
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1:
		cout << "\nPlease enter the product ID to add it to your cart\n";
		cin >> choice;
		cin.ignore();
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].get_id() == choice) {
				Add_to_cart(products[i], products);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\"" << products[i].get_name() << "\"" << " has been added to your cart successfully \n";
				SetConsoleTextAttribute(hConsole, 15);
				isfound = true;
				break;
			}
		}
		if (isfound == false) {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "The product ID your have entered is not found\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			show_all_products(products);
		}
		
		break;
	case 2:
		customer_menu(products);
		break;
	case 3:
		cout << "Logging out.........\n";
		break;
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		display_category_products(cat,products);
	}

}

void Customer::show_all_products(vector<Product>&products)
{
	system("cls");
	int choice;
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
	cout << "Press-->3 to Log Out\n";
	
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1:
		cout << "\nPlease enter the product ID to add it to your cart\n";
		cin >> choice;
		cin.ignore();
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].get_id() == choice) {
				Add_to_cart(products[i], products);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\"" << products[i].get_name() << "\"" << " has been added to your cart successfully \n";
				SetConsoleTextAttribute(hConsole, 15);
				isFound = true;
				break;
			}
		}
		if (isFound == false) {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "The product ID your have entered is not found\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			show_all_products(products);
		}
		break;
	case 2:
		customer_menu(products);
		break;
	case 3:
		cout << "Logging out.........\n";
		break;
	
	default:
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid Entry...please try again!\n";
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		show_all_products(products);
	}
}

void Customer::display_Receipt()
{
	float totalPrice=0;
	for (int i = 0; i < cart.size(); i++) {
		totalPrice += cart[i].pro.get_price() * cart[i].Quantity;
	}
	Receipt receipt(*this,totalPrice);
	cout << "\t\t\t\t\t************ Wellcome! ************\n\n\n" << "Receipt Id: " << receipt.get_id() << "\n\n";

	for (int i = 0; i < cart.size(); i++)
	{
		cout << i + 1 << "-  " << "product name: " << cart[i].pro.get_name() << "\t\tprice: " << cart[i].pro.get_price() << " EGP" << "\t\t quantity:  " << cart[i].Quantity << "\t\ttotal: " << cart[i].pro.get_price() * cart[i].Quantity << " EGP" << endl;
		cout << "\n--------------------------------------------------------------------------------------------------------\n";
		cout << endl;
	}
	cout << "total payment: " << totalPrice << " EGP\n";
	cout << "Have a nice day....."<<"\n";
}

void Customer::Cancel(vector<Product>& products)
{
	//for (int i = 0; i < products.size(); i++)
	//{
	//	if (cart[i].pro.get_id() == products[i].get_id())
	//	{
	//		products[i].set_quantity(products[i].get_quantity() + cart[cart[i].pro.get_id()].Quantity);
	//		cout << "\nproduct has been removed from your cart\n";
	//		break;
	//	}
	//		
	//	
	//}
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
	cout << "\nproduct has been removed from your cart\n";
}




//Customer::~Customer()
//{
//	cin.ignore();
//}
