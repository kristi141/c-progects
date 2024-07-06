/*RU
Условие:
Даны два числа. Необходимо вычислить НОД этих чисел, используя быстрый 
алгоритм Евклида.
НОД – наибольший общий делитель двух чисел.

Входные данные:
На вход даются два натуральных числа a, b (a, b ≤ 109).

Выходные данные:
В выходной файл необходимо вывести единственное значение - НОД данных чисел.

Входные данные:
32 24

Выходные данные:
8

ENG
Condition:
Two numbers are given. It is necessary to calculate the gcd of these numbers 
using a quick Euclidean algorithm.
GCD is the greatest common divisor of two numbers.

Input data:
The input is given two natural numbers a, b (a, b ≤ 109).

Output:
The only value that needs to be output to the output file is the gcd of 
these numbers.

Input data:
32 24

Output:
8                                                             */

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