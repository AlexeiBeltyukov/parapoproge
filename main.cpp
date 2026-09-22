#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main () {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0));

    std::string firstName;
    std::string lastName;
    int Parol;

    std::cout << "¬ведите ваше им€: ";
    std::cin >> firstName;

    std::cout << "¬ведите вашу фамилию: ";
    std::cin >> lastName;

    std::cout << "¬ведите число символов в пароле: ";
    std::cin >> Parol;

    std::string fullName = lastName + " " + firstName;
    std::string finalPassword = "";
    int counter = 0;

    for (int i = fullName.length() - 1; i >= 0; i--) {
        if (counter == Parol) {
            break;
        }
         finalPassword += fullName[i];
         counter++;
    }
    std::cout << "¬аш пароль: " << finalPassword << std::endl;

    return 0;
}
