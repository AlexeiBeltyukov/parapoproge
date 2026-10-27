#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

struct Student {
    string name;
    int age;
    int group;
    int mark;
    double avg_mark;
};
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Student> students = {
        {"Юрченко Артем", 19, 4511, 85, 4.2},
        {"Кравчук Сергей", 20, 4510, 95, 4.8},
        {"Куценко Данил", 19, 4509, 78, 3.9},
        {"Алексеев Захар", 19, 4507, 92, 4.7}
    };


    int bestIndex = 0;

    for (size_t i = 1; i < students.size(); ++i) {
        if (students[i].avg_mark > students[bestIndex].avg_mark) {
            bestIndex = i;
        }
    }

    cout << "Студент с максимальной средней оценкой :" << endl;
    cout << "Имя: " << students[bestIndex].name << endl;
    cout << "Средняя оценка: " << students[bestIndex].avg_mark << endl;
    cout << "Все студенты: " << endl;
    for (const auto& s : students) {
        cout << s.name << "| Группа: " << s. group << " | Ср.балл: " << s.avg_mark << endl;
    }

    return 0;
}

