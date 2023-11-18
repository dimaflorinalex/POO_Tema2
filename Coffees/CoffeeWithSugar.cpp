#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithSugar.hpp"
#include "../Exceptions/InsufficientIngredientException.cpp"

using namespace std;

CoffeeWithSugar::CoffeeWithSugar(int availableWater, int availableCoffee, int availableSugar) :
    SimpleCoffee { availableWater, availableCoffee } {
    if (availableSugar < CoffeeWithSugar::sugar) {
        throw InsufficientIngredientException("Zahar insuficient");
    }
}

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

int CoffeeWithSugar::GetSugar() {
    return CoffeeWithSugar::sugar;
}