#pragma once

#include <iostream>
#include <string>
#include "SimpleCoffee.cpp"

using namespace std;

class CoffeeWithMilk : virtual public SimpleCoffee {
    private:
        static const string name;

    protected:
        string GetName() const override;

    public:
        void Brew(ostream & os) const override;
};

const string CoffeeWithMilk::name = "Cafea cu lapte";