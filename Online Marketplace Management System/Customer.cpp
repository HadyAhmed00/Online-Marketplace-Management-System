#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;
static int ID = 1000;
Customer::Customer() {

}


Customer::Customer(string name, string email, string address, string phone, string password, vector <Product>& pros)
{
    ID++;
    per_id = ID;
    per_name = name;
    per_email = email;
    this->address = address;
    this->phone_number = phone;
    per_password = password;
	products = pros;
}


//add to cart function: add product to customer cart
void Customer::Add_to_cart(Product& product)
{
	system("cls");
	int choice;
	int quantity;
	cout << "please enter quantity: "; cin >> quantity;
	if (quantity > product.get_quantity())
	{
		cout << "Sorry this quantity is unavailable right now\n";
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
			cout << "Now you have " << cart[index].Quantity << " " << product.get_name() << "s\n";
		}
		else
		{
			product_struct temp;
			temp.pro = product;
			temp.Quantity = quantity;
			cart.push_back(temp);
			product.set_quantity(product.get_quantity() - quantity);
			cout << "\""<<product.get_name()<<"\""<<" has been added to your cart successfully \n\n";
		}
	}
	cout << "Press-->1 to add more quantity of this product\n";
	cout << "Press-->2 to search for another product\n";
	cout << "Press-->3 to go to customer menu\n";
	cout << "Press-->4 to Log Out\n";
	cin >> choice;
	switch (choice) {
	case 1:
		Add_to_cart(product);
		break;
	case 2:
		search_by_name();
		break;
	case 3:
		customer_menu();
		break;
	case 4:
		cout << "Logging out.........\n";
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		system("pause");
		show_all_products();
	}
	
}

void Customer::customer_menu()
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
    switch (choice) {
    case 1:
        display_cart_products();
        break;
    case 2:
        display_category_products("A");
        break;
    case 3:
		display_category_products("B");
        break;
    case 4:
		display_category_products("C");
        break;
    case 5:
		display_category_products("D");
        break;
    case 6:
		show_all_products();
        break;
    case 7:
		search_by_name();
        break;
    case 8:
        cout << "Logging out.......\n";
        break;
    default:
        cout << "Incorrect entry..Please try again!!!\n";
		system("pause");
		customer_menu();
        break;
    }
    
}

// search for a product by entering its name
void Customer::search_by_name() {
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
		switch (choice) {
		case 1:
			Add_to_cart(products[index]);
			break;
		case 2:
			search_by_name();
			break;
		case 3:
			customer_menu();
			break;
		case 4:
			cout << "Logging out.........\n";
			break;
		default:
			cout << "Invalid Entry...please try again!\n";
			display_cart_products();
		}
        
    }
    else
    {
        cout << "Product is not found\n";
		cout << "\n\n";
		int choice;
		cout << "Press-->1 to stay on this page\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to Log Out\n";

		cin >> choice;
		switch (choice) {
		case 1:
			search_by_name();
			break;
		case 2:
			customer_menu();
			break;
		case 3:
			cout << "Logging out.........\n";
			break;
		default:
			cout << "Invalid Entry...please try again!\n";
			display_cart_products();
		}
    }
	/*cout << "\n\n";
	int choice;
	cout << "Press-->1 to Add this product to cart\n";
	cout << "Press-->2 to stay on this page\n";
	cout << "Press-->3 to go back\n";
	cout << "Press-->4 to Log Out\n";
	
	cin >> choice;
	switch (choice) {
	case 1:
		Add_to_cart(products[index]);
		break;
	case 2:
		search_by_name();
		break;
	case 3:
		customer_menu();
		break;
	case 4:
		cout << "Logging out.........\n";
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		display_cart_products();
	}*/

}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(int ind)
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
	switch (choice) {
	case 1:
		remove_from_cart(ind);
		break;
	case 2:
		customer_menu();
		break;
	case 3:
		cout << "Logging out.........\n";
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		display_cart_products();
	}
}
//display all elements in cart
void Customer::display_cart_products()
{
	system("cls");
    int choice;
    if (cart.size() == 0) {
        cout << "Your cart is empty now \n\n\n";
		cout << "Press-->1 to search for a product to add it to your cart\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to Log Out\n";

		cin >> choice;
		switch (choice) {
		case 1:
			search_by_name();
			break;
		case 2:
			customer_menu();
			break;
		case 3:
			cout << "Logging out.........\n";
			break;
		default:
			cout << "Invalid Entry...please try again!\n";
			system("pause");
			display_cart_products();
		}
    }
    else {
		for (int i = 0; i < cart.size(); i++)
		{
			cout << i + 1 << "-  " << "product name: " << cart[i].pro.get_name() << "\t\t quantity:  " << cart[i].Quantity << endl;
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
		}
			cout << "Press-->1 to search for a product to add it to your cart\n";
			cout << "Press-->2 to remove products from your cart\n";
			cout << "Press-->3 to go back\n";
			cout << "Press-->4 to Log Out\n";

			cin >> choice;
			switch (choice) {
			case 1:
				search_by_name();
				break;
			case 2:
				cout << "\nPlease enter the product number to remove it\n";
				int n;
				cin >> n;
				n = n - 1;
				remove_from_cart(n);
				break;
			case 3:
				customer_menu();
				break;
			case 4:
				cout << "Logging out.........\n";
				break;
			default:
				cout << "Invalid Entry...please try again!\n";
				system("pause");
				display_cart_products();
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

void Customer::display_category_products( string cat)
{
	system("cls");
	int choice;
    bool isfound = false;
    int index;
	int quantity_check;
	cout << "\n\n";
	cout <<"\t\t\t---------- Category " << cat << " ----------\n\n";
    for (int i = 0; i < products.size(); i++)
    {
		if (cat == products[i].get_category() && products[i].get_quantity())
		{
			/*quantity_check = products[i].get_quantity();*/

			cout << "Product Number: " << i <<" ";
			products[i].product_info();
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
			cout << endl;
			isfound = true;
			continue;
		}
    }
	if (isfound) {

	}
	else {
		cout << "There are no available products of this category right now :(\n\n";
	}
	cout << "Press-->1 to Add product to cart\n";
	cout << "Press-->2 to go back\n";
	cout << "Press-->3 to Log Out\n";
	
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "\nPlease enter the product number to add it to your cart\n";
		cin >> choice;
		Add_to_cart(products[choice]);
		break;
	case 2:
		customer_menu();
		break;
	case 3:
		cout << "Logging out.........\n";
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		system("pause");
		display_category_products(cat);
	}

}

void Customer::show_all_products()
{
	system("cls");
	int choice;
	bool isFound = false;
	int displayed_numbers=1;
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].get_quantity() != 0) {
			cout << endl;
			cout << i+1 << "- ";
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
	switch (choice) {
	case 1:
		cout << "\nPlease enter the product ID to add it to your cart\n";
		cin >> choice;
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i].get_id() == choice) {
				Add_to_cart(products[i]);
				cout << "\"" << products[i].get_name() << "\"" << " has been added to your cart successfully \n";
				isFound = true;
				break;
			}
		}
		if (isFound == false) {
			cout << "The product ID your have entered is not found\n";
			system("pause");
			show_all_products();
		}
		break;
	case 2:
		customer_menu();
		break;
	case 3:
		cout << "Logging out.........\n";
		break;
	
	default:
		cout << "Invalid Entry...please try again!\n";
		system("pause");
		show_all_products();
	}
}
