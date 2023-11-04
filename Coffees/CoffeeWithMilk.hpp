#pragma once

#include <iostream>
#include <string>
#include "Coffee.hpp"

using namespace std;

class CoffeeWithMilk : public Coffee {
    private:
        static const string name;

    protected:
        void Print(ostream & os) const override;
};

const string CoffeeWithMilk::name = "Cafea cu lapte";