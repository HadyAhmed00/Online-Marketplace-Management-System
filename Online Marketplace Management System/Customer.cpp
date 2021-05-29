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
void Customer::Add_to_cart(Product& product, int quantity)
{
	system("cls");
	int choice;
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
        cout << "this product is already exist so the product quantity has been increased\n";
    }
    else
    {
        product_struct temp;
        temp.pro = product;
        temp.Quantity = quantity;
        cart.push_back(temp);
        product.set_quantity(product.get_quantity() - quantity);
        cout << "the product has been added to cart \n";
    }
	cout << "Press-->1 to go to customer menu\n";
	cout << "Press-->2 to Log Out\n";
	cin >> choice;
	switch (choice) {
	case 1:
		customer_menu();
		break;
	case 2:
		cout << "Logging out.........\n";
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
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
    cout << "Press 7 to search for a product by name\n\n";
    cout << "Press 8 to Log Out\n\n";
    /*cout << "Press 8 to go back\n";*/
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
        //search_by_name();
		search_by_name();
        break;
    case 8:
        cout << "Logging out.......\n";
        break;
    default:
        cout << "Incorrect entry..Please try again!!!\n";
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
	cout << "\nplease enter product name: \n\n";
	cin.ignore();
	getline(cin, Name);
    for (int i = 0; i < products.size(); i++)
    {
        if (Name == products[i].get_name())
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
        
    }
    else
    {
        
        cout << "product is not found\n";
    }
	cout << "\n\n";
	int choice;
	cout << "Press-->1 to go back\n";
	cout << "Press-->2 to Log Out\n";
	cout << "Press-->3 to Add to cart\n";
	cin >> choice;
	switch (choice) {
	case 1:
		customer_menu();
		break;
	case 2:
		cout << "Logging out.........\n";
		break;
	case 3:
		cout << "enter quanteity: "; cin >> choice;
		Add_to_cart(products[index], choice);
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		display_cart_products();
	}

}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(Product& product)
{
    bool isFound = false;
    int index;
    for (int i = 0; i < cart.size(); i++)
    {
        if (product.get_id() == cart[i].pro.get_id())
        {
            isFound = true;
            index = i;
            break;
        }
        else
        {
            continue;
        }
    }
    if (isFound)
    {
        product.set_quantity(product.get_quantity() + cart[index].Quantity);
        cart.erase((cart.begin() + index));

        cout << "the product " << cart[index].pro.get_name() << " has been removed\n";
    }
    else
    {
        cout << "This product" << cart[index].pro.get_name() << " is not found" << endl;
    }
}
//display all elements in cart
void Customer::display_cart_products()
{
	system("cls");
    int choice;
    if (cart.size() == 0) {
        cout << "Your cart is empty now \n";
    }
    else {
        for (int i = 0; i < cart.size(); i++)
        {
            cout << i+1<<"-  "<<"product name: "<<cart[i].pro.get_name() << "\t\t quantity:  " << cart[i].Quantity << endl;
			cout << "\n--------------------------------------------------------------------------------------------------------";
			cout << endl;
			
        }
    }
	
    cout << "Press-->1 to go back\n";
    cout << "Press-->2 to Log Out\n";
	cout << "Press-->3 to remove products\n";
    cin >> choice;
    switch (choice) {
    case 1:
        customer_menu();
        break;
    case 2:
        cout << "Logging out.........\n";
        break;
	case 3:
		cout << "\nplease enter the product numper to remove it\n";
		cin >> choice;
		remove_from_cart(cart[choice-1].pro);
		break;
    default:
        cout << "Invalid Entry...please try again!\n";
        display_cart_products();
    }

   
}

void Customer::display_category_products( string cat)
{
	system("cls");
	int choice;
	int quantity;
    bool isfound = false;
    int index;
	cout << "\n\n";
	cout <<"\t\t\t---------- Category " << cat << " ----------\n\n";
    for (int i = 0; i < products.size(); i++)
    {
        if (cat == products[i].get_category())
        {
			cout << i << "- ";
			products[i].product_info();;
			cout << "\n--------------------------------------------------------------------------------------------------------";
				cout<<endl;
            cout << endl;
            continue;
        }
        else
        {
            continue;
        }
    }
	cout << "Press-->1 to go back\n";
	cout << "Press-->2 to Log Out\n";
	cout << "Press-->3 to Add product to cart\n";
	cin >> choice;
	switch (choice) {
	case 1:
		customer_menu();
		break;
	case 2:
		cout << "Logging out.........\n";
		break;
	case 3:
		cout << "\nplease enter the product numper to Add it\n";
		cin >> choice;
		cout << "enter the quantity: "; cin >> quantity;
		Add_to_cart(products[choice], quantity);
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		display_category_products(cat);
	}

}

void Customer::show_all_products()
{
	system("cls");
	int choice;
	int quantity;
	for (int i = 0; i < products.size(); i++)
	{
		cout << endl;
		cout << i + 1 << "- ";
		products[i].product_info();
		cout << "\n--------------------------------------------------------------------------------------------------------";
		cout << endl;
	}
	cout << "Press-->1 to go back\n";
	cout << "Press-->2 to Log Out\n";
	cout << "Press-->3 to Add product to cart\n";
	cin >> choice;
	switch (choice) {
	case 1:
		customer_menu();
		break;
	case 2:
		cout << "Logging out.........\n";
		break;
	case 3:
		cout << "\nplease enter the product numper to Add it\n";
		cin >> choice;
		cout << "enter the quantity: "; cin >> quantity;
		Add_to_cart(products[choice - 1], quantity);
		break;
	default:
		cout << "Invalid Entry...please try again!\n";
		show_all_products();
	}
}
