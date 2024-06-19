#include "../headers/RemoveFileCommand.h"

void RemoveFileCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString fileName;
	context >> fileName;
	BaseFile* currentFile = file->getChildWithName(fileName);
	if (currentFile) {
		if (ExecutableFile* d = dynamic_cast<ExecutableFile*>(currentFile)) {
			file->removeFile(*user, currentFile);
			return;
		}
		std::cout << "Can't remove folder with command rm(try using rmdir)" << std::endl;
		return;
	}
}