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
	int choice;
	cout << "************** Seller Menu ****************" << endl;
	cout << "Profit is " << profit << endl;
	cout << "Press-->1 To Add Product" << endl;
	cout << "Press-->2 To browse your Products" << endl;
	cout << "Press-->3 To Log Out" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		addPriduct(a);
		break;
	case 2:
		display_Seller_Products(allproducts,per_id);
		break;
	case 3:
		//control function or Pop up "do you want to continue?"
		break;
	default:
		cout << "Incorrect entry..Please try again!!!\n";
		seller_menu(a,allproducts);
		break;
	}

}

// add the new product to the list of all products and to the list of the seller products
void Seller::addPriduct(Admin&admin)
{
	string name = "unNamed";
	string cato = "no cat";
	int q;
	float price;
	int choic;
	bool done = false;
	cout << "************** Add Product form ********************\n";
	cout << "Enter Porduct name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter The Product Price:";
	cin >> price;
	cout << "Enter The Product Quantity:";
	cin >> q;
	do
	{
		cout << "Choose The Product Category :- \n";
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
				cout << "Invalid Choice!!....try again!!";
				done = false;break;
			}
		}
	} while (!done);

   //assinge the user enterd vals to the temp
	Product tmp(per_id, q, price, name, cato);
	tmp.product_info();
	admin.Add_to_requested_products(tmp);
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

void Seller::display_Seller_Products(vector<Product> allProducts, int sId)
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
