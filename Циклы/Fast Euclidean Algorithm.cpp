/*Условие:
Даны два числа. Необходимо вычислить НОД этих чисел, используя быстрый 
алгоритм Евклида.
НОД – наибольший общий делитель двух чисел.

Входные данные:
На вход даются два натуральных числа a, b (a, b ≤ 109).

Выходные данные:
В выходной файл необходимо вывести единственное значение - НОД данных чисел.*/

#include <iostream>
using namespace std;

int fastEuclideanAlgorithm(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << fastEuclideanAlgorithm(a, b);

    return 0;
}