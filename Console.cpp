// written by Sofia Gratny
// september 27, 2022


#include "Console.h"
#include "sstream"


void Console::displayOptions() {

    std::string output;
    std::stringstream ss;
    ss << "\nTODO LIST APPLICATION\n";
    ss << "---------------------" << '\n';
    ss << "[A] Add new task" << '\n';
    ss << "[C] Complete task" << '\n';
    ss << "[W] Withdraw task" << '\n';
    ss << "[R] Reset tasks" << '\n';
    ss << "[D] Display tasks" << '\n';
    ss << "[Q] Quit" << '\n';
    output = ss.str();

    std::cout << output << std::endl;
}

int Console::getIntInput(const std::string& display) {

    int input;
    std::cout << display;
    std::cin >> input;
    return input;
}

char Console::getCharInput(const std::string& display) {

    char input;
    std::cout << display;
    std::cin >> input;
    return input;
}

std::string Console::getStringInput(const std::string &display) {

    std::string input;
    std::cout << display;
    std::cin.ignore();
    std::getline(std::cin, input);
    return input;
}

void Console::displayInvalidInput() {

    std::cout << "Invalid input, please try again!" << '\n';
}