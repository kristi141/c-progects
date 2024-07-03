/*RU
Условие:
Даны два натуральных числа a и b. Напишите функцию, возвращающую их 
минимум, и выведите его.

Входные данные:
В первой строке записаны числа a и b (1 ≤ a,b≤109 ).

Выходные данные:
Выведите минимальное из данных чисел.
Если числа одинаковы, выведите любое из них.

ENG
Condition:
Given two natural numbers a and b. Write a function that returns them
minimum and output it.

Input data:
The first line contains the numbers a and b (1 ≤ a,b≤109 ).

Output:
Print the minimum of the given numbers.
If the numbers are the same, print any of them.*/

#include <iostream>
using namespace std;

int min(int a, int b) {
    if (a < b){
      return a;
    } else if (a == b){
      return b;
    } else {
      return b;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << min(a, b) << endl;

    return 0;
}