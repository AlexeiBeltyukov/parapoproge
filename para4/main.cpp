#include <iostream>
#include <windows.h>
#include "func.h"
using namespace std;
int mull(int a, int b){
    return a*b; }
int main(){
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
    int a,b;
    cout << "Введите два числа: " << endl;
    cin >> a >> b;
    cout << "Произведение: " << mull(a, b) << endl;
    return 0;
}
