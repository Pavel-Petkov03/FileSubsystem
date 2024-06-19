#include "../headers/TxtFile.h"

void TxtFile::execute(User* user)
{
	for (int i = 0; i < fileLines.getSize(); i++) {
		std::cout << fileLines[i] << std::endl;
	}
}
ExecutableFile* TxtFile::clone() const
{
	return new TxtFile(*this);
}

TxtFile::TxtFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}