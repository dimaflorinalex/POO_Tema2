#pragma once

#include <iostream>

using namespace std;

class FullCoffeeMachineException : public exception {
    private:
        string message;

    public:
        FullCoffeeMachineException(string msg) : message(msg) {}

        const char * what() {
            return message.c_str();
        }
};