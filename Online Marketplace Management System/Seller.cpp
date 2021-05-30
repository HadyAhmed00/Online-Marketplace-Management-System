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

void Seller::seller_menu(Admin & a,vector<Product> allproducts)
{
	string choice;
	cout << "************** Seller Menu ****************" << endl;
	cout << "Profit is " << profit << endl;
	cout << "Press-->1 To Add Product" << endl;
	cout << "Press-->2 To browse your Products" << endl;
	cout << "Press-->3 To Log Out" << endl;
	
	getline(cin ,choice);

	if(choice=="1")
		addPriduct(a,allproducts);
	else if (choice == "2")
		display_Seller_Products(allproducts,per_id,a);
	else if (choice == "3")
		//control function or Pop up "do you want to continue?"
		cout << "Logging out.....\n";
	else
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "Incorrect entry..Please try again!!!\n";
		SetConsoleTextAttribute(hConsole, 15);
		seller_menu(a, allproducts);
	}
		
		
	

}

// add the new product to the list of all products and to the list of the seller products
void Seller::addPriduct(Admin&admin,vector<Product>allproducts)
{
	string name = "unNamed";
	string cato = "no cat";
	int q;
	float price;
	string choic/*,choice2*/;
	bool done = false;
	bool done2 = false;
	cout << "************** Add Product form ********************\n";
	cout << "Enter Product name: ";
	/*cin.ignore();*/
	getline(cin, name);
	cout << "Enter The Product Price:";
	price=Validation::isFloat();
	cout << "Enter The Product Quantity:";
	q = Validation::isNumber();
	do
	{
		cout << "Choose The Product Category :- \n";
		cout << "1 --> Category A\n";
		cout << "2 --> Category B\n";
		cout << "3 --> Category C\n";
		cout << "4 --> Category D\n";
		getline(cin ,choic);
		if (choic == "1") {
			cato = "catA";
			done = true;
		}else if (choic == "2")
		{
			cato = "catB";
			done = true; 
		}
		else if (choic == "3")
		{
			cato = "catC";
			done = true; 
		}
		else if (choic == "4")
		{
			cato = "catD";
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
		cout << "Press-->3 to Log Out\n";
		getline(cin, choic);
		if (choic == "1") {
			done2 = true;
			addPriduct(admin, allproducts);
		}
		else if (choic == "2")
		{
			done2 = true;
			seller_menu(admin, allproducts);
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

void Seller::display_Seller_Products(vector<Product> allProducts, int sId,Admin &admin)
{
	string choice;
	bool done = false;
	vector<Product> tmp = getSellerProducts(allProducts, sId);
	cout << "----------------------------------\n";
	for (int i = 0; i < tmp.size(); i++)
	{
		/*cout << tmp[i].get_id() << " \t\t" << tmp[i].get_name() << " \t\t" << tmp[i].get_quantity() << "\n";*/
		tmp[i].product_info();
		cout << "\n\n";
	}
	do
	{
		cout << "Press-->1 to go back\n";
		cout << "Press-->2 to Log Out\n";
		getline(cin, choice);
		if (choice == "1") {
			done = true;
			seller_menu(admin, allProducts);
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
