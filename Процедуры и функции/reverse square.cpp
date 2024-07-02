/*Условие:
Необходимо реализовать функцию, ктороая возводит число N в степень D.

Входные данные:
На вход даётся число N (-10 ≤ N ≤ 10) и число D (1 ≤ D ≤ 9).

Выходные данные:
В выходной файл необходимо вывести число N, возведенное в требуемую степень.*/

#include <iostream>
using namespace std;

int power(int N, int D) {
    int result = 1;
    for (int i = 0; i < D; i++) {
        result *= N;
    }
    return result;
}

int main() {
    int N, D;
    cin >> N >> D;
   cout << power(N, D) << endl;

    return 0;
}