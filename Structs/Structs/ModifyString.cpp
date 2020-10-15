#include "ModifyString.h"

std::string ModifyString::capitalize(std::string str) {
	for (auto& c : str) {
		c = std::toupper(c);
	}
	return str;
}

std::string ModifyString::lower(std::string str) {
	for (auto& c : str) {
		c = std::tolower(c);
	}
	return str;
}


std::string ModifyString::title(std::string str) {

	bool capitalize = true;
	
	for (int i = 0; i < str.size(); i++) {
		if (capitalize) {
			str[i] = std::toupper(str[i]);
			capitalize = false;
		}
		if (str[i] == ' ') {
			capitalize = true;
		}
	}

	return str;
}
