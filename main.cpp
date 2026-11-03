#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;

int main(){

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string fio;
    string familia, name, patronymic;

    cout << "Введите ваше ФИО " << endl;
    getline (cin, fio);

    int lettersCount = 0;
    for (char c : fio) {
        if (c != ' ') {
            lettersCount++;
        }
    }

    stringstream ss(fio);
    ss >> familia >> name >> patronymic;
    string initials = string(1, name[0]) + "." + string(1, patronymic[0]) + ".";

    cout << "Количество символов в ФИО: " << lettersCount << endl;
    cout << "Ваши инициалы: " << familia << " " << initials << endl;
    return 0;
}
