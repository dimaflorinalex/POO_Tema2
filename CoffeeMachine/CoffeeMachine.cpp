#pragma once

#include <iostream>
#include <list>
#include <memory>
#include "CoffeeMachine.hpp"
#include "../Exceptions/FullCoffeeMachineException.cpp"

void CoffeeMachine::Init() {
    ShowOpeningView();
}

void CoffeeMachine::Refill() {
    bool isFull = true;
    for (auto ingredient : IngredientType::IngredientType_All) {
        if (CoffeeMachine::ingredientsQuantity[ingredient] != CoffeeMachine::maxIngredientsQuantity[ingredient]) {
            isFull = false;
            break;
        }
    }

    if (isFull) {
        throw FullCoffeeMachineException("Aparatul de cafea este plin");
    }

    for (auto ingredient : IngredientType::IngredientType_All) {
        CoffeeMachine::ingredientsQuantity[ingredient] = CoffeeMachine::maxIngredientsQuantity[ingredient];
    }
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
    cout << "6. Verifica ingredientele" << endl;
    cout << "7. Completeaza ingredientele" << endl;

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
            case 6:
                ShowIngredientsView();
                break;
            case 7:
                ShowRefillView();
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
        for (list<shared_ptr<CoffeeBase>>::iterator it = coffeesHistory.begin(); it != coffeesHistory.end(); it++) {
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

void CoffeeMachine::ShowIngredientsView() {
    cout << endl;
    cout << "- - - - - Cantitati ingrediente - - - - - - - - - -" << endl;
    cout << "Ingredient (U.M.) - Cantitate / Cantitate maxima" << endl;

    for (auto ingredient : IngredientType::IngredientType_All) {
        cout << CoffeeMachine::ingredientsName[ingredient] << " - " << CoffeeMachine::ingredientsQuantity[ingredient] << " / " << CoffeeMachine::maxIngredientsQuantity[ingredient] << endl;
    }

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    cout << "Apasati o tasta pentru a reveni la meniul principal" << endl;
    cin.ignore();
    cin.get();

    ShowMainMenuView();
}

void CoffeeMachine::ShowRefillView() {
    cout << endl;
    try {
        CoffeeMachine::Refill();
        cout << "Aparatul de cafea a fost umplut" << endl;
    }
    catch (FullCoffeeMachineException& fcmex) {
        cout << "Aparatul de cafea nu a putut fi alimentat!" << endl;
        cout << "Eroare: " << fcmex.what() << endl;
    }

    ShowIngredientsView();
}

void CoffeeMachine::ShowPreparingCoffeeView(CoffeeType::CoffeeType coffeeType) {
    try {
        shared_ptr<CoffeeBase> coffee = nullptr;

        cout << endl;
        switch (coffeeType) {
            case CoffeeType::SimpleCoffee: {
                coffee = make_shared<SimpleCoffee>(
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee]
                );

                shared_ptr<SimpleCoffee> aux = dynamic_pointer_cast<SimpleCoffee>(coffee);
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water] -= aux->GetWater();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee] -= aux->GetCoffee();
                break;
            }
            case CoffeeType::CoffeeWithMilk: {
                coffee = make_shared<CoffeeWithMilk>(
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Milk]
                );

                shared_ptr<CoffeeWithMilk> aux = dynamic_pointer_cast<CoffeeWithMilk>(coffee);
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water] -= aux->GetWater();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee] -= aux->GetCoffee();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Milk] -= aux->GetMilk();
                break;
            }
            case CoffeeType::CoffeeWithSugar: {
                coffee = make_shared<CoffeeWithSugar>(
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Sugar]
                );

                shared_ptr<CoffeeWithSugar> aux = dynamic_pointer_cast<CoffeeWithSugar>(coffee);
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water] -= aux->GetWater();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee] -= aux->GetCoffee();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Sugar] -= aux->GetSugar();
                break;
            }
            case CoffeeType::CoffeeWithMilkAndSugar: {
                coffee = make_shared<CoffeeWithMilkAndSugar>(
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Milk],
                    CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Sugar]
                );

                shared_ptr<CoffeeWithMilkAndSugar> aux = dynamic_pointer_cast<CoffeeWithMilkAndSugar>(coffee);
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Water] -= aux->GetWater();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Coffee] -= aux->GetCoffee();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Milk] -= aux->GetMilk();
                CoffeeMachine::ingredientsQuantity[IngredientType::IngredientType::Sugar] -= aux->GetSugar();
                break;
            }
            default: {
                cout << "Tipul de cafea ales nu exista!" << endl;
                return ShowMainMenuView();
            }
        }

        cout << "Se prepara cafeaua..." << endl;
        coffee->Brew(cout);
        coffeesHistory.push_back(coffee);
        cout << "Cafeaua poate fi servita." << endl;
    }
    catch (InsufficientIngredientException& iiex) {
        cout << "Cafeaua nu a putut fi preparata." << endl;
        cout << "Eroare: " << iiex.what() << endl;
    }
    
    ShowMainMenuView();
}

void CoffeeMachine::ShowClosingView() {
    cout << endl;
    cout << "Aparatul de cafea se stinge..." << endl;
    coffeesHistory.clear();
}