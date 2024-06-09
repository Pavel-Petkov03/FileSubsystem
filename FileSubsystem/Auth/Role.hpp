#pragma once
class BaseCommand;

enum class RoleTypes {
	Admin,
	Editor,
	Viewer,
};


class BaseRole {
public:
	virtual bool authorisedCommand(const BaseCommand* command) const = 0;
	virtual BaseRole* clone() const = 0;
	virtual ~BaseRole() = default;
	virtual RoleTypes getType() const = 0;
	friend std::ostream& operator<<(std::ostream& ofs, const BaseRole&);
};


std::ostream& operator<<(std::ostream& ofs, const BaseRole& role)
{
	ofs << "Base";
	return ofs;
}