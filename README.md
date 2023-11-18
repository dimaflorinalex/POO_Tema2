# Laborator POO - 2023/2024 - Tema 2
## Dima Florin-Alexandru - Grupa 262 - CTI, FMI Unibuc

Titlu: Aparat de cafea

Descriere: Interfata/logica unui aparat de cafea pentru prepararea catorva tipuri de cafele

### Functiile aplicatiei:
0. Stinge aparatul de cafea > Inchide aplicatia
1. Istoric cafele > Istoricul cafelelor preparate + data si ora
2. Prepara o cafea simpla > Prepara o cafea simpla
3. Prepara o cafea cu lapte > Prepara o cafea simpla la care adaugam lapte
4. Prepara o cafea cu zahar > Prepara o cafea simpla la care adaugam zahar
5. Prepara o cafea cu lapte si zahar > Prepara o cafea simpla la care adaugam lapte si zahar
6. Verifica ingredientele > Verifica cantitatile de ingrediente din aparatul de cafea (apa, cafea, zahar, lapte)
7. Completeaza ingredientele > Umple aparatul de cafea cu ingrediente

- Exista protectie impotriva optiunilor invalide.

### Clase
1. CoffeeMachine - Contine doar membri si metode statice, nu este permisa instantierea ei (este o clasa "statica"). Are rolul de a tine starea globala a aparatului de cafea (istoric cafele, ingrediente, cantitati maxime de ingrediente), de a gestiona navigatia si helper pentru gestionarea datelor.
2. CoffeeBase - Clasa abstracta: clasa de baza pentru tipurile de cafele
3. SimpleCoffee - Cafea simpla, mosteneste CoffeeBase
4. CoffeeWithMilk - Cafea cu lapte, mosteneste SimpleCoffee
5. CoffeeWithSugar - Cafea cu zahar, mosteneste SimpleCoffee
6. CoffeeWithMilkAndSugar - Cafea cu lapte si zahar, mosteneste CoffeeWithMilk si CoffeeWithSugar: rezolvam "Problema diamantului" (The Diamond Inheritance Problem) folosind mostenire virtuala.

### Enums
1. IngredientType - Tipul ingredientelor (apa, cafea, zahar, lapte) (util pentru dictionare / unordered maps)
2. CoffeeType - Tipurile de cafele (util pentru selectia pe baza input-ului utilizatorului)

### Exceptii
1. FullCoffeeMachineException - Aparatul de cafea nu poate fi umplut, deoarece este deja plin (toate ingredientele au cantitatea maxima)
2. InsufficientIngredientException - Aparatul de cafea nu are suficienta cantitate dintr-un ingredient pentru a prepara cafeaua

### Obiective:
- Separarea codului din clase în .h (sau .hpp) și .cpp
- Minim o clasă de bază și 3 clase derivate (cu bază proprie, cele cu bază predifinită pot fi în plus)
- Minim o funcție virtuală va fi specifică temei (e.g. nu simple citiri/afișări)
- Minim un exemplu de polimorfism
- Apelarea constructorului clasei de bază din constructori ai clasei derivate
- Smart pointers
- Conversii de tipuri pentru pointeri către clase
- Suprascris metode (e.g. operatorul= pentru copieri/atribuiri corecte)
- Excepții (clase derivate din std::exception; minim 2 clase pentru erori specifice)
- Utilizare cu sens: de exemplu, throw în constructor, try/catch în main
- Funcții și atribute static
- Cât mai multe const
- Utilizare STL
