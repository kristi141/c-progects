/*Условие:
Даны два натуральных числа a и b. Напишите функцию, возвращающую их 
максимум, и выведите его.

Входные данные:
В первой строке записаны числа a и b (1 ≤ a,b≤109 ).

Выходные данные:
Выведите максимальное из двух данных чисел.
Если числа одинаковы, выведите любое из них.*/

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