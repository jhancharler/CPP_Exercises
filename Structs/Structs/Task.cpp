#include <iostream>
#include <string>
#include <fstream>

#include "Task.h"
#include "ModifyString.h"

Task::Task() {

	_running = true;

	std::cout << "What input file would you like to use? ";
	std::cin >> _inFileName;

	std::cout << "What output file would you like to use? ";
	std::cin >> _outFileName;
	
	std::cin.ignore();

	populateUsers();
}

void Task::populateUsers() {

	std::ifstream inFile(_inFileName.c_str());
	if (!inFile) {
		std::cout << _inFileName << " could not be opened! \n";
		return;
	}

	while (inFile.peek() != std::ifstream::traits_type::eof()) {
		
		User user;

		std::getline(inFile, user.name);
		inFile >> user.id;
		inFile >> user.balance;

		inFile.ignore();

		_users.push_back(user);
	}
}

void Task::printHeading(const User& u) {

}

void searchBalance();
void sum();

void Task::searchName(std::string name) {
	
	bool found = false;

	for (User u : _users) {
		if (ModifyString::capitalize(u.name) == ModifyString::capitalize(name)) {
			found = true;
			break;
		}
	}

	if (found) {
		std::cout << "Found.\n";
	}
	else {
		std::cout << ModifyString::title(name) << " was not found.\n";
	}
}

void Task::execute() {

	std::string name = "";
	while (_running){
		std::cout << "Who do you want to search for (enter done to exit): ";
		std::getline(std::cin, name);
		if (name == "done") 
			_running = false;
		else {
			searchName(name);
		}
	}

	sum();

	std::cout << "Thank you for using my program\n";
}