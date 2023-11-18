#pragma once

#include <iostream>
#include <list>
#include <unordered_map>
#include "../Ingredients/IngredientType.cpp"
#include "../Coffees/CoffeeType.cpp"
#include "../Coffees/SimpleCoffee.cpp"
#include "../Coffees/CoffeeWithMilk.cpp"
#include "../Coffees/CoffeeWithSugar.cpp"
#include "../Coffees/CoffeeWithMilkAndSugar.cpp"

using namespace std;

class CoffeeMachine {
    private:
        static list<shared_ptr<CoffeeBase>> coffeesHistory;
        static unordered_map<IngredientType::IngredientType, int> ingredientsQuantity;
        static unordered_map<IngredientType::IngredientType, string> ingredientsName;
        static unordered_map<IngredientType::IngredientType, int> maxIngredientsQuantity;
        
        static void Refill();
        static void ShowOpeningView();
        static void ShowMainMenuView();
        static void ShowCoffeesHistoryView();
        static void ShowIngredientsView();
        static void ShowRefillView();
        static void ShowPreparingCoffeeView(CoffeeType::CoffeeType coffeeType);
        static void ShowClosingView();

    public:
        CoffeeMachine() = delete;
        static void Init();
};

list<shared_ptr<CoffeeBase>> CoffeeMachine::coffeesHistory;
unordered_map<IngredientType::IngredientType, int> CoffeeMachine::ingredientsQuantity;

unordered_map<IngredientType::IngredientType, int> CoffeeMachine::maxIngredientsQuantity = {
    { IngredientType::IngredientType::Water, 3000 },
    { IngredientType::IngredientType::Coffee, 300 },
    { IngredientType::IngredientType::Sugar, 200 },
    { IngredientType::IngredientType::Milk, 500 }
};

unordered_map<IngredientType::IngredientType, string> CoffeeMachine::ingredientsName = {
    { IngredientType::IngredientType::Water, "Apa (ml)" },
    { IngredientType::IngredientType::Coffee, "Cafea (g)" },
    { IngredientType::IngredientType::Sugar, "Zahar (g)" },
    { IngredientType::IngredientType::Milk, "Lapte (ml)" }
};