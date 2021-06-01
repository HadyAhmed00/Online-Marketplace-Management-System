#include "Validation.h"
Validation::Validation()
{
}
bool Validation::Email_check(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}
string Validation::passwordValidation() {
	bool upper_case = false; //saves the result if upper-case characters were found.
	bool lower_case = false; //same for lower-case
	bool number_case = false; //same for number-case
	bool special_char = false; // same for special-char
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string pass;

	regex upper_case_expression{ "[A-Z]+" }; //here is the very simple expression for upper_case search
	regex lower_case_expression{ "[a-z]+" }; //here is the very simple expression for lower_case search
	regex number_expression{ "[0-9]+" }; //here is the very simple expression for number search
	regex special_char_expression{ "[@!?]+" };//here is the very simple expression for special_char search

	bool done = false; //let's assume we're not done
	SetConsoleTextAttribute(hConsole, 5);
	cout << "Note:1-Your password must be at least 9 characters\n" <<
		"    2-Must contain at least one special character('#','&','@',..etc)\n" <<
		"    3-Must contain at least one uppercase character \n" <<
		"    4-Must contain at least one number    \n";
	SetConsoleTextAttribute(hConsole, 15);
	do
	{ //do ask-for-password as long were not done
		
		
		
		cout << "Type in a valid password: ";

		getline(cin, pass); //get input
		if (pass.length() <= 8) { //too short!
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid password too short!! Try again . . .\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
		{
			upper_case = regex_search(pass, upper_case_expression); //save the result, if the expression was found.
			lower_case = regex_search(pass, lower_case_expression); //....
			number_case = regex_search(pass, number_expression);
			special_char = regex_search(pass, special_char_expression);

			//like: sum_of_positive_results = 1 + 0 + 1 + 1 (true/false as an integer)
			int sum_of_positive_results = upper_case + lower_case + number_case + special_char;
			if (sum_of_positive_results < 3) { //not enough booleans were true!
				SetConsoleTextAttribute(hConsole, 4);
				cout << "Invalid password! Because:\n";
				if (!upper_case)
				{
					cout << "\t***Your password dont have a uper case\n";
				}
				if (!lower_case)
				{
					cout << "\t***Your password dont have a lower case\n";
				}
				if (!number_case)
				{
					cout << "\t***Your password dont have a number case\n";
				}
				if (!special_char)
				{
					cout << "\t***Your password dont have a special char\n";
				}
				SetConsoleTextAttribute(hConsole, 15);
			}
			else { //otherwise it's valid!
				SetConsoleTextAttribute(hConsole, 10);
				cout << "That's a valid Password!" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				done = true;
				return pass;
			}
		}
	} while (!done);
}
int Validation::isNumber()
{
	string input;
	bool done=false;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	regex number_expression{ "[0-9]+" }; //here is the very simple expression for number search
	do
	{
		/*cin.ignore();*/
		getline(cin, input);
		if (regex_match(input, number_expression)) {
			done = true;
			return stoi(input);
			break;
		}
		else
		{
			done = false;
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid entry...Try again\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	} while (!done); 
	
	
}
float Validation::isFloat()
{
	string input;
	bool done = false;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	regex number_expression{ "([0-9]*[.])?[0-9]+" }; //here is the very simple expression for number search
	do
	{
		/*cin.ignore();*/
		getline(cin, input);
		if (regex_match(input, number_expression)) {
				done = true;
				return stof(input);
				break;
		}
		else
		{
			done = false;
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid entry...Try again\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
	} while (!done);
}
string Validation::emailValidation()
{
	string email;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		cout << "Enter your Email-Id:" << endl;
		getline(cin, email);
		if (Email_check(email))
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Your Email-Id is valid" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			return email;
			break;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Your Email-Id is invalid" << endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
}

string Validation::phoneValidation()
{
	string input;
	bool done = false;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	regex number_expression{ "[0-9]+" }; //here is the very simple expression for number search
	do
	{
		cout << "Enter your Phone Number :  ";
		/*cin.ignore();*/
		getline(cin, input);
		if (input.length() <= 10)
		{
			done = false;
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid entry... Too short Try again\n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
		{
			if (regex_match(input, number_expression)) 
			{
				done = true;
				return input;
				break;
			}
			else
			{
				done = false;
				SetConsoleTextAttribute(hConsole, 4);
				cout << "Invalid entry...Try again\n\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		
	} while (!done);

}
Validation::~Validation()
{
}