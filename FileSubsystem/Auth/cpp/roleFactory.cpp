#include "../headers/Admin.h"
#include "../headers/Editor.h"
#include "../headers/Viewer.h"

BaseRole* roleFactory(int number) {
	if (number == 0) {
		return new Admin();
	}
	else if (number == 1) {
		return new Editor();
	}
	else if (number == 2) {
		return new Viewer();
	}
}