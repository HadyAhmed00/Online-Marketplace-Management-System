#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
    int per_id;
    string per_name;
    string per_email;
    string per_password;
    string address;
    string phone_number;
public:
    Person();
    Person(string, string, string, string, string);
    void set_id(int);
    void set_name(string);
    void set_email(string);
    void set_password(string);
    void set_address(string);
    void set_phoneNum(string);
    string get_name();
    int get_id();
    string get_email();
    string get_password();
    string get_address();
    string get_phoneNum();
};
