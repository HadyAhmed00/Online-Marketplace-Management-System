#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Seller.h"
#include "Validation.h"
#include <string>

vector <Customer> customers; //all customers in system
vector <Product> products; //all products in system
vector <Seller> sellers; //all sellers in system
using namespace std;
void main()
{
	Seller s("hadi", "ayman");
	
	Admin admin("HFE", "hfe@gmail.com");
	Validation validate;
	Product p1(1, 5, 15, "phone", "a");
	Product p2(1000, 5, 15, "android", "b");
	Product p3(1000, 5, 15, "mak", "a");
	Product p4(5, 5, 15, "lenovo", "c");
	s.addPriduct(admin);
	
	//admin.Accept_or_Reject(products);
	for (int i = 0; i < products.size(); i++)
	{
		cout << products[i].get_name() << endl;
	}

	//int choice;   //this variable is entered by the user to choose his navigation
	//int id;

	//cout << "Online Marketplace Management System\n";
	//cout << "*********** Welcome to Our Marketplace! :)*************\n";
	//cout << "Press-->1 To Login \n";
	//cout << "Press-->2 For Registration \n";

	//do {
	//	cout << "Enter your Choice: ";cin >> choice;
	//} while (choice != 1 && choice != 2);
	//
	//if (choice == 1)
	//{
	//	cin >> id;
	//	string email = validate.emailValidation();
	//	if (id > 1000 && id < 2000)
	//	{
	//		
	//	}
	//}
	//else if (choice == 2)
	//{
	//	
	//}

}