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
	bool number_case = false; //...
	bool special_char = false;
	string pass;



	regex upper_case_expression{ "[A-Z]+" }; //here is the very simple expression for upper_case search
	regex lower_case_expression{ "[a-z]+" }; //for lower-case
	regex number_expression{ "[0-9]+" }; //...
	regex special_char_expression{ "[@!?]+" };







	bool done = false; //let's assume we're not done



	do { //do ask-for-password as long were not done

		cout << "Note:1-Your password must be at least 9 characters\n" <<
			"    2-Must contain at least one special character('#','&','@',..etc)\n" <<
			"    3-Must contain at least one uppercase character \n" <<
			"    4-Must contain at least one number    \n";

		cout << "Type in a valid password: ";
		getline(cin, pass); //get input



		if (pass.length() <= 8) { //too short!
			cout << "Invalid password! Try again . . .\n\n";
		}
		else {



			upper_case = regex_search(pass, upper_case_expression); //save the result, if the expression was found.
			lower_case = regex_search(pass, lower_case_expression); //....
			number_case = regex_search(pass, number_expression);
			special_char = regex_search(pass, special_char_expression);



			//like: sum_of_positive_results = 1 + 0 + 1 + 1 (true/false as an integer)
			int sum_of_positive_results = upper_case + lower_case + number_case + special_char;



			if (sum_of_positive_results < 3) { //not enough booleans were true!
				cout << "Invalid password! Try again . . .\n\n";
			}
			else { //otherwise it's valid!
				cout << "That's a valid Password!" << endl;
				done = true;
				return pass;
			}
		}



	} while (!done);
}
string Validation::emailValidation() {
	string email;




	cout << "Enter your Email-Id:" << endl;
	do
	{
		getline(cin, email);
		if (Email_check(email))
		{
			cout << "Your Email-Id is valid" << endl;
			return email;
		}
		else
		{
			cout << "Your Email-Id is invalid" << endl;
			
		}



	} while (!Email_check(email));




}
Validation::~Validation()
{
}
