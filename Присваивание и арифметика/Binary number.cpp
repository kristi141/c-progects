/*RU
Условие:
Дано число.
Необходимо перевести его в двоичную систему счисления.

Входные данные:
На вход даётся целое число n (n < 17).

Выходные данные:
В выходной файл должно быть выведено единственное значение - 
двоичная запись заданного числа n.

ENG
Condition:
A number is given.
It is necessary to convert it to the binary number system.

Input data:
The input is an integer n (n < 17).

Output:
A single value should be output to the output file -
binary representation of a given number n.*/

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