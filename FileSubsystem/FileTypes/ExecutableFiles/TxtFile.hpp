#pragma once
#include "../../Utility/Vector.hpp"
#include "ExecutableFile.hpp"
#include "../../Utility/MyString.h"
class TxtFile : public ExecutableFile {
private:
	Vector<MyString> fileText;
public:
	void execute() const override;
};


void TxtFile::execute() const
{
	for (int i = 0; i < fileText.getSize(); i++) {
		std::cout << fileText[i] << std::endl;
	}
}