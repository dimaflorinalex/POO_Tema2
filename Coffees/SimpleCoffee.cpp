#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "../Exceptions/InsufficientIngredientException.cpp"
#include "SimpleCoffee.hpp"

using namespace std;

SimpleCoffee::SimpleCoffee(int availableWater, int availableCoffee) :
    CoffeeBase() {
    if (availableWater < SimpleCoffee::water) {
        throw InsufficientIngredientException("Apa insuficienta");
    }

    if (availableCoffee < SimpleCoffee::coffee) {
        throw InsufficientIngredientException("Cafea insuficienta");
    }
}

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

int SimpleCoffee::GetWater() {
    return SimpleCoffee::water;
}

int SimpleCoffee::GetCoffee() {
    return SimpleCoffee::coffee;
}