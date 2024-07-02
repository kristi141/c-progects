/*Условие:
Необходимо реализовать функцию, возвращающую модуль заданного числа N.

Входные данные:
На вход даётся одно число N (-109 ≤ N ≤ 109).

Выходные данные:
В выходной файл необходимо вывести модуль числа N.*/

#include <iostream>
using namespace std;

int abs(int n) {
    if (n < 0) {
        return -n;
    } else {
        return n;
    }
}

int main() {
    int n;
    cin >> n;

    int result = abs(n);

    cout << result << endl;

    return 0;
}