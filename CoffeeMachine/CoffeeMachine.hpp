#pragma once

#include <iostream>
#include <list>
#include "../Coffees/CoffeeType.cpp"
#include "../Coffees/Coffee.cpp"
#include "../Coffees/CoffeeWithMilk.cpp"

using namespace std;

class CoffeeMachine {
    private:
        static list<Coffee*> coffeesHistory;
        
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

list<Coffee*> CoffeeMachine::coffeesHistory;