#include "Person.h"

Person::Person()
{

}

Person::Person(string Name, string Email, string password, string Address, string phone)
{
    per_name = Name;
    per_email = Email;
    per_password = password;
    address = Address;
    phone_number = phone;
}

void Person::set_id(int id)
{
    per_id = id;
}

void Person::set_name(string name)
{
    per_name = name;
}

void Person::set_email(string email)
{
    per_email = email;
}

void Person::set_password(string pass)
{
    per_password = pass;
}

void Person::set_address(string add)
{
    address = add;
}

void Person::set_phoneNum(string num)
{
    phone_number = num;
}


string Person::get_name()
{
    return per_name;
}

int Person::get_id()
{
    return per_id;
}

string Person::get_email()
{
    return per_email;
}

string Person::get_password()
{
    return per_password;
}

string Person::get_address()
{
    return address;
}

string Person::get_phoneNum()
{
    return phone_number;
}
