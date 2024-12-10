#include <iostream>
#include "Tasks.h"

int main() {
    std::cout << "Performed by: Avramenko Roman Aleksandrovich\n";
    std::cout << "Group: 453503\n";
    std::cout << "Variant 1\n";
    int task;

    std::cout << "Choose option:\n1 - Task_1\n2 - Task_2\n3 - Task_3\n4 - Run Googletests\n5 - Exit program\n";
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
    }

    repeat();
}