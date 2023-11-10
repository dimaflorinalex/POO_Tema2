#pragma once

#include <iostream>
#include <list>
#include "../Coffees/CoffeeType.cpp"
#include "../Coffees/SimpleCoffee.cpp"
#include "../Coffees/CoffeeWithMilk.cpp"
#include "../Coffees/CoffeeWithSugar.cpp"
#include "../Coffees/CoffeeWithMilkAndSugar.cpp"

using namespace std;

class CoffeeMachine {
    private:
        static list<CoffeeBase*> coffeesHistory;
        
        static void ClearMemory();

        static void ShowOpeningView();
        static void ShowMainMenuView();
        static void ShowCoffeesHistoryView();
        static void ShowPreparingCoffeeView(CoffeeType::CoffeeType coffeeType);
        static void ShowClosingView();

    public:
        CoffeeMachine() = delete;
        static void Init();
};

list<CoffeeBase*> CoffeeMachine::coffeesHistory;