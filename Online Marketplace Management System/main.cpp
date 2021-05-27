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

//password function
string password() {
    char pass[50];
    int num = 0;
    cout << "Enter the password: \n";
    while (pass[num - 1] != '\r')
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





void control(Person, vector <Customer>&, vector <Seller>&);
void Registration(Person, vector <Customer>&, vector <Seller>&);
void login(Person, vector <Customer>&, vector <Seller>&);

//start main<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main()
{
    vector <Customer> customers; //all customers in system
    vector <Product> products; //all products in system
    vector <Seller> sellers; //all sellers in system

    Product p1(1, 5, 15, "phone", "a");
    Product p2(5, 5, 15, "android", "b");
    Product p3(5, 5, 15, "mak", "a");
    Product p4(5, 5, 15, "lenovo", "c");

    Person per;

    //customers
    //the information for the first customer
    Customer c1("Customer1", "Customer1@gmail.com", "Customer1 adress", "phone1", "pass1");
    //the information for the second customer
    Customer c2("Customer2", "Customer2@gmail.com", "Customer1 adress", "phone2", "pass2");
    //save the data
    customers.push_back(c1);
    customers.push_back(c2);
    //sellers
    //the information for the first seller
    Seller s1("Seller1", "pass3", "Seller1@gmail.com", "phone3", "Seller1 adress");
    //the information for the second seller
    Seller s2("Seller2", "pass4", "Seller2@gmail.com", "phone4", "Seller2 adress");
    //save the data
    sellers.push_back(s1);
    sellers.push_back(s2);
    //to display the data in seller and customer vector
    for (int i = 0; i < sellers.size(); i++)
        cout << sellers[i].get_name() << "\t\t" << sellers[i].get_password() << "\t\t" << sellers[i].get_id() << "\t\t" << sellers[i].get_email() << "\t\t" << sellers[i].get_address() << "\t\t" << sellers[i].get_phoneNum() << endl;
    for (int i = 0; i < customers.size(); i++)
        cout << customers[i].get_name() << "\t" << customers[i].get_password() << "\t\t" << customers[i].get_id() << "\t\t" << customers[i].get_email() << "\t\t" << customers[i].get_address() << "\t" << customers[i].get_phoneNum() << endl;


    //#########################################################################################################################################################



    cout << "\n\n\n";
    cout << "Online Marketplace Management System\n";
    cout << "***********Welcome to Our Marketplace! :)*************\n";
    int N_num;

    control(per, customers, sellers);
    cout << "please press 1 for continue\n";
    cout << "please press 2 for exit\n";
    cin >> N_num;
    if (N_num == 1)
    {
        control(per, customers, sellers);
    }
    else if (N_num == 2)
    {
        return 0;
    }
    else
    {
        cout << "invalid\n";
    }
    system("pause");
    return 0;

}

//end main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


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
        Registration(per, customers, sellers);
        for (int i = 0; i < sellers.size(); i++)
            cout << sellers[i].get_name() << "\t\t" << sellers[i].get_password() << "\t\t" << sellers[i].get_id() << "\t\t" << sellers[i].get_email() << "\t\t" << sellers[i].get_address() << "\t\t" << sellers[i].get_phoneNum() << endl;
        for (int i = 0; i < customers.size(); i++)
            cout << customers[i].get_name() << "\t" << customers[i].get_password() << "\t\t" << customers[i].get_id() << "\t\t" << customers[i].get_email() << "\t\t" << customers[i].get_address() << "\t" << customers[i].get_phoneNum() << endl;
    }
    else
    {
        cout << " please enter the correct number ....\n";
        control(per, customers, sellers);

    }
}

//regestration function
void Registration(Person per, vector <Customer>& customers, vector <Seller>& sellers)
{


    int number, setID;
    string setName, setPass, setAdd, setEmail, setPhone;

    cout << "please press 1 for seller\n";
    cout << "please press 2 for customer\n";
    cin >> number;
    if (number == 1)
    {

        per.set_id(sellers.size() + 101);
        cout << "your ID is :  " << per.get_id() << endl;
        // ID_s++;
    }
    else if (number == 2)
    {
        per.set_id(customers.size() + 1001); ;
        cout << "your ID is :  " << per.get_id() << endl;
        //   ID_c++;
    }
    cout << "Enter your Name :  \n";
   // cin >> setName;
    cin.ignore();
    getline(cin, setName);
    per.set_name(setName);

    /* cout << "Enter your password :  \n";
     cin >> per.per_password;*/
    setPass = password();
    per.set_password(setPass);

    cout << "\nEnter your Email :  \n";
    cin.ignore();
    getline(cin, setEmail);
    per.set_email(setEmail);
    cout << "Enter your Phone number :  \n";
    cin.ignore();
    getline(cin, setPhone);
    per.set_phoneNum(setPhone);
    cout << "Enter your Adress :  \n";
    cin.ignore();
    getline(cin, setAdd);
    per.set_address(setAdd);

    if (number == 2)
    {
        Customer c(per.get_name(), per.get_email(), per.get_address(), per.get_phoneNum(), per.get_password()); //temparaory save for customer
        customers.push_back(c);
    }
    else if (number == 1)
    {
        Seller s(per.get_name(), per.get_password(), per.get_email(), per.get_phoneNum(), per.get_address());//temparaory save for seller
        sellers.push_back(s);
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
            if (person_email == sellers[i].getEmail() && person_password == sellers[i].get_password())
            {
                cout << "\nhello , " << sellers[i].get_name() << endl;
                check = true;
                i = 0;
                break;
            }
            check = false;

        }
        if (check == false)
        {
            cout << "\ninvalide your Email or your Password \nPlease try again\n";
            login(per, customers, sellers);
            // break;
        }
    }
    else if (person_id >= 1000)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (person_email == customers[i].get_email() && person_password == customers[i].get_password())
            {
                cout << "\nhello, " << customers[i].get_name() << endl;
                check = true;
                i = 0;
                break;
            }
            check = false;

        }
        if (check == false)
        {
            cout << "\ninvalide your Email or your Password \nPlease try again\n";
            login(per, customers, sellers);
            // break;
        }
    }

}
