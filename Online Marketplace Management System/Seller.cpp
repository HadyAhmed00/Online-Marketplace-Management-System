#include "Seller.h"
#include "Admin.h"

static int ID = 1000;

Seller::Seller( string name, string email)
{
	per_id = ID;
	per_name = name;
	per_email = email;
	ID++;
}


//---------- Getters	--------------------

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
	cout << "************** Seller Menu ****************" << endl;
	cout << "Profit is " << profit << endl;
	cout << "Press-->1 To Add Product" << endl;
	cout << "Press-->2 To browse Products" << endl;
}

// add the new product to the list of all products and to the list of the seller products
void Seller::addPriduct(Admin &admin,Product new_Product)
{
	//call Add_to_requested_products function() in Admin class() 
	admin.Add_to_requested_products(new_Product);
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

