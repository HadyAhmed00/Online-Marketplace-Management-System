#include <iostream>
#include <vector>
#include "Person.h"
#include "Product.h"
#include "Admin.h"
#include <string>
#include "Validation.h"

using namespace std;
/*
	* This class is a sup class form Person class 
	* The persone class have the commen attrebutes between this class and Customer class
		- Such As :
			person ID 
			Person Name 
			Person Email
*/
class Seller : public Person
{
private:
	float profit=0;
public:
	Seller(string ,string);

	int getId();
	string getName();
	string getEmail();

	void setName(string);
	void setEmail(string);

	
	void seller_menu();
	void addPriduct(Admin&);
	vector<Product> getSellerProducts(vector<Product> , int );
	void display_Seller_Products(vector<Product>, int);
	~Seller();
};

