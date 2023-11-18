#pragma once

#include <iostream>
#include <string>
#include "CoffeeWithMilk.cpp"
#include "CoffeeWithSugar.cpp"

using namespace std;

class CoffeeWithMilkAndSugar : public CoffeeWithMilk, public CoffeeWithSugar {
    private:
        static const string name;

    protected:
        string GetName() const override;

    public:
        CoffeeWithMilkAndSugar(int availableWater = 0, int availableCoffee = 0, int availableMilk = 0, int availableSugar = 0);
        void Brew(ostream & os) const override;
};

const string CoffeeWithMilkAndSugar::name = "Cafea cu lapte si zahar";