#include <iostream>
#include <string>
#include "Functions.h"


void Task_1(){
    std::string number;
    std::cout << "Введите число в прямом коде:\n";
    std::cin >> number;

    number = DirectToReverse(number);

    std::cout << "Число в обратном коде:\n" << number << '\n';
}

void Task_2(){
    std::cout << "Введите два числа в естественной форме:\n";
    std::string number_1, number_2;
    bool negative_1 = false, negative_2 = false;
    std::cin >> number_1 >> number_2;

    if (number_1[0] == '-'){
        negative_1 = true;
        number_1.erase(0, 1);
    }
    if (number_2[0] == '-'){
        negative_2 = true;
        number_2.erase(0, 1);
    }

    number_1 = DecToDirect(number_1, negative_1);
    number_2 = DecToDirect(number_2, negative_2);

    number_1 = DirectToAdditional(number_1);
    number_2 = DirectToAdditional(number_2);

    size_t size = std::max(number_1.size(), number_2.size());
    std::string sum = SumNumbers(number_1, number_2, 2);
    if (sum.size( )> size){
        sum.erase(0, 1);
    }
    sum = DirectToAdditional(sum);
    std::cout << DeleteZeroes(sum) << '\n';
}

void Task_3(){
    std::cout << "Введите основание системы:\n";
    int system;
    std::cin >> system;
    std::cout << "Введите два числа в " << system << "-ой системе:\n";
    std::string number_1, number_2;
    std::cin >> number_1 >> number_2;

    bool negative_1 = false, negative_2 = false;
    if (number_1[0] == '-'){
        negative_1 = true;
        number_1.erase(0, 1);
    }
    if (number_2[0] == '-'){
        negative_2 = true;
        number_2.erase(0, 1);
    }

    std::string sum, diference;
    std::cout << "Сумма двух чисел:\n";
    if (negative_1 && negative_2){
        sum = SumNumbers(number_1, number_2, system);
        sum = AddMinus(sum);
    }
    else if (negative_1){
        sum = SubstractNumber(number_2, number_1, system);
    }
    else if (negative_2){
        sum = SubstractNumber(number_1, number_2, system);
    }
    else {
        sum = SumNumbers(number_1, number_2, system);
    }
    std::cout << sum << '\n';

    std::cout << "Разность чисел:\n";
    if (negative_1 && negative_2){
        diference = SubstractNumber(number_2, number_1, system);
    }
    else if (negative_1){
        diference = SumNumbers(number_1, number_2, system);
        diference = AddMinus(diference);
    }
    else if (negative_2){
        diference = SumNumbers(number_1, number_2, system);
    }
    else {
        diference = SubstractNumber(number_1, number_2, system);
    }
    std::cout << diference << '\n';
}

void Task_4(){
    long long number;
    std::cout << "Введите число:\n";
    std::cin >> number;
    std::cout << "Проверить делимость на (1 - 3, 2 - 37, 3 - 89):\n";
    int input;
    std::cin >> input;
    switch (input){
    case 1:
        if (checkDivisible(number, 3, 1, 1, 2)){
            std::cout << number << " делится на 3\n";
        }
        else {
            std::cout << number << " не делится на 3\n";
        }
        break;
    case 2:
        if (checkDivisible(number, 37, 4, 15, 7)){
            std::cout << number << " делится на 37\n";
        }
        else {
            std::cout << number << " не делится на 37\n";
        }
        break;
    case 3:
        if (checkDivisible(number, 89, 4, 15, 39)){
            std::cout << number << " делится на 89\n";
        }
        else {
            std::cout << number << " не делится на 89\n";
        }
        break;
    default:
        std::cout << "Неверный номер!\n";
    }
}
