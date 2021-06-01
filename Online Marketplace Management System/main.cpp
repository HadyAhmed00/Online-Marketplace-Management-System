#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Seller.h"    
#include "Person.h"
#include <conio.h>
#include <string>
#include <windows.h>
#include "Validation.h"
#include <sstream>
#include <fstream>
using namespace std;
//------------------ global vars and vectors ------------------

vector <Customer> customers; //all customers in system
vector <Product> products; //all products in system
vector <Seller> sellers; //all sellers in system
Admin admin("hadi","Admin2021@gmail.com");
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int current_user_index;
//-------------------------function declaration --------------------
string password();
void control();
void Registration();
void login();
void load_from_file();
void write_in_file();
int main()
{  
	load_from_file();
  
    cout << "\t\t\t\t\tOnline Marketplace Management System\n";
    cout << "\t\t***************************Welcome to Our Marketplace! :)**************************\n";
    string N_num;
    bool isValid=true;
    while (true) {
        if (isValid) {
            control();
        }
        cout << "please press 1 to continue\n";
        cout << "please press 2 to exit\n";

        getline(cin,N_num);
        if (N_num == "1")
        {
            isValid=true;
        }
        else if (N_num == "2")
        {
			write_in_file();
            return 0;
        }
        else
        {
            isValid = false;
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Invalid entry\n";
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
	
    system("pause");
    return 0;
}

//------------------- function Definition --------------------
//password function
string password() {
    string pass = "";
    char ch;
    cout << "Enter pass\n";
    ch = _getch();
    while (true)
    {
        if (ch == 13)//If the user presses enter --->break;
        {
            break;
        }
        if (ch == 127 || ch == 8)//If the user presses backspace  
        {
            if (!pass.empty())//such that the password is not empty
            {
                pass.pop_back();
                cout << "\b \b";//delete the char
            }
        }
        else 
        {
            pass.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    return pass;
}

//for asking the user if he want to login or register
void control()
{
    string choice;   //this variable is entered by the user to choose his navigation 
    cout << "please enter number :\n";
    cout << "1-Login\t" << "2-Registration\n";
    getline(cin, choice);
    if (choice == "1")
    {
        login();
    }
    else if (choice == "2")
    {
        Registration();
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Please enter the correct number ....\n";
        SetConsoleTextAttribute(hConsole, 15);
        control();
    }
}

//registration function
void Registration()
{
	string number;
	string setName, setPass, setAdd, setEmail, setPhone;
	cout << "please press 1 for seller\n";
	cout << "please press 2 for customer\n";
    getline(cin, number);
	if (number == "1" || number == "2")
	{
		cout << "Enter your Name :  \n";
		cin.ignore();
		getline(cin, setName);
        setEmail = Validation::emailValidation();
		setPass = Validation::passwordValidation();		

		if (number == "2")
		{
			
			setPhone = Validation::phoneValidation();
			cout << "Enter your Address :  \n";
			getline(cin, setAdd);
			while (setAdd == "")
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << "Invalid entry... \n";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "Enter your Address :  ";
				getline(cin, setAdd);
			}
			Customer tmpCustomer(setName, setEmail, setAdd, setPhone, setPass); //temparaory create for customer
            cout << "************************************\n";
            cout << "Your ID is: " << tmpCustomer.get_id() << endl;
            cout << "\n\n\n";
            cout << "************************************\n";
			customers.push_back(tmpCustomer);
		}
		else if (number == "1")
		{
			Seller tmpSeller(setName, setEmail,setPass);//temparaory creat for seller
            cout << "************************************\n";
            cout << "Your ID is: " << tmpSeller.get_id() << endl;
            cout << "\n\n\n";
            cout << "************************************\n";
			sellers.push_back(tmpSeller);
		}
	}
	else
	{
        SetConsoleTextAttribute(hConsole, 4);
		cout << "Invalid input\n";
        SetConsoleTextAttribute(hConsole, 15);
		Registration();
	}
}

//login functiom
void login()
{
    bool check = false;
    int person_id;
    int user_index;
    string person_email;
    string person_password;
    cout << "Enter your ID" << endl;
    person_id = Validation::isNumber();
    cout << "Enter your Email :  \n";
    getline(cin,person_email);

    person_password = password();
    if (person_id >= 100 && person_id < 1000)
    {
        for (int i = 0; i < sellers.size(); i++)
        {
            if (person_id==sellers[i].get_id() && person_email == sellers[i].get_email() && 
				person_password == sellers[i].get_password())
            {
                user_index = sellers[i].get_id();
               
                sellers[i].seller_menu(admin,products,user_index);
                check = true;
                break;
            }
            
        }
        if (check == false)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\nYour Email or Password is Invalid \nPlease try again\n";
            SetConsoleTextAttribute(hConsole, 15);
            login();
        }
    }
    else if (person_id >= 1000&&person_id <10000)
    {
        for (int i = 0; i < customers.size(); i++)
        {
			if (person_id == customers[i].get_id() && person_email == customers[i].get_email() &&
				person_password == customers[i].get_password())
            {				
				customers[i].customer_menu(products, sellers);
                check = true;
                break;
            }
    
        }
        if (check == false)
        {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\nYour Email or your Password is invalid \nPlease try again\n";
            SetConsoleTextAttribute(hConsole, 15);
            login();
        }
    }
	else if (person_id == admin.get_id() && person_email==admin.get_email() && person_password ==admin.get_password()) {
		admin.Accept_or_Reject(products);
    }
    else {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\n\nThe ID you have entered is not found \n\n";
        SetConsoleTextAttribute(hConsole, 15);
    }
}

void load_from_file()
{
	ifstream products_file ,sellers_file,customers_file;
	int i = 0,ca=0,se=0, j = 0,seller_size=0,customer_size=0;
	string pname, pcat, pid, pprice, pquantity, sellerid;
	string cid,cemail,caddress,cphone,cpass,cname;
	string sid, semail, spass, sname, sprofit;
	int idd, pricee, quantityy, selleridd,sprofitt;
	//opening the file to know its file
	products_file.open("mydata.txt");
	while (!products_file.eof())
	{
		getline(products_file, pid);
		j++;
	}
	products_file.close();
	j = j / 6;
//////////////////////////////////////////
	customers_file.open("customers data.txt");
	while (!customers_file.eof())
	{
		getline(customers_file, cid);
		customer_size++;
	}
	customers_file.close();
	customer_size = customer_size / 6;
////////////////////////////////////////////
	sellers_file.open("sellers data.txt");
	while (!sellers_file.eof())
	{
		getline(sellers_file, sid);
		seller_size++;
	}
	sellers_file.close();
	seller_size = seller_size / 5;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////   opening the file to load data from it 
	products_file.open("mydata.txt");
	while (i<j)
	{
		getline(products_file, pid);
		getline(products_file, pname);
		getline(products_file, pcat);
		getline(products_file, pprice);
		getline(products_file, pquantity);
		getline(products_file, sellerid);
		stringstream  geek1(pid);
		geek1 >> idd;
		stringstream  geek2(pprice);
		geek2 >> pricee;
		stringstream  geek3(pquantity);
		geek3 >> quantityy;
		stringstream  geek(sellerid);
		geek >> selleridd;
		Product p(selleridd, quantityy, pricee, pname, pcat);
		products.push_back(p);
		i++;
	}
	products_file.close();
////////////////////////////////////////////////////////////////////////////////////

	customers_file.open("customers data.txt");
	while (ca<customer_size)
	{
		getline(customers_file, cid);
		getline(customers_file, cname);
		getline(customers_file,cemail );
		getline(customers_file, caddress);
		getline(customers_file,cphone);
		getline(customers_file,cpass);
		stringstream  geek4(cid);
		geek4 >> idd;
		Customer c(cname, cemail, caddress, cphone, cpass);
		customers.push_back(c);
		ca++;
	}
	customers_file.close();
	////////////////////////////////////////////////////////
	sellers_file.open("sellers data.txt");
	while (se<seller_size)
	{
		getline(sellers_file, sid);
		getline(sellers_file, sname);
		getline(sellers_file, semail);
		getline(sellers_file, spass);
		getline(sellers_file, sprofit);
		stringstream  geek5(sid);
		geek5 >> idd;
		stringstream  geek6(sprofit);
		geek6 >> sprofitt;
		Seller s(sname, semail, spass);
		sellers.push_back(s);
		sellers[se].set_profit(sprofitt);
		se++;
	}
	sellers_file.close();
}
void write_in_file()
{
	ofstream file1, customer_file, seller_file;
	file1.open("mydata.txt");
	for (int i = 0; i < products.size(); i++)
	{
		file1 << products[i].get_id() << "\n" << products[i].get_name() << "\n" << products[i].get_category() << "\n" << products[i].get_price() << "\n" << products[i].get_quantity() << "\n" << products[i].get_sellerId() << endl;
	}
	file1.close();
	////////////////////////////////////////////////////////////////
	customer_file.open("customers data.txt");
	for (int i = 0; i < customers.size(); i++)
	{
		customer_file << customers[i].get_id() << "\n" << customers[i].get_name() << "\n" << customers[i].get_email() << "\n" << customers[i].get_address() << "\n" << customers[i].get_phoneNum() << "\n" << customers[i].get_password() << endl;
	}
	customer_file.close();
	////////////////////////////////////////////////////////////////
	seller_file.open("sellers data.txt");
	for (int i = 0; i < sellers.size(); i++)
	{
		seller_file << sellers[i].get_id() << "\n" << sellers[i].get_name() << "\n" << sellers[i].get_email() << "\n" << sellers[i].get_password() << endl<<sellers[i].get_profit()<<endl;
	}
	seller_file.close();
}