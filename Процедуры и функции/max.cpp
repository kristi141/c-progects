/*RU
Условие:
Даны два натуральных числа a и b. Напишите функцию, возвращающую их 
максимум, и выведите его.

Входные данные:
В первой строке записаны числа a и b (1 ≤ a,b≤109 ).

Выходные данные:
Выведите максимальное из двух данных чисел.
Если числа одинаковы, выведите любое из них.

ENG
Condition:
Given two natural numbers a and b. Write a function that returns them
maximum and output it.

Input data:
The first line contains the numbers a and b (1 ≤ a,b≤109 ).

Output:
Print the maximum of the two given numbers.
If the numbers are the same, print any of them.*/

#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b){
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
    cout << max(a, b) << endl;

    return 0;
}