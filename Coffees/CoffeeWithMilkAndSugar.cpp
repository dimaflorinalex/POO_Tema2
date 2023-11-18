#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithMilkAndSugar.hpp"
#include "../Exceptions/InsufficientIngredientException.cpp"

using namespace std;

CoffeeWithMilkAndSugar::CoffeeWithMilkAndSugar(int availableWater, int availableCoffee, int availableMilk, int availableSugar) :
    CoffeeWithMilk { availableWater, availableCoffee, availableMilk } {
    if (availableSugar < CoffeeWithSugar:sugar) {
        throw InsufficientIngredientException("Zahar insuficient");
    }
}

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