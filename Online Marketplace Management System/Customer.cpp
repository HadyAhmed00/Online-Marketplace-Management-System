#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;
static int ID = 1000;
Customer::Customer() {

}


Customer::Customer(string name, string email, string address, string phone, string password)
{
    ID++;
    per_id = ID;
    per_name = name;
    per_email = email;
    this->address = address;
    this->phone_number = phone;
    per_password = password;
}


//add to cart function: add product to customer cart
void Customer::Add_to_cart(Product& product, int quantity)
{
    bool found = false;
    int index;
    for (int i = 0; i < cart.size(); i++)
    {
        if (product.get_id() == cart[i].pro.get_id())
        {
            found = true;
            index = i;
            break;
        }
        else
            found = false;
    }
    if (found)
    {
        cart[index].Quantity += quantity;
        product.set_quantity(product.get_quantity() - quantity);
        cout << "this product is already exist so the product quantity has been increased\n";
    }
    else
    {
        product_struct temp;
        temp.pro = product;
        temp.Quantity = quantity;
        cart.push_back(temp);
        product.set_quantity(product.get_quantity() - quantity);
        cout << "the product has been added to cart \n";
    }
}

void Customer::customer_menu()
{
    int choice;
    string cat = "no cat";
    cout << "*******************Customer Menu*******************\n";
    cout << "Press 1 to go to cart\n";
    cout << "Press 2 to show products of Category A\n";
    cout << "Press 3 to show products of Category B\n";
    cout << "Press 4 to show products of Category C\n";
    cout << "Press 5 to show products of Category D\n";
    cout << "Press 6 to show all products\n";
    cout << "Press 7 to search for a product by name\n";
    cout << "Press 8 to Log Out\n";
    /*cout << "Press 8 to go back\n";*/
    cin >> choice;
    switch (choice) {
    case 1:
        display_cart_products();
        break;
    case 2:
        cout << "Category A\n";
        cat = "catA";
        //display_category_products(products_array,cat);
        break;
    case 3:
        cout << "Category B\n";
        cat = "catB";
        //display_category_products(products_array,cat);
        break;
    case 4:
        cout << "Category C\n";
        cat = "catC";
        //display_category_products(products_array,cat);
        break;
    case 5:
        cout << "Category D\n";
        cat = "catD";
        //display_category_products(products_array,cat);
        break;
    case 6:
        //call all products
        //it takes products array list and its category
        //then calls product_info in a for loop
        break;
    case 7:
        //search_by_name();
        break;
    case 8:
        cout << "Logging out.......\n";
        break;
    default:
        cout << "Incorrect entry..Please try again!!!\n";
        customer_menu();
        break;
    }
    
}

// search for a product by entering its name
bool Customer::search_by_name(string Name, vector<Product>arr) {
    bool isFound = false;
    int index;
    for (int i = 0; i < arr.size(); i++)
    {
        if (Name == arr[i].get_name())
        {
            isFound = true;
            index = i;
            break;
        }
        else
        {
            isFound = false;
            continue;
        }

    }
    if (isFound)
    {
        arr[index].product_info();
        cout << endl;
        return true;
    }
    else
    {
        return false;
        cout << "product is not found\n";
    }

}
//remove from cart: remove product from customer cart
void Customer::remove_from_cart(Product& product)
{
    bool isFound = false;
    int index;
    for (int i = 0; i < cart.size(); i++)
    {
        if (product.get_id() == cart[i].pro.get_id())
        {
            isFound = true;
            index = i;
            break;
        }
        else
        {
            continue;
        }
    }
    if (isFound)
    {
        product.set_quantity(product.get_quantity() + cart[index].Quantity);
        cart.erase(cart.begin() + index);
        cout << "the product " << cart[index].pro.get_name() << " has been removed\n";
    }
    else
    {
        cout << "This product" << cart[index].pro.get_name() << " is not found" << endl;
    }
}
//display all elements in cart
void Customer::display_cart_products()
{
    int choice;
    if (cart.size() == 0) {
        cout << "Your cart is empty now \n";
    }
    else {
        for (int i = 0; i < cart.size(); i++)
        {
            cout << cart[i].pro.get_name() << "\t" << cart[i].Quantity << endl;
        }
    }
    cout << "Press-->1 to go back\n";
    cout << "Press-->2 to Log Out\n";
    cin >> choice;
    switch (choice) {
    case 1:
        customer_menu();
        break;
    case 2:
        cout << "Logging out.........\n";
        break;
    default:
        cout << "Invalid Entry...please try again!\n";
        display_cart_products();
    }

   
}

void Customer::display_category_products(vector <Product> products, string cat)
{
    bool isfound = false;
    int index;
    for (int i = 0; i < products.size(); i++)
    {
        if (cat == products[i].get_category())
        {
            products[i].product_info();
            cout << endl;
            continue;
        }
        else
        {
            continue;
        }
    }

}


