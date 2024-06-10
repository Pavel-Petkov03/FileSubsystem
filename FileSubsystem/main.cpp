#include <iostream>
#include <chrono>
#include "FileTypes/Directory.hpp"
int main(){
	const User user;
	std::string name("root");
	Vector<Polymorphic_Ptr<BaseFile>> children;
	Vector<std::string> groups;
	groups.pushBack("Teachers");
	Directory dir(name, user, nullptr, children, groups);
	std::cout << dir;
}