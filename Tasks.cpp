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