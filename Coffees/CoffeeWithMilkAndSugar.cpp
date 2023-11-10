#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithMilkAndSugar.hpp"

using namespace std;

string CoffeeWithMilkAndSugar::GetName() const {
    return CoffeeWithMilkAndSugar::name;
}

void CoffeeWithMilkAndSugar::Brew(ostream & os) const {
    this->CoffeeWithMilk::Brew(os);
    os << "Se adauga zahar..." << endl;
}

ostream & operator<<(ostream & os, CoffeeWithMilkAndSugar const & coffee) {
    coffee.PrintInfo(os);
    return os;
}