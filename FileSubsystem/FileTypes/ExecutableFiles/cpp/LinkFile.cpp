#include "../headers/LinkFile.h"
#include "../../Directory.h"
LinkFile::LinkFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}

ExecutableFile* LinkFile::clone() const
{
	return new LinkFile(*this);
}

void LinkFile::execute(User* user)
{
	if (executed) {
		// throw circular import error;
	}
	executed = true;
	for (int i = 0; i < fileLines.getSize(); i++) {
		std::stringstream currentStream;
		currentStream << " " << fileLines[i];
		cd.runTaskOnLoggedFile((Directory*&)parent, user, currentStream, [](ExecutableFile*& otherFile, User* user, std::stringstream& context) {
			otherFile->execute(user);
			},
			nullptr);
	}
	executed = false;
}