#include "Seller.h"

static int ID = 100;

Seller::Seller()
{
}



Seller::Seller(string name, string email,string pass)
{
	ID++;
	per_id = ID;
	per_name = name;
	per_email = email;
	per_password = pass;
	
}

//-------- Seller functions ------------

float Seller::get_profit()
{
	return profit;
}

void Seller::set_profit(float pro)
{
	profit += pro;
}

void Seller::seller_menu(Admin & a,vector<Product> &allproducts,int user_index)
{
	system("cls");
	string choice;
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t\t\t\tHello , " << per_name << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t\t\t\t************** Seller Menu ****************\n\n" << endl;
	cout << "\tProfit is " << profit <<" EGP\n" <<endl;
	cout << "Press-->1 To Add a new product" << endl;
	cout << "Press-->2 to add quantity to an existing product" << endl;
	cout << "Press-->3 To browse your Products" << endl;
	cout << "Press-->4 To log out" << endl;
	
	getline(cin ,choice);

	if (choice == "1")
		addPriduct(a, allproducts, user_index);
	else if (choice == "2")
		add_more_quantity(allproducts,user_index,a);
	else if (choice == "3")
		display_Seller_Products(allproducts,per_id,a,user_index);
	else if (choice == "4")
		//control function or Pop up "do you want to continue?"
		cout << "Logging out.....\n";
	else
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Incorrect entry..Please try again!!!\n";
		SetConsoleTextAttribute(hConsole, 15);
		seller_menu(a, allproducts,user_index);
	}

}

void Seller::add_more_quantity(vector<Product>&products,int user_index,Admin &admin)
{
	int ID;
	int quantity;
	bool Found = false;
	string choic;
	bool done2 = false;
	int index;
	cout << "Enter the product ID you want to update its quantity\n";
	ID = Validation::isNumber();
	cout << "Enter the quantity you want to add\n";
	quantity = Validation::isNumber();
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].get_id()==ID&&products[i].get_sellerId()==user_index)
		{
			
			Found = true;
			index = i;
			break;
		}
	}
	if (Found)
	{
		products[index].set_quantity(products[index].get_quantity() + quantity);
		SetConsoleTextAttribute(hConsole, 10);
		cout << "The quantity has been added to the product successfully\n\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	else{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "The product ID you have entered is not found\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	do
	{
		cout << "Press-->1 to add more quantity to the product\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to log out\n";
		getline(cin, choic);
		if (choic == "1") {
			done2 = true;
			add_more_quantity(products,user_index,admin);
		}
		else if (choic == "2")
		{
			done2 = true;
			seller_menu(admin, products, user_index);
		}
		else if (choic == "3")
		{
			done2 = true;
			cout << "Logging out.....\n";
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid entry....try again\n";
			SetConsoleTextAttribute(hConsole, 15);
			done2 = false;
		}
	} while (!done2);

}

// add the new product to the list of all products and to the list of the seller products
void Seller::addPriduct(Admin&admin,vector<Product>allproducts,int user_index)
{
	string name = "unNamed";
	string cato = "no cat";
	int q;
	float price;
	string choic;
	bool done = false;
	bool done2 = false;
	cout << "************** Add Product form ********************\n";
	cout << "Enter Product name: ";
	getline(cin, name);
	cout << "Enter The Product Price:";
	price=Validation::isFloat();
	cout << "Enter The Product Quantity:";
	q = Validation::isNumber();
	do
	{
		cout << "Choose The Product Category :- \n";
		cout << "1 --> Appliances \n";
		cout << "2 --> Books \n";
		cout << "3---> Fashion \n";
		cout << "4 --> Food & Beverage \n";
		cout << "5 --> SmartPhones, Laptops and Accessories \n";
		getline(cin ,choic);
		if (choic == "1") {
			cato = "Appliances";
			done = true;
		}else if (choic == "2")
		{
			cato = "Books";
			done = true; 
		}
		else if (choic == "3")
		{
			cato = "Fashion";
			done = true; 
		}
		else if (choic == "4")
		{
			cato = "Food & Beverage";
			done = true; 
		}
		else if (choic == "5")
		{
			cato = "SmartPhones, Laptops and Accessories";
			done = true;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid Choice!!....try again!!";
			SetConsoleTextAttribute(hConsole, 15);
			done = false;
		}
	} while (!done);

   //assign the user entered vals to the temp
	Product tmp(per_id, q, price, name, cato);
	tmp.product_info();
	admin.Add_to_requested_products(tmp);
	do
	{
		cout << "Press-->1 to add another product\n";
		cout << "Press-->2 to go back\n";
		cout << "Press-->3 to log out\n";
		getline(cin, choic);
		if (choic == "1") {
			done2 = true;
			addPriduct(admin, allproducts,user_index);
		}
		else if (choic == "2")
		{
			done2 = true;
			seller_menu(admin, allproducts,user_index);
		}
		else if (choic == "3")
		{
			done2 = true;
			cout << "Logging out.....\n";
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid entry....try again\n";
			SetConsoleTextAttribute(hConsole, 15);
			done2 = false;
		}
	} while (!done2);
	
}

//return the seller product list
vector<Product> Seller::getSellerProducts(vector<Product> allProducts, int sId)
{
	vector<Product> tmp;
	for (int i = 0; i < allProducts.size(); i++)
	{
		if (allProducts[i].get_sellerId() == sId)
		{
			tmp.push_back(allProducts[i]);
		}
	}
	return tmp;
}

void Seller::display_Seller_Products(vector<Product> allProducts, int sId, Admin& admin, int user_index)
{
	string choice;
	bool done = false;
	vector<Product> tmp = getSellerProducts(allProducts, sId);
	cout << "----------------------------------\n";
	if (tmp.size() != 0){
		for (int i = 0; i < tmp.size(); i++)
		{
			tmp[i].product_info();
			cout << "\n\n";
		}
    }

	else {
		
		SetConsoleTextAttribute(hConsole, 11);
		cout << "You haven't added any products yet\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	do
	{
		cout << "Press-->1 to go back\n";
		cout << "Press-->2 to log out\n";
		getline(cin, choice);
		if (choice == "1") {
			done = true;
			seller_menu(admin, allProducts, user_index);
		}
		else if (choice == "2")
		{
			done = true;
			cout << "Logging out.....\n";
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid entry....try again\n";
			SetConsoleTextAttribute(hConsole, 15);
			done = false;
		}
	} while (!done);
	
}

Seller::~Seller()
{

}