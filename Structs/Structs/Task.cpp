#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <algorithm>

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
		throw std::runtime_error(_inFileName + " could not be opened!");
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

void Task::printHeading() {

	std::ostringstream outStream;
	int index;
	float totalBalance;
	float balanceSearched;
	std::ofstream outFile(_outFileName);

	auto streamUserDetails = [](std::ostringstream& oss, const User& u) {
		oss << std::left << std::setw(10) << u.id << std::left << std::setw(20) << u.name << std::setw(5) << std::right << "$" << std::setw(10) << std::right << std::fixed << u.balance << std::endl;
	};

	outStream << std::setprecision(2);
	outStream << std::fixed;

	outStream << "Higher Balance:\n";
	outStream << std::left << std::setw(10) << "ID #" << std::left <<  std::setw(20) << "NAME" << std::setw(15) << std::right << "BALANCE DUE" << std::endl;
	outStream << std::left << std::setw(10) << "----" << std::left << std::setw(20) << "--------------------" << std::setw(15) << std::right << "-----------" << std::endl;

	index = searchLargestBalance();
	User mostBalanceUser = _users[index];

	// Largest balance:
	streamUserDetails(outStream, mostBalanceUser);
	outStream << std::endl;

	totalBalance = sum();
	outStream << "Total Balance for all persons:\n";
	outStream << std::left << std::setw(4) << "$" << std::left << totalBalance << std::endl;

	outStream << std::endl;
	outStream << "Search Names:\n";
	outStream << std::left << std::setw(10) << "ID #" << std::left << std::setw(20) << "NAME" << std::setw(15) << std::right << "BALANCE DUE" << std::endl;

	balanceSearched = 0;
	for (auto u : _searchedNames) {
		streamUserDetails(outStream, u);
		balanceSearched += u.balance;
	}

	outStream << std::endl;
	outStream << std::setw(35) << std::right << "Total Balance Due: $" << std::right << std::setw(10) << balanceSearched << std::endl;
	std::cout << "\n";

	// Print to console
	std::cout << outStream.str() << std::endl;

	// Print to file
	outFile << outStream.str();
	outFile.close();
}

std::ostringstream Task::printCols(std::string col1, std::string col2, std::string col3) {
	
	std::ostringstream outStream;

	outStream << std::setw(10) << std::left << col1;
	outStream << col2;
	outStream << std::setw(16) << std::right << col3 << "\n";

	return outStream;
	
}

int Task::searchLargestBalance() {

	int index = -1;
	float highest = -std::numeric_limits<float>::max();
	for (size_t i = 0; i < _users.size(); i++) {
		if (highest < _users[i].balance) {
			highest = _users[i].balance;
			index = i;
		}
	}
	return index;
}

float Task::sum() {

	float sum = 0.f;
	for (size_t i = 0; i < _users.size(); i++) {
		sum += _users[i].balance;
	}
	return sum;
}

void Task::searchName(std::string name) {
	
	bool found = false;

	for (User u : _users) {
		if (ModifyString::capitalize(u.name) == ModifyString::capitalize(name)) {
			found = true;
			_searchedNames.push_back(u);
			break;
		}
	}

	if (found) {
		std::cout << "Found.\n";
	}
	else {
		std::cout << ModifyString::title(name) << " was not found.\n";
	}

	printHeading();
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

	auto s = sum();
	auto h = searchLargestBalance();

	std::cout << "Thank you for using my program\n";
}