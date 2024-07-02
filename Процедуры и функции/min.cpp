/*Условие:
Даны два натуральных числа a и b. Напишите функцию, возвращающую их 
минимум, и выведите его.

Входные данные:
В первой строке записаны числа a и b (1 ≤ a,b≤109 ).

Выходные данные:
Выведите минимальное из данных чисел.
Если числа одинаковы, выведите любое из них.*/

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