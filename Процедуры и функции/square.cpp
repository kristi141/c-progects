/*RU
Условие:
Необходимо реализовать функцию, возвращающую квадрат заданного числа N.

Входные данные:
На вход даётся одно число N (-104 ≤ N ≤ 104).

Выходные данные:
В выходной файл необходимо вывести квадрат данного числа N.

ENG
Condition:
It is necessary to implement a function that returns the square of a given 
number N.

Input data:
One number N is given as input (-104 ≤ N ≤ 104).

Output:
The square of the given number N must be output to the output file.*/

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