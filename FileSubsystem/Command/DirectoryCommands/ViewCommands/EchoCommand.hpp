#pragma once
#include "ViewCommand.hpp"
#include "../../../FileTypes/ExecutableFiles/ExecutableFile.hpp"
class EchoCommand : public ViewCommand {
private:
	static void changeFile(ExecutableFile* file, const MyString& text);
	static void modifyFile(ExecutableFile* file, const MyString& text);
public:
	void runTask(Directory*& file, User*& user, std::stringstream& context) override;
};



void EchoCommand::changeFile(ExecutableFile* file, const MyString& text)
{
	Vector<MyString> currentVc;
	currentVc.pushBack(text);
	file->fileLines = currentVc;
	file->setModificationDate();
}

void EchoCommand::modifyFile(ExecutableFile* file, const MyString& text)
{

	file->fileLines.pushBack(text);
	file->setModificationDate();
}

void EchoCommand::runTask(Directory*& file, User*& user, std::stringstream& context) {
	MyString text;
	MyString cmd;
	MyString filename;
	context >> text >> cmd >> filename;
	if(!cmd && !filename){
		std::cout << text << std::endl;
		return;
	}
	context.str("");
	context.clear();
	context << " " << filename << " " << cmd << " " << text;
	CdCommand cd;
	cd.runTaskOnLoggedFile(file, user, context, [](ExecutableFile*& currentFile, User* user, std::stringstream& context) {
		MyString text;
		MyString cmd;
		MyString filename;
		context >> filename >> cmd >> text;
		if (cmd == ">") {
			changeFile(currentFile, text);
		}
		else if (cmd == ">>") {
			modifyFile(currentFile, text);
		}
		}, nullptr);
}