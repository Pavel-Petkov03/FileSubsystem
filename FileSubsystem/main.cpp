#include <iostream>
#include <chrono>
#include "FileTypes/Directory.hpp"
int main(){
	const User user;
	std::string name("First_directory");
	Vector<Polymorphic_Ptr<BaseFile>> children;
	Vector<std::string> groups;
	groups.pushBack("Teachers");
	Directory dir(name, user, nullptr, children, groups);
	Directory dir2(name, user, &dir);

	std::cout << dir2.getPath();
}