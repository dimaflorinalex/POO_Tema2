#pragma once

#include <iostream>
#include <string>

using namespace std;

class CoffeeBase {
    protected:
        const time_t dateTime;
        virtual string GetName() const = 0;

    public:
        CoffeeBase(const time_t dateTime = time(nullptr));
        virtual void PrintInfo(ostream & os) const;
        virtual void Brew(ostream & os) const = 0;
};