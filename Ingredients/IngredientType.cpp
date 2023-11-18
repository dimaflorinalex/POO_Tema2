#pragma once

namespace IngredientType {
    enum IngredientType {
        Water = 0,
        Coffee = 1,
        Sugar = 2,
        Milk = 3
    };

    constexpr std::initializer_list<IngredientType> IngredientType_All = { Water, Coffee, Sugar, Milk };
}