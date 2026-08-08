// Login Page
#include <iostream>
#include <string>

int main(){
	std::string name1, name2, pw1, pw2;	// Username & Password
	bool namePw = false;			// Username & Password checker
	std::string yesNo;
	int batasLogin;

	while(true){
		std::cout << "\n===Login Page===" << std::endl;
		std::cout << "Have you login before? (Y/N): ";
		std::cin >> yesNo;

		std::cin.ignore();
		if(yesNo == "N" || yesNo == "n"){
			if(namePw){
				std::cout << "Account already exist.\n";
			}
			else{
				std::cout << "Username	: ";
				std::getline(std::cin, name1);
				std::cout << "Password	: ";
				std::getline(std::cin, pw1);
				std::cout << "Thankyou for your response!" << std::endl;

				namePw = true;
				std::cout << "\nSuccess creating account!\n";
			}
		}	
		else if(yesNo == "Y" || yesNo == "y"){
			if(!namePw){
				std::cout << "No login detected" << std::endl;
			}
			else{
				batasLogin = 3;
				while(batasLogin > 0){
					std::cout << "Username	: ";
					std::getline(std::cin, name2);
					std::cout << "Password	: ";
					std::getline(std::cin, pw2);
				
					if(name2 != name1 || pw2 != pw1){
						std::cout << "Login failed.\n\n";
						batasLogin--;
					}
					else{
						std::cout << "\n===Login Page Response===" << std::endl;
						std::cout << "Username	: " << name2 << std::endl;
						std::cout << "Password	: " << pw2 << std::endl;
						std::cout << "\nLogin successful.\n";
						break;
					}
				}
			}
		}
		else if(yesNo == "Q" || yesNo =="q"){
			return 0;
		}
		else{
			std::cout << "Input is not valid.\n";
		}
	}
	
	return 0;
}
