#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithMilk.hpp"
#include "../Exceptions/InsufficientIngredientException.cpp"

using namespace std;

CoffeeWithMilk::CoffeeWithMilk(int availableWater, int availableCoffee, int availableMilk) :
    SimpleCoffee(availableWater, availableCoffee) {
    if (availableMilk < CoffeeWithMilk::milk) {
        throw InsufficientIngredientException("Lapte insuficient");
    }
}

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

int CoffeeWithMilk::GetMilk() {
    return CoffeeWithMilk::milk;
}