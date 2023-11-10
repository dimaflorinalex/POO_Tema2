#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithMilk.hpp"

using namespace std;

string CoffeeWithMilk::GetName() const {
    return CoffeeWithMilk::name;
}

void CoffeeWithMilk::Brew(ostream & os) const {
    this->SimpleCoffee::Brew(os);
    os << "Se adauga lapte..." << endl;
}

ostream & operator<<(ostream & os, CoffeeWithMilk const & coffee) {
    coffee.PrintInfo(os);
    return os;
}