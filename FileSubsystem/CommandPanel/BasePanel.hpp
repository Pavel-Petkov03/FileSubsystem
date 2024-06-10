#pragma once
class BasePanel {
public:
	virtual void printPrompth() const = 0;
	virtual void run() const = 0;
};