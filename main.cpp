#include <iostream>
#include "Tasks.h"
#include "Functions.h"

int main() {
    std::cout << "Выполнил Авраменко Роман Александрович\n";
    std::cout << "Группа: 453503\n";
    std::cout << "Вариант 1\n";
    int task;

    std::cout << "Выберите пункт меню:\n1 - Task_1\n2 - Task_2\n3 - Task_3\n4 - Task_4\n5 - Task_5\n6 - Выйти\n";
    std::cin >> task;

    switch (task) {
    case 1:
        Task_1();
        break;
    case 2:
        Task_2();
        break;
    case 3:
        Task_3();
        break;
    case 4:
        Task_4();
        break;
    case 5:
        Task_5();
        break;
    case 6:
        break;
    default:
        std::cout << "Неверный символ!\n";
    }

    repeat();
}