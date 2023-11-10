#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "SimpleCoffee.hpp"

using namespace std;

SimpleCoffee::SimpleCoffee() :
    CoffeeBase() { }

string SimpleCoffee::GetName() const {
    return SimpleCoffee::name;
}

void SimpleCoffee::Brew(ostream & os) const {
    os << "Se incalzeste apa..." << endl;
    os << "Se pregatesc boabele de cafea..." << endl;
}

ostream & operator<<(ostream & os, SimpleCoffee const & coffee) {
    coffee.PrintInfo(os);
    return os;
}