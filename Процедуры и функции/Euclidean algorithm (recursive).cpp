/*RU
Условие:
Дано два числа. Напишите функцию для вычисления НОДа этих чисел 
с помощью алгоритма Евклида.
НОД – наибольший общий делитель двух чисел.

Входные данные:
На вход даётся два натуральных числа a, b (a, b ≤ 109).

Выходные данные:
В выходной файл должен быть выведен НОД данных чисел.

ENG
Condition:
Two numbers are given. Write a function to calculate the GCD of these numbers
using the Euclidean algorithm.
GCD is the greatest common divisor of two numbers.

Input data:
The input is given two natural numbers a, b (a, b ≤ 109).

Output:
The GCD of these numbers should be output to the output file.*/

#include <iostream>
using namespace std;

int nod(int a, int b) {
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
    cout << nod(a, b) << endl;

    return 0;
}