// written by Sofia Gratny
// september 27, 2022


#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

class Console {

    public:
        
        static void displayOptions();
        static int getIntInput(const std::string&);
        static char getCharInput(const std::string&);
        static std::string getStringInput(const std::string&);
        static void displayInvalidInput();
};

#endif // CONSOLE_H