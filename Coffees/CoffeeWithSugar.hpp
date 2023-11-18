#pragma once

#include <iostream>
#include <string>
#include "SimpleCoffee.cpp"

using namespace std;

class CoffeeWithSugar : virtual public SimpleCoffee {
    private:
        static const string name;

    protected:
        static const int sugar;
        string GetName() const override;

    public:
        CoffeeWithSugar(int availableWater = 0, int availableCoffee = 0, int availableSugar = 0);
        void Brew(ostream & os) const override;
        static int GetSugar();
};

const string CoffeeWithSugar::name = "Cafea cu zahar";
const int CoffeeWithSugar::sugar = 20;