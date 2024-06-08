#pragma once


class BaseCommand {
public:
	virtual void execute() const = 0;
};