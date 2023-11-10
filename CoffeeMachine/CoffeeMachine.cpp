#pragma once

#include <iostream>
#include <list>
#include "CoffeeMachine.hpp"

void CoffeeMachine::Init() {
    ClearMemory();
    ShowOpeningView();
}

void CoffeeMachine::ClearMemory() {
    for (list<CoffeeBase *>::iterator it = coffeesHistory.begin(); it != coffeesHistory.end(); it++) {
        delete *it;
    }

    coffeesHistory.clear();
}

void CoffeeMachine::ShowOpeningView() {
    cout << "Aparatul de cafea se aprinde..." << endl;
    ShowMainMenuView();
}

void CoffeeMachine::ShowMainMenuView() {
    cout << endl;
    cout << "Meniul principal" << endl;
    cout << "- - - - - - - - -" << endl;
    cout << "0. Stinge aparatul de cafea" << endl;
    cout << "1. Istoric cafele" << endl;
    cout << "2. Prepara o cafea simpla" << endl;
    cout << "3. Prepara o cafea cu lapte" << endl;
    cout << "4. Prepara o cafea cu zahar" << endl;
    cout << "5. Prepara o cafea cu lapte si zahar" << endl;

    int choice;

    do {
        cout << "Alegeti o optiune valida: " << endl;
        cin >> choice;

        switch(choice) {
            case 0:
                ShowClosingView();
                break;
            case 1:
                ShowCoffeesHistoryView();
                break;
            case 2:
                ShowPreparingCoffeeView(CoffeeType::SimpleCoffee);
                break;
            case 3:
                ShowPreparingCoffeeView(CoffeeType::CoffeeWithMilk);
                break;
            case 4:
                ShowPreparingCoffeeView(CoffeeType::CoffeeWithSugar);
                break;
            case 5:
                ShowPreparingCoffeeView(CoffeeType::CoffeeWithMilkAndSugar);
                break;
            default:
                choice = -1;
                break; 
        }
    } while (choice == -1);
}

void CoffeeMachine::ShowCoffeesHistoryView() {
    cout << endl;
    cout << "- - - - - " << coffeesHistory.size() << " cafele preparate - - - - -" << endl;

    if (coffeesHistory.size() > 0) {
        cout << "Nr - Data si ora - Tip cafea - Ingrediente" << endl;

        int i = 0;
        for (list<CoffeeBase *>::iterator it = coffeesHistory.begin(); it != coffeesHistory.end(); it++) {
            i++;
            cout << i << " - ";
            (*it)->PrintInfo(cout);
        }
        cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
    }

    cout << "Apasati o tasta pentru a reveni la meniul principal" << endl;
    cin.ignore();
    cin.get();

    ShowMainMenuView();
}

void CoffeeMachine::ShowPreparingCoffeeView(CoffeeType::CoffeeType coffeeType) {
    CoffeeBase * coffee = nullptr;

    cout << endl;
    switch (coffeeType) {
        case CoffeeType::SimpleCoffee:
            coffee = new SimpleCoffee();
            break;
        case CoffeeType::CoffeeWithMilk:
            coffee = new CoffeeWithMilk();
            break;
        case CoffeeType::CoffeeWithSugar:
            coffee = new CoffeeWithSugar();
            break;
        case CoffeeType::CoffeeWithMilkAndSugar:
            coffee = new CoffeeWithMilkAndSugar();
            break;
        case CoffeeType::CustomCoffee:
            break;
        default:
            cout << "Tipul de cafea ales nu exista!" << endl;
            return ShowMainMenuView();
    }

    cout << "Se prepara cafeaua..." << endl;
    coffee->Brew(cout);
    coffeesHistory.push_back(coffee);
    cout << "Cafeaua poate fi servita." << endl;

    ShowMainMenuView();
}

void CoffeeMachine::ShowClosingView() {
    cout << endl;
    cout << "Aparatul de cafea se stinge..." << endl;
    ClearMemory();
}