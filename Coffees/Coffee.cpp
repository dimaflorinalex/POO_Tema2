#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "Coffee.hpp"

using namespace std;

Coffee::Coffee() :
    datetime(time(nullptr)) { }

void Coffee::Print(ostream & os) const {
    os << put_time(localtime(&this->datetime), "%d.%m.%Y %H:%M:%S") << " - " << Coffee::name;
}

ostream & operator<<(ostream & os, Coffee const & coffee) {
    coffee.Print(os);
    return os;
}