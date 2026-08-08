// Login Page
#include <iostream>
#include <string>

int main(){
	std::string name, pw;

	std::cout << "===Login Page===" << std::endl;
	std::cout << "Username	: ";
	std::getline(std::cin, name);
	std::cout << "Password	: ";
	std::getline(std::cin, pw);
	std::cout << "Thankyou for your response!" << std::endl;

	std::cout << "\n===Login Page Response===" << std::endl;
	std::cout << "Username	: " << name << std::endl;
	std::cout << "Password	: " << pw << std::endl;

	return 0;
}

