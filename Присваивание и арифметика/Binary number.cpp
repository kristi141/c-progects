/*Условие:
Дано число.
Необходимо перевести его в двоичную систему счисления.

Входные данные:
На вход даётся целое число n (n < 17).

Выходные данные:
В выходной файл должно быть выведено единственное значение - 
двоичная запись заданного числа n.*/

#include <iostream>
using namespace std;

void convertToBinary(int n) {
    if (n > 1) {
        convertToBinary(n/2);
    }
    cout << n % 2;
}

int main() {
    int n;
    cin >> n;
    convertToBinary(n);
    return 0;
}