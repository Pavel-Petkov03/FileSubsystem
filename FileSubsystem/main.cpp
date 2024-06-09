#include <iostream>
#include <chrono>
#include "Utility/PolymorphicPtr.hpp"
#include "Auth/User.hpp"
int main(){
	User user;
	std::string name("adsa");

	BaseRole* c = new Admin();
	Polymorphic_Ptr<BaseRole> q(c);
	std::cout << q;
}