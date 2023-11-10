#pragma once

#include <iostream>
#include <string>
#include "SimpleCoffee.cpp"

using namespace std;

class CoffeeWithSugar : virtual public SimpleCoffee {
    private:
        static const string name;

    protected:
        string GetName() const override;

    public:
        void Brew(ostream & os) const override;
};

const string CoffeeWithSugar::name = "Cafea cu zahar";