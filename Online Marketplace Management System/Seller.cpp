#include "Seller.h"

static int ID = 1000;

Seller::Seller( string name, string email)
{
	per_id = ID;
	per_name = name;
	per_email = email;
	ID++;
}


												//----------   Getters	--------------------

//@return the person id  AKA (Seller ID)
int Seller::getId()
{
	return per_id;
}
//@return the person Name  AKA (Seller Name)
string Seller::getName()
{
	return per_name;
}
//@return the person Email  AKA (Seller Email)
string Seller::getEmail()
{
	return per_email;
}


												//----------------- Setters -------------------

//set the person Name  AKA (Seller Name)
void Seller::setName(string name_val)
{
	per_name = name_val;
}

//set the person Email  AKA (Seller Email)
void Seller::setEmail(string Email_val)
{
	per_email = Email_val;
}


												//-------- Seller functions ------------

void Seller::seller_menu()
{
	int choice;
	cout << "************** Seller Menu ****************" << endl;
	cout << "Profit is " << profit << endl;
	cout << "Press-->1 To Add Product" << endl;
	cout << "Press-->2 To browse Products" << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
			//addPriduct();
			break;
		case 2:
			cout << "not now yet";
			break;
		default:
			cout << "you are a mather fucker pich";
			break;
	}

}

// add the new product to the list of all products and to the list of the seller products
void Seller::addPriduct(Admin & admin)
{
	
	string name = "unNamed";
	string cato = "no cat";
	int q;
	float price;
	int choic;
	bool done = false;
	cout << "************** Add Product form ********************\n";
	cout << "Enter Porduct name: ";
	getline(cin, name);
	cout << "enter the product Price:";
	cin >> price;
	cout << "Enter teh producnt Quntataty:";
	cin >> q;
	do
	{
		cout << "choses The Product Category :- \n";
		cout << "1 --> Category A\n";
		cout << "2 --> Category B\n";
		cout << "3 --> Category C\n";
		cout << "4 --> Category D\n";
		cin >> choic;
		switch (choic)
		{
			case 1:
			{
				cato = "catA";

				done = true; break;
			}
			case 2:
			{
				cato = "catB";

				done = true; break;
			}
			case 3:
			{
				cato = "catC";

				done = true; break;
			}
			case 4:
			{
				cato = "catD";

				done = true; break;
			}
			default:
			{
				cout << "incalid choice try again";

				done = false; break;
			}
		}
	} while (!done);

	/*cout << "the product info thet you Enterd is :" << endl;
	cout << "Name:        " << name << endl;
	cout << "price:       " << price << endl;
	cout << "catogary is: " << cato << endl;
	cout << "quitity :    " << q << endl;*/
	//assinge the user enterd vals to the temp 
	Product tmp(per_id, q, price, name, cato);
	tmp.product_info();
	admin.Add_to_requested_products(tmp);
/*
	admin.Add_to_requested_products(tmp);*///call Add_to_requested_products function() in Admin class() 
}

//return the seller product list 
vector<Product> Seller::getSellerProducts(vector<Product> allProducts,int sId)
{
	vector<Product> tmp;
	for (int i = 0; i < allProducts.size(); i++)
	{
		if (allProducts[i].get_sellerId()==sId)
		{
			tmp.push_back(allProducts[i]);
		}
	}
	return tmp;
}

void Seller::display_Seller_Products(vector<Product> allProducts,int sId)
{
	vector<Product> tmp = getSellerProducts(allProducts, sId);
	cout << "Your Products is :\n______________________________\n";
	cout << "ID \t\tProduct Name \t \t Quntaty\n";
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i].get_id() << " \t\t" << tmp[i].get_name() << " \t\t" << tmp[i].get_quantity() << "\n";
	}
}

Seller::~Seller()
{
}