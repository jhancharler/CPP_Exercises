// Lab #4 - Intro to Arrays

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, std::vector<std::string>& vect) {
    for (auto s : vect) {
        os << "[" + s + "]";
    }
    return os;
}

// A class that deals with the tasks for the Arrays lesson...
// Task: Enter list of names then search for names inside the list
class IntroToArrays {

public:
    IntroToArrays() : names(std::vector<std::string>{}) {};

    std::vector<std::string> names;

    void enterNames(int n) {
        for (int i = 1; i <= n; i++) {

            std::string thisName = "";
            std::cout << "Enter name #" << i << ": ";
            std::cin >> thisName;
            capitalize(thisName);
            names.push_back(thisName);
        }
    }

    void startSearching() {
        bool running = true;
        while (running) {
            std::string query = "";
            std::cout << "Who do you want to search for (enter done to exit)?\n";
            std::cin >> query;
            if (query[0] == 'd' || query[0] == 'D') running = false;
            else { search(query); }
        }
        std::cout << "Thank you for using my program.\n";
    }

    void search(std::string who) {
        int count = 0;
        capitalize(who);
        for (int i = 0; i < names.size(); i++) {
            if (who == names[i]) count++;
        }
        std::cout << "There are " << count << " instances of the name " << who << "\n";
    }

    void printNames() {
        std::cout << "List of names = " << names << "\n";
    }

    void capitalize(std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c); 
        });
    }
};

int main()
{
    IntroToArrays ita;

    ita.enterNames(10);

    ita.printNames();

    ita.startSearching();
}

