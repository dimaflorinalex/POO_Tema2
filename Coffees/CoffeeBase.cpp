#pragma once

#include <iostream>
#include <string>
#include "CoffeeBase.hpp"

using namespace std;

CoffeeBase::CoffeeBase(const time_t dateTime) :
    dateTime(dateTime) { }

void CoffeeBase::PrintInfo(ostream & os) const {
    os << put_time(localtime(&this->dateTime), "%d.%m.%Y %H:%M:%S") << " - " << this->GetName() << endl;
}