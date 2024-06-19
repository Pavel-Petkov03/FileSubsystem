#pragma once
#include "ViewCommand.h"
#include "../../../../FileTypes/Directory.h"
#include "../../../../Auth/headers/User.h"
#include "../../../../FileTypes/ExecutableFiles/headers/ExecutableFile.h"
class CdCommand : public ViewCommand {
private:

	void logToDirectory(Directory*& file, User*& user, std::stringstream& context);
	void logToDirectoryRecurse(Directory*& file, User*& user, std::stringstream& context);
	void runTaskOnLoggedDirectory(Directory*& file, User*& user, std::stringstream& context, void(*func)(Directory*& otherFile, User* user, std::stringstream& context), bool movePath = false);
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
	friend class ExecuteCommand;
	friend class LinkFile;
};