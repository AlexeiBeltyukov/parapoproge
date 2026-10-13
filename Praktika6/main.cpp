#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

using namespace std::chrono;

void optimizeBubbleSort(int arr[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }

        }

        if (!swapped) {
            break;
        }
    }
}


int main () {

    auto start_time = high_resolution_clock::now();

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    srand(time(0));

    int size;
    cout << "Ведите размер массива: ";
    cin >> size;

    if (size <= 0 || size > 1000) {
        cout << "Размер должен быть положительным и не больше 1000." << endl;
        return 1;
    }

    int* arr = new int[size];

    cout << "Введите " << size << " элементов массива:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Элемент [" << i + 1 << "]: ";
        cin >> arr[i];
    }

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time).count();

    char order;
    cout << "\nВыберите порядок сортировки:\n";
    cout << "  'a' — по возрастанию\n";
    cout << "  'd' — по убыванию\n";
    cout << "Ваш выбор: ";
    cin >> order;


    bool ascending = true;
    if (order == 'd' || order == 'D'){
        ascending = false;
    } else if (order != 'a' && order != 'A') {
        cout << "Неверный выбор. По умолчанию сортировка по возрастанию." << endl;
    }

    optimizeBubbleSort(arr, size, ascending);

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Время выполнения кода: " << duration << " мс" << endl;

    delete[] arr;

    return 0;
}
