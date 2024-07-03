/*RU
Условие:
Необходимо реализовать функцию, возвращающую модуль заданного числа N.

Входные данные:
На вход даётся одно число N (-109 ≤ N ≤ 109).

Выходные данные:
В выходной файл необходимо вывести модуль числа N.

ENG
Condition:
It is necessary to implement a function that returns the modulus of a given 
number N.

Input data:
One number N is given as input (-109 ≤ N ≤ 109).

Output:
The modulus of the number N must be output to the output file.*/

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