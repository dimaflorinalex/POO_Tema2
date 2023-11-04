#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "CoffeeWithMilk.hpp"

using namespace std;

void CoffeeWithMilk::Print(ostream & os) const {
    os << put_time(localtime(&this->datetime), "%d.%m.%Y %H:%M:%S") << " - " << CoffeeWithMilk::name;
}