
#include "../headers/ExecutableFile.h"
ExecutableFile::ExecutableFile(const MyString& name, BaseFile* parent) : BaseFile(name, parent) {

}

void ExecutableFile::serialise(std::ostream& ofs) const
{
	ofs << (int)getType() << std::endl;
	operator<<(ofs, static_cast<const BaseFile&>(*this));
	ofs << fileLines.getSize() << std::endl;
	for (int i = 0; i < fileLines.getSize(); i++) {
		ofs << fileLines[i] << std::endl;
	}
}

void ExecutableFile::deserialise(std::istream& ifs)
{
	operator>>(ifs, static_cast<BaseFile&>(*this));
	int size;
	ifs >> size;
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < size; i++) {
		MyString element;
		element.getline(ifs);
		fileLines.pushBack(element);
	}
}
