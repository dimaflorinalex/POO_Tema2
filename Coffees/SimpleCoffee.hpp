#pragma once

#include <iostream>
#include <string>
#include "CoffeeBase.cpp"

using namespace std;

class SimpleCoffee : virtual public CoffeeBase {
    private:
        static const string name;
    
    protected:
        static const int water;
        static const int coffee;
        string GetName() const override;

    public:
        SimpleCoffee(int availableWater = 0, int availableCoffee = 0);
        void Brew(ostream & os) const override;
        static int GetWater();
        static int GetCoffee();
};

const string SimpleCoffee::name = "Cafea simpla";
const int SimpleCoffee::water = 300;
const int SimpleCoffee::coffee = 20;