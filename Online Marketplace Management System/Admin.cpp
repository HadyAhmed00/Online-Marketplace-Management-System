#include "Admin.h"


using namespace std;
Admin::Admin(string name, string email) {
    per_password = "Admin1";
    per_id = 100000;
    per_name = name;
    per_email = email;
}

void Admin::Add_to_requested_products(Product newproduct) {
    requested_products.push(newproduct);
    SetConsoleTextAttribute(hConsole, 11);
	cout << "Waiting for admin approval......\n\n";
    SetConsoleTextAttribute(hConsole, 15);
	cout << "******\n";
}

void Admin::Accept_or_Reject(vector <Product>& all_products) {
	system("cls");
    string choice;
    while (!requested_products.empty()) {
		cout << "\t\t\t\t\t************ Admin page ************\t\n\n";
        requested_products.front().product_info();
		cout << "------------------------------------------------------------------------------------------------------------\n";
        cout << "Press-->1 to accept the product\n\n";
        cout << "Press-->2 to reject the product\n";
        do {
            cout << "Enter your choice: "; getline(cin, choice);
        } while (choice != "1" && choice != "2");
        if (choice == "1")
        {
            all_products.push_back(requested_products.front());
            requested_products.pop();
        }
        else {
            requested_products.pop();
        }

    }
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\n\n\nThere is no other requested product\n" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}