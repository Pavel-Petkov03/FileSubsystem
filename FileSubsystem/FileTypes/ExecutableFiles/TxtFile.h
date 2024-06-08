#pragma once

#include "ExecutableFile.h"
class TxtFile : public ExecutableFile {
private:
	std::string text;
public:
	void execute() const override;
};