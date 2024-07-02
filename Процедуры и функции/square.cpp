/*Условие:
Необходимо реализовать функцию, возвращающую квадрат заданного числа N.

Входные данные:
На вход даётся одно число N (-104 ≤ N ≤ 104).

Выходные данные:
В выходной файл необходимо вывести квадрат данного числа N.*/

#include <iostream>
using namespace std;

int square(int a) {
    return a * a;
}
int main() {
    int a;
    cin >> a;
    cout << square(a) << endl;

    return 0;
}