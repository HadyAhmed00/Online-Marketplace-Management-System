#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Seller.h"    
#include "Person.h"
#include <conio.h>
#include<string>
#include"Validation.h"
using namespace std;
//------------------ global vars and vectors ------------------

vector <Customer> customers; //all customers in system
vector <Product> products; //all products in system
vector <Seller> sellers; //all sellers in system

//-------------------------function declaration --------------------
string password();
void control(Person, vector <Customer>&, vector <Seller>&);
void Registration();
void login(Person, vector <Customer>&, vector <Seller>&);

int main()
{
    

    Product p1(1, 5, 15, "phone", "a");
    Product p2(5, 5, 15, "android", "b");
    Product p3(5, 5, 15, "mak", "a");
    Product p4(5, 5, 15, "lenovo", "c");

    Person per;
    //customers
    //the information for the first customer
    Customer c1("Customer1",			       //Name
				"Customer1@gmail.com",		  //Email
				"Customer1 adress",			 //adress
				"phone1",				    //phone
				"pass1");				   //passwod

	//the information for the second customer
    Customer c2("Customer2",                 //Name
				"Customer2@gmail.com", 	    //Email
				"Customer1 adress",		   //adress
				"phone2", 				  //phone
				"pass2");				 //passwod
    //save the data
    customers.push_back(c1);
    customers.push_back(c2);
    //sellers

    //the information for the first seller
    Seller s1("Seller1", //Name
			  "Seller1@gmail.com","pass3"); //NO NEED TO THIS IN SELLER

    //the information for the second seller
    Seller s2("Seller2",  //Name
			  "Seller2@gmail.com","pass4");	//NO NEED TO THIS IN SELLER
    //save the data
    sellers.push_back(s1);
    sellers.push_back(s2);
    //to display the data in seller and customer vector
    for (int i = 0; i < sellers.size(); i++)
        cout << sellers[i].get_name() << "\t\t" <<
				sellers[i].get_password() << "\t\t" <<
				sellers[i].get_id() <<"\t\t" << 
				sellers[i].get_email() << "\t\t" << 
				sellers[i].get_address() << "\t\t" << 
				sellers[i].get_phoneNum() << endl;

    for (int i = 0; i < customers.size(); i++)
        cout << customers[i].get_name() << "\t" << 
				customers[i].get_password() << "\t\t" << 
				customers[i].get_id() << "\t\t" << 
				customers[i].get_email() << "\t\t" <<
				customers[i].get_address() << "\t" << 
				customers[i].get_phoneNum() << endl;

   

    cout << "\n\n\n";
    cout << "Online Marketplace Management System\n";
    cout << "***********Welcome to Our Marketplace! :)*************\n";
    int N_num;
    bool isValid=true;
    while (true) {
        if (isValid) {
            control(per, customers, sellers);
        }
        cout << "please press 1 to continue\n";
        cout << "please press 2 to exit\n";
        cin >> N_num;
        if (N_num == 1)
        {
            isValid=true;
        }
        else if (N_num == 2)
        {
            return 0;
        }
        else
        {
            isValid = false;
            cout << "Invalid\n";
        }
    }
    system("pause");
    return 0;

}

//------------------- function Defenation --------------------
//password function
string password() {
	char pass[50];
	int num = 0;
	cout << "Enter the password: \n";
	while (pass[num - 1] != '\r')// what does \r mean
	{
		pass[num] = _getch();
		if (pass[num - 1] != '\r')
		{
			cout << "*";
		}
		num++;
	}
	pass[num - 1] = '\0';
	string s = pass;
	return s;
}

//for asking the user if he want to login or regist
void control(Person per, vector <Customer>& customers, vector <Seller>& sellers)
{
    //Person p;
    int choice;   //this variable is entered by the user to choose his navigation 
    cout << "please enter number :\n";
    cout << "1-Login\t" << "2-Registration\n";
    cin >> choice;
    if (choice == 1)
    {
        login(per, customers, sellers);
    }
    else if (choice == 2)
    {
        Registration();

        for (int i = 0; i < sellers.size(); i++)
            cout << sellers[i].get_name() << "\t\t" << 
					sellers[i].get_password() << "\t\t" <<
					sellers[i].get_id() << "\t\t" <<
					sellers[i].get_email() << "\t\t" << 
					sellers[i].get_address() << "\t\t" << 
					sellers[i].get_phoneNum() << endl;

        for (int i = 0; i < customers.size(); i++)
            cout << customers[i].get_name() << "\t" << 
					customers[i].get_password() << "\t\t" <<
					customers[i].get_id() << "\t\t" <<
					customers[i].get_email() << "\t\t" <<
					customers[i].get_address() << "\t" << 
					customers[i].get_phoneNum() << endl;
    }
    else
    {
        cout << "please enter the correct number ....\n";
        control(per, customers, sellers);
    }
}

//regestration function
void Registration()
{
	int number;
	string setName, setPass, setAdd, setEmail, setPhone;
	cout << "please press 1 for seller\n";
	cout << "please press 2 for customer\n";
	cin >> number;
	if (number == 1 || number == 2)
	{
		cout << "Enter your Name :  \n";
		cin.ignore();
		getline(cin, setName);

		setPass = Validation::passwordValidation();

		setEmail = Validation::emailValidation();

		if (number == 2)
		{
			cout << "Enter your Phone Number :  \n";
			cin.ignore();
			getline(cin, setPhone);

			cout << "Enter your Address :  \n";
			cin.ignore();
			getline(cin, setAdd);
			Customer tmpCustomer(setName, setEmail, setAdd, setPhone, setPass); //temparaory create for customer
			customers.push_back(tmpCustomer);
		}
		else if (number == 1)
		{
			Seller tmpSeller(setName, setEmail,setPass);//temparaory creat for seller
			sellers.push_back(tmpSeller);
		}
	}
	else
	{
		cout << "invaled input\n";
		Registration();
	}
}

//login functiom
void login(Person per, vector <Customer>& customers, vector <Seller>& sellers)
{
    bool check = false;
    int person_id;
    //string setEmail;
    string person_email;
    string person_password;
    cout << "Enter your ID :  \n";
    cin >> person_id;
    cout << "Enter your Email :  \n";
    cin >> person_email;
    person_password = password();
    if (person_id >= 100 && person_id < 1000)
    {
        for (int i = 0; i < sellers.size(); i++)
        {
            if (person_email == sellers[i].getEmail() && 
				person_password == sellers[i].get_password())
            {
                cout << "\nhello , " << sellers[i].get_name() << endl;
                sellers[i].seller_menu();
                check = true;
                i = 0; //why put i = 0
                break;
            }
            check = false; //why put check = false
        }
        if (check == false)
        {
            cout << "\nYour Email or Password is invalid \nPlease try again\n";
            login(per, customers, sellers);
            // break;
        }
    }
    else if (person_id >= 1000)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (person_email == customers[i].get_email() && 
				person_password == customers[i].get_password())
            {
                cout << "\nhello, " << customers[i].get_name() << endl;
                customers[i].customer_menu();
                check = true;
                i = 0;
                break;
            }
            check = false;
        }
        if (check == false)
        {
            cout << "\nYour Email or your Password is invalid \nPlease try again\n";
            login(per, customers, sellers);
            // break;
        }
    }

}
