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
<<<<<<< HEAD
=======

	cout << "somthing randam\n";
>>>>>>> 8b8fa21cd4a6ceeea6d09456ed1597881d51a3b8
	do {
		cout << "Enter your Choice: ";cin >> choice;
	} while (choice != 1 && choice != 2);
	
}