#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

size_t visualLength(const string& str) {
    size_t len = 0;
    for (unsigned char c : str) {
        if ((c & 0xC0) != 0x80) {
            len++;
        }
    }
    return len;
}

void printCell(const string& text, size_t width) {
    cout << text;
    size_t vLen = visualLength(text);
    if (width > vLen) {
        cout << string(width - vLen, ' ');
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("students.txt");

    if (file.is_open()) {
        cout << "Файл открыт успешно!\n\n";

        string line;
        bool isHeader = true;

        string youngestFio = "";
        string youngestDate = "";
        string youngestWeight = "";

        double maxBmi = -1.0;
        string maxBmiFio = "";
        string maxBmiWeight = "";
        string maxBmiStr = "";

        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string fio, birthDate, height, weight;

            getline(ss, fio, ';');
            getline(ss, birthDate, ';');
            getline(ss, height, ';');
            getline(ss, weight, ';');

            fio = trim(fio);
            birthDate = trim(birthDate);
            height = trim(height);
            weight = trim(weight);

            if (isHeader) {
                printCell(fio, 33);
                printCell(weight, 10);
                printCell("ИМТ", 10);
                cout << endl;
                cout << string(53, '-') << endl;
                isHeader = false;
            } else {
                double hMeters = stod(height) / 100.0;
                double wKg = stod(weight);
                double bmi = wKg / (hMeters * hMeters);

                stringstream bmiStream;
                bmiStream << fixed << setprecision(2) << bmi;
                string bmiText = bmiStream.str();

                printCell(fio, 33);
                printCell(weight, 10);
                printCell(bmiText, 10);
                cout << endl;

                if (fio.size() >= 2 && fio.substr(fio.size() - 2) == "на") {
                    if (youngestDate.empty() || birthDate > youngestDate) {
                        youngestFio = fio;
                        youngestDate = birthDate;
                        youngestWeight = weight;
                    }
                }

                if (bmi > maxBmi) {
                    maxBmi = bmi;
                    maxBmiFio = fio;
                    maxBmiWeight = weight;
                    maxBmiStr = bmiText;
                }
            }
        }

        cout << "\nСамый молодой студент-девушка:\n";
        if (!youngestFio.empty()) {
            printCell(youngestFio, 33);
            printCell(youngestWeight, 10);
            cout << endl;
        } else {
            cout << "Девушки в списке не найдены." << endl;
        }


        cout << "\nСтудент с максимальным ИМТ:\n";
        if (!maxBmiFio.empty()) {
            printCell(maxBmiFio, 33);
            printCell(maxBmiWeight, 10);
            printCell(maxBmiStr, 10);
            cout << endl;
        }

        file.close();
    } else {
        cout << "Не удалось открыть файл" << endl;
    }

    return 0;
}
