#pragma once
#include "ExecutableFile.hpp"
#include "../../Utility/Vector.hpp"
#include "../../Utility/MyString.h"
class ExeFile : public ExecutableFile {
private:
	Vector<MyString> commandLines;
public:

};