#pragma once

#include <string>
#include <vector>

#include "User.h"

class Task
{
public:
    Task();
    void printHeading(const User& u);
    void searchBalance();
    void sum();
    void searchName(std::string name);
    void execute();

private:
	std::string _inFileName;
	std::string _outFileName;
    std::vector<User> _users;

    bool _running;

    void populateUsers();
};

