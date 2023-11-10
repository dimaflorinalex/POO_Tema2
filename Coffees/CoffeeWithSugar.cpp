#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithSugar.hpp"

using namespace std;

string CoffeeWithSugar::GetName() const {
    return CoffeeWithSugar::name;
}

void CoffeeWithSugar::Brew(ostream & os) const {
    this->SimpleCoffee::Brew(os);
    os << "Se adauga zahar..." << endl;
}

ostream & operator<<(ostream & os, CoffeeWithSugar const & coffee) {
    coffee.PrintInfo(os);
    return os;
}