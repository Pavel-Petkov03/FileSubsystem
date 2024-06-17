#pragma once
#include <iostream>
#include <string>

class MyString {
private:
	char* data;
	size_t length;
	size_t allocatedData;

	void free();
	void moveFrom(MyString&& other);
	void copyFrom(const MyString& other);
	void resize(size_t allocatedData);

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	const char* c_str() const;
	size_t getLength() const;
	size_t getCapacity() const;

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;
	char& operator[](size_t index);
	char operator[](size_t index) const;

	MyString& operator+=(const MyString& other);
	MyString& operator+=(char symbol);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);
	operator bool() const;

	void getLine(std::istream& is, char delim='\n');
	MyString substr(size_t begin, size_t end) const;
};

unsigned nextPowerOfTwo(unsigned n);

MyString operator+(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);