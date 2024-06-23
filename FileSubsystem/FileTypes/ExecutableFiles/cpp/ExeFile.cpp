#include "../headers/ExeFile.h"
#include "../../../CommandPanel/headers/DirectoryPanel.h"
void ExeFile::execute(User* user) {
	if (executed) {
		throw CircularFileError("Circle file reference");
	}
	executed = true;
	DirectoryPanel panel((Directory*)this->parent, user);
	for (int i = 0; i < fileLines.getSize(); i++) {
		try {
			panel.runCommand(fileLines[i]);
		}
		catch (CircularFileError& err) {
			executed = false;
			throw err;
		}
	}
	executed = false;
}

ExecutableFile* ExeFile::clone() const
{
	return new ExeFile(*this);
}

FileTypes ExeFile::getType() const
{
	return FileTypes::ExeType;
}

ExeFile::ExeFile(const MyString& name, BaseFile* parent) : ExecutableFile(name, parent) {

}