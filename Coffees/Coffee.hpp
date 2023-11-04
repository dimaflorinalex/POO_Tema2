#pragma once

#include <iostream>
#include <string>

using namespace std;

class Coffee {
    private:
        static const string name;

    protected:
        const time_t datetime;

        virtual void Print(ostream & os) const;

    public:
        Coffee();
        friend ostream & operator<<(ostream & os, Coffee const & coffee);
};

const string Coffee::name = "Cafea simpla";