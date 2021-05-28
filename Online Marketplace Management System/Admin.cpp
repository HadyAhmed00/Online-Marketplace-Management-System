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
}

void Admin::Accept_or_Reject(vector <Product>& all_products) {
    int choice;
    while (!requested_products.empty()) {
        cout << requested_products.front().get_name() << endl;
        cout << "Press-->1 to accept the product\n";
        cout << "Press-->2 to reject the product\n";
        do {
            cout << "Enter your choice: "; cin >> choice;
        } while (choice != 1 && choice != 2);
        if (choice == 1)
        {
            all_products.push_back(requested_products.front());
            requested_products.pop();
        }
        else {
            requested_products.pop();
        }

    }
    cout << "There is no other requested product\n" << endl;
    //hana5od ra2y elnas kollaha law eladmin ye3mel 7aga tanya

}
