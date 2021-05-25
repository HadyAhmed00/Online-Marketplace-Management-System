#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Seller.h"	

using namespace std;
void main()
{
	cout << "hady 1.24";
	vector <Customer> customers; //all customers in system
	vector <Product> products; //all products in system
	vector <Seller> sellers; //all sellers in system
	int choice;   //this variable is entered by the user to choose his navigation
	cout << "Online Marketplace Management System\n";
	cout << "***********Welcome to Our Marketplace! :)*************\n";
	cout << "Press-->1 To Login \n";
	cout << "Press-->2 For Registration \n";


	cout << "somthing randam\n";

	do {
		cout << "Enter your Choice: ";cin >> choice;
	} while (choice != 1 && choice != 2);
	
}