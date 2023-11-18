#pragma once

#include <iostream>
#include <string>
#include "SimpleCoffee.cpp"

using namespace std;

class CoffeeWithMilk : virtual public SimpleCoffee {
    private:
        static const string name;

    protected:
        static const int milk;
        string GetName() const override;

    public:
        CoffeeWithMilk(int availableWater = 0, int availableCoffee = 0, int availableMilk = 0);
        void Brew(ostream & os) const override;
        static int GetMilk();
};

const string CoffeeWithMilk::name = "Cafea cu lapte";
const int CoffeeWithMilk::milk = 50;