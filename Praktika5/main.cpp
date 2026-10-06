#include <windows.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

int main () {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(0));

    const int MAX_LEN = 51;

    char firstName [MAX_LEN];
    char lastName [MAX_LEN];

    std::cout << "¬ведите ваше им€: ";
    std::cin.getline(firstName, MAX_LEN);

    std::cout << "¬ведите вашу фамилию: ";
    std::cin.getline(lastName, MAX_LEN);

    std::cout << "¬аш пароль ";

    char* p = lastName;
    int len = strlen(p);

    if (len > 0) {
        p = p + (len - 1);
        while (p >= lastName) {
            std::cout << *p;
            p--;
        }
    }

    std::cout << " ";

    p = firstName;
    len = strlen(p);

    if (len > 0) {
        p = p + (len - 1);

        while (p >= firstName) {
            std::cout << *p;
            p--;
        }
    }

    std::cout << std::endl;

    return 0;
}
