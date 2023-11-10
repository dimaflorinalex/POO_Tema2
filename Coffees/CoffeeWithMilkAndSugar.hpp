#pragma once

#include <iostream>
#include <string>
#include "CoffeeWithMilk.cpp"
#include "CoffeeWithSugar.cpp"

using namespace std;

class CoffeeWithMilkAndSugar : virtual public CoffeeWithMilk, virtual public CoffeeWithSugar {
    private:
        static const string name;

    protected:
        string GetName() const override;

    public:
        void Brew(ostream & os) const override;
};

const string CoffeeWithMilkAndSugar::name = "Cafea cu lapte si zahar";