#include <iostream>
#include <string>
#include "Functions.h"


void Task_1() {
    std::cout << "Перевести чилсло из прямого кода в обратный\n";
    std::cout << "Решение:\n";
    std::string number;
    std::cout << "Введите число в прямом коде:\n";
    number = CheckSystem(2, 1);

    number = DirectToReverse(number);

    std::cout << "Число в обратном коде:\n" << number << '\n';
}

void Task_2() {
    std::cout << "Найти сумму двоичных чисел, заданных в естесвенной форме\n";
    std::cout << "Сложение выполнить в дополнительном коде. Ответ вывети в прямом коде\n";
    std::cout << "Решение\n";
    std::cout << "Введите два числа в естественной форме:\n";
    std::string number_1, number_2;
    bool negative_1 = false, negative_2 = false;
    number_1 = CheckSystem(10, 0);
    number_2 = CheckSystem(10, 0);

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
    std::cout << "Сумма чисел в прямом коде: " << sum << '\n';
}

void Task_3() {
    std::cout << "Осуществить сложение и вычитание чисел в заданной системе счисления\n";
    std::cout << "Решение:\n";
    std::cout << "Введите основание системы:\n";
    unsigned long long system;
    system = CheckUnsigned();
    std::cout << "Введите два числа в " << system << "-ой системе:\n";
    std::string number_1, number_2;
    number_1 = CheckSystem(system, 0);
    number_2 = CheckSystem(system, 0);

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
        sum = SubtractNumbers(number_2, number_1, system);
    }
    else if (negative_2){
        sum = SubtractNumbers(number_1, number_2, system);
    }
    else {
        sum = SumNumbers(number_1, number_2, system);
    }
    std::cout << number_1 << " + " << number_2 << " = " << sum << '\n';

    std::cout << "Разность чисел:\n";
    if (negative_1 && negative_2){
        diference = SubtractNumbers(number_2, number_1, system);
    }
    else if (negative_1){
        diference = SumNumbers(number_1, number_2, system);
        diference = AddMinus(diference);
    }
    else if (negative_2){
        diference = SumNumbers(number_1, number_2, system);
    }
    else {
        diference = SubtractNumbers(number_1, number_2, system);
    }
    std::cout << number_1 << " - " << number_2 << " = " << diference << '\n';
}

void Task_4() {
    std::cout << "Проверить делится ли число на 3, 37 и 89\n";
    std::cout << "Решение:\n";
    unsigned long long number;
    std::cout << "Введите число:\n";
    number = CheckUnsigned();
    bool cont = true;
    while (cont){
        std::cout << "Проверить делимость на (1 - 3, 2 - 37, 3 - 89, 4 - выйти):\n";
        int input;
        std::cin >> input;
        switch (input){
        case 1:
            if (checkDivisible(number, 3, 1, 2)){
                std::cout << number << " делится на 3\n";
            }
            else {
                std::cout << number << " не делится на 3\n";
            }
            break;
        case 2:
            if (checkDivisible(number, 37, 4, 7)){
                std::cout << number << " делится на 37\n";
            }
            else {
                std::cout << number << " не делится на 37\n";
            }
            break;
        case 3:
            if (checkDivisible(number, 89, 2, 67)){
                std::cout << number << " делится на 89\n";
            }
            else {
                std::cout << number << " не делится на 89\n";
            }
            break;
        case 4:
            cont = false;
            break;
        default:
            std::cout << "Неверный номер!\n";
        }
    }
}

void Task_5() {
    std::cout << "Одна из 240 бочек отравлена, необходимо определить какая\n";
    std::cout << "Яд проявляет себя через 24 часа, после принятия. Бочку необходимо найти за 48 часов\n";
    std::cout << "Есть 5 рабов, которыми можно пожертвовать\n";
    std::cout << "Решение:\n";
    std::cout << "Загадайте одну бочку, в которой находится яд(номера бочек от 1 до 240)\n";
    std::string barrel;

    for (int i = 1; i <= 5; i++){
        barrel.push_back(EnterSlavesDay(i));
    }

    if (barrel == "00000" || barrel == "22221" || barrel == "22222"){
        std::cout << "Такая ситуация невозможна!\n";
    }
    else {
        int poison = FindBarrel(barrel);
        std::cout << "Отравлена бочка под номером " << poison << '\n';
    }
}
