// Login Page
#include <iostream>
#include <string>

int main(){
	std::string name1, name2, pw1, pw2;	// Username & Password
	bool namePw = false;			// Username & Password checker
	std::string yesNo;

	while(true){
		std::cout << "\n===Login Page===" << std::endl;
		std::cout << "Have you login before? (Y/N): ";
		std::cin >> yesNo;

		std::cin.ignore();
		if(yesNo == "N"){
			std::cout << "Username	: ";
			std::getline(std::cin, name1);
			std::cout << "Password	: ";
			std::getline(std::cin, pw1);
			std::cout << "Thankyou for your response!" << std::endl;

			namePw = true;
		}	
		else if(yesNo == "Y"){
			std::cout << "Username	: ";
			std::getline(std::cin, name2);
			std::cout << "Password	: ";
			std::getline(std::cin, pw2);
			std::cout << "Thankyou for your response!" << std::endl;

			if(name2 == name1 && pw2 == pw1)
			std::cout << "\n===Login Page Response===" << std::endl;
			std::cout << "Username	: " << name2 << std::endl;
			std::cout << "Password	: " << pw2 << std::endl;			
		}
	}
	
	return 0;
}

