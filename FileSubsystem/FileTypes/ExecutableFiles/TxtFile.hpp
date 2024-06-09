#pragma once

#include "ExecutableFile.hpp"
class TxtFile : public ExecutableFile {
private:
	std::string text;
public:
	void execute() const override;
};


void TxtFile::execute() const
{
	std::cout << text;
}