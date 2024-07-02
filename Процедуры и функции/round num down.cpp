/*Условие:
Вам дано дробное число. Напишите процедуру, которая округлит его вниз.

Входные данные:
Содержит дробное число N  (0 < N ≤ 100).

Выходные данные:
Результат округления числа вниз.*/

#include <iostream>
#include <cmath>
using namespace std;

double roundDown(double num) {
    if (num >= 0.0) {
        return floor(num);
    } else {
        return ceil(num);
    }
}

int main() {
    double N;
    cin >> N;

    double roundedDown = roundDown(N);

    cout << roundedDown << endl;

    return 0;
}