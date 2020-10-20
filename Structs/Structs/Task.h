#pragma once

#include <string>
#include <vector>

#include "User.h"


class Task
{
public:
    Task();

    void printHeading();
    int searchLargestBalance();
    float sum();
    void searchName(std::string name);
    void execute();

private:
	std::string _inFileName;
	std::string _outFileName;
    std::vector<User> _users;

    std::vector<User> _searchedNames;

    bool _running;

    void populateUsers();
    std::ostringstream printCols(std::string col1, std::string col2, std::string col3);
};

