#pragma once
#include "ViewCommand.hpp"
#include <fstream>
#include <sstream>
#include "../../../Errors/FileErrors.hpp"
#include "../../../FileTypes/ExecutableFiles/ExecutableFile.hpp"
class CdCommand : public ViewCommand {
private:

	void logToDirectory(Directory*& file, User*& user, std::stringstream& context);
	void logToDirectoryRecurse(Directory*& file, User*& user, std::stringstream& context);
	void runTaskOnLoggedDirectory(Directory*& file, User*& user, std::stringstream& context, void(*func)(Directory*& otherFile, User* user, std::stringstream& context), bool movePath=false);
	void runTaskOnLoggedFile(Directory*& file, User*& user, std::stringstream& context, void(*func)(ExecutableFile*& otherFile, User* user, std::stringstream& context), 
		void(*onCreate)(Directory*& otherFile, User* user, std::stringstream& context));
	void rebuildStream(std::stringstream& stream, const MyString& path);
	void changeFileLocation(std::stringstream& stream, const MyString& path);
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
	friend class LsCommand;
	friend class FindCommand;
	friend class RemoveFileCommand;
	friend class RemoveDirCommand;
	friend class EchoCommand;
	friend class TouchCommand;
};

void CdCommand::logToDirectory(Directory*& file, User*& user, std::stringstream& context)
{
	context.ignore(); // for " ";
	logToDirectoryRecurse(file, user, context);
}

void CdCommand::logToDirectoryRecurse(Directory*& file, User*& user, std::stringstream& context)
{
	char buffer[1024];
	context.getline(buffer, 1024, '/');
	MyString path(buffer);
	if (path == "..") {
		Directory* cpy = file;
		file = (Directory*)file->parent;
		if (!file) {
			std::cout << "Cannot do this command on root" << std::endl;
			file = cpy;
			return;
		}
		logToDirectoryRecurse(file, user, context);
	}
	else if (path) {
		for (int i = 0; i < file->children.getSize(); i++) {
			if (file->children[i]->name == path) {
				if (Directory* currentDir = dynamic_cast<Directory*>(file->children[i].get())) {
					file = currentDir;
					logToDirectoryRecurse(currentDir, user, context);
					return;
				}
				changeFileLocation(context, path);
				throw InvalidFileType("Cd command can be used only on folder");
			}
		}
		changeFileLocation(context, path);
		throw InvalidFileName("Invalid file name");
	}
}

void CdCommand::runTaskOnLoggedDirectory(Directory*& file, User*& user, std::stringstream& context, void(*func)(Directory*& otherFile, User* user, std::stringstream& context), bool movePath)
{
	try {
		if (movePath) {
			logToDirectory(file, user, context);
			func(file, user, context);
			return;
		}
		else {
			Directory* copy = file;
			logToDirectory(copy, user, context);
			func(copy, user, context);
		}
	}
	catch (InvalidFileError& err) {
		std::cout << err.what() << std::endl;
	}
}

void CdCommand::runTaskOnLoggedFile(Directory*& file, User*& user, std::stringstream& context, void(*onExecute)(ExecutableFile*& otherFile, User* user, std::stringstream& context)
	, void(*onCreate)(Directory*& otherFile, User* user, std::stringstream& context))
{
	Directory* copy = file;
	std::stringstream fileStream;
	try {
		MyString filename;
		context >> filename;
		fileStream << " " <<  filename.c_str();
		context.seekg(std::ios::beg);
		logToDirectory(copy, user, fileStream); // returs the stream to beg
	}
	catch (InvalidFileError& err) {
		MyString currentFileName;
		fileStream >> currentFileName;
		rebuildStream(context, currentFileName);
		BaseFile* currentFile = copy->getChildWithName(currentFileName);
		ExecutableFile* execFile = dynamic_cast<ExecutableFile*>(currentFile);
		if (execFile) {
			onExecute(execFile, user, context);
		}
		else if (onCreate) {
			onCreate(copy, user, context);
		}
		else {
			std::cout << "No such file with name" << currentFileName << std::endl;
		}
	}
}

void CdCommand::rebuildStream(std::stringstream& stream, const MyString& path)
{
	bool changed = false;
	MyString currentStr;
	std::stringstream dest;
	stream.seekg(std::ios::beg);
	stream >> currentStr;
	while (currentStr) {
		if (!changed) {
			dest << path << " ";
			changed = true;
		}
		else {
			dest << currentStr << " ";
		}
		stream >> currentStr;
	}
	stream.clear();
	stream.seekg(std::ios::beg);
	stream.str(dest.str());
}

void CdCommand::changeFileLocation(std::stringstream& stream, const MyString& path)
{
	stream.str("");
	stream.clear();
	stream << path.c_str();
}


void CdCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	
	runTaskOnLoggedDirectory(file, user, context, [](Directory*& otherFile, User* user, std::stringstream& context) {},true);
}