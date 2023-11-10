#pragma once

#include <iostream>
#include <string>
#include "CoffeeBase.cpp"

using namespace std;

class SimpleCoffee : virtual public CoffeeBase {
    private:
        static const string name;
    
    protected:
        string GetName() const override;

    public:
        SimpleCoffee();
        void Brew(ostream & os) const override;
};

const string SimpleCoffee::name = "Cafea simpla";