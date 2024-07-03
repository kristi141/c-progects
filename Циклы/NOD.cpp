/*RU
Условие:
Даны два натуральных числа a и b.
Необходимо найти и вывести их наибольший общий делитель.
Примечание: наибольший общий делитель двух чисел – 
наибольшее число, являющееся делителем каждого из этих чисел.

Входные данные:
В первой строке входного файла даны два натуральных числа a и b 
(1 ≤ a,b ≤ 10^8).

Выходные данные:
В выходной файл необходимо вывести единственное значение - 
наибольший общий делитель чисел a и b.

ENG
Condition:
Given two natural numbers a and b.
It is necessary to find and derive their greatest common divisor.
Note: The greatest common divisor of two numbers is
the largest number that is a divisor of each of these numbers.

Input data:
The first line of the input file contains two natural numbers a and b
(1 ≤ a,b ≤ 10^8).

Output:
The only value you need to output to the output file is -
greatest common divisor of numbers a and b.*/

#include<iostream>
using namespace std;

int main() {
    int a;
    int b;
    int i;

    cin >> a;
    cin >> b;

    for ( i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << i;
            break;
        }
    }
    return 0;
}