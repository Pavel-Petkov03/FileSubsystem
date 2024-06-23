#include "fileFactory.h"
#include "Directory.h"
#include "ExecutableFiles/headers/ExeFile.h"
#include "ExecutableFiles/headers/TxtFile.h"
#include "ExecutableFiles/headers/LinkFile.h"
BaseFile* fileFactory(int number) {
	if (number == 0) {
		return new Directory();
	}
	else if (number == 1) {
		return new ExeFile();
	}
	else if (number == 2) {
		return new TxtFile();
	}
	else if (number == 3) {
		return new LinkFile();
	}
}