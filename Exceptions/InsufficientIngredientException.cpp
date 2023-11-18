#pragma once

#include <iostream>

using namespace std;

class InsufficientIngredientException : public exception {
    private:
        string message;

    public:
        InsufficientIngredientException(string msg) : message(msg) {}

        const char * what() {
            return message.c_str();
        }
};