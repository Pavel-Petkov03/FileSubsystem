#include "MyString.h"
#include <sstream>
#pragma warning(disable:4996)

void MyString::free()
{
	delete[] data;
	data = nullptr;
	allocatedData = 0;
	length = 0;
}

void MyString::moveFrom(MyString&& other) {
	data = other.data;
	length = other.length;
	allocatedData = other.allocatedData;
	other.data = nullptr;
	other.length = 0;
	other.allocatedData = 0;
}

void MyString::copyFrom(const MyString& other) {
	data = new char[other.allocatedData];
	strcpy(data, other.data);
	length = other.length;
	allocatedData = other.allocatedData;
}

MyString::MyString() : MyString("") {

}

MyString::MyString(const char* str) {
	if (str == nullptr) {
		length = 0;
		allocatedData = 16 - 1;
		data = new char[allocatedData];
		strcpy(data, "");
		return;
	}
	size_t len = strlen(str);
	allocatedData = std::max(nextPowerOfTwo(len), (unsigned)16) - 1;
	data = new char[allocatedData];
	strcpy(data, str);
	length = len;
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}


MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString& MyString::operator=(MyString&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
MyString::MyString(MyString&& other) noexcept {
	moveFrom(std::move(other));
}

MyString::~MyString() {
	free();
}

const char* MyString::c_str() const {
	return data;
}

size_t MyString::getLength() const {
	return length;
}

size_t MyString::getCapacity() const
{
	return allocatedData;
}

void MyString::resize(size_t allocatedData)
{
	char* newData = new char[allocatedData];
	strcpy(newData, data);
	delete[] data;
	data = newData;
	this->allocatedData = allocatedData;
}


char& MyString::operator[](size_t index) {
	return data[index];
}

char MyString::operator[](size_t index) const {
	return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	length += other.length;
	if (length > allocatedData) {
		resize(nextPowerOfTwo(length) - 1);
	}
	strcat(data, other.data);
	return *this;
}

MyString& MyString::operator+=(char symbol)
{
	if (length == allocatedData) {
		resize(nextPowerOfTwo(length) - 1);
	}
	data[length++] = symbol;
	data[length] = '\0';
	return *this;
}

MyString::operator bool() const
{
	return length > 0;
}



void MyString::getLine(std::istream& is, char delim)
{
	char buffer[1024];
	std::cin.getline(buffer, 1024, delim);
	int currentLen = strlen(buffer);
	if (currentLen > allocatedData) {
		resize(nextPowerOfTwo(currentLen) - 1);
	}
	strcpy(data, buffer);
	length = currentLen;
}

MyString MyString::substr(size_t begin, size_t end) const // end exclusive
{
	if (begin < 0 || end > length || begin > end) {
		throw std::out_of_range("Invalid bounds");
	}
	MyString result;
	for (int i = begin; i < end; i++) {
		result += data[i];
	}
	return result;
}

Vector<MyString> MyString::splitStr()
{
	// split by " "
	std::stringstream stream(data);
	Vector<MyString> result;
	MyString currentStr;
	stream >> currentStr;
	while (currentStr) {
		result.pushBack(currentStr);
		stream >> currentStr;
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	os << str.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
	char buffer[1024];
	is >> buffer;
	size_t bufferLen = strlen(buffer);
	if (bufferLen > str.getCapacity()) {
		str.resize(nextPowerOfTwo(bufferLen) - 1);
	}
	strcpy(str.data, buffer);
	str.length = bufferLen;
	return is;
}

unsigned nextPowerOfTwo(unsigned n)
{
	unsigned step = 1;
	while (n >> step > 0) {
		n |= n >> step;
		step <<= 1;
	}
	return n + 1;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
