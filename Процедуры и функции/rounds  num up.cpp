/*Условие:
Дано дробное число. Необходимо написать function, которая округляет 
данное число вверх.

Входные данные:
Входной файл содержит единственное дробное число N (0 < N ≤ 100).

Выходные данные:
В выходной файл необходимо вывести результат округления числа N вверх.*/

#include <iostream>
#include <cmath>
using namespace std;

double roundUp(double num) {
    if (num >= 0.0) {
        return ceil(num);
    } else {
        return floor(num);
    }
}

int main() {
    double N;
   cin >> N;

    double rounded = roundUp(N);

    cout << rounded << endl;

    return 0;
}