/*Условие:
Дано число. Напишите функцию для перевода его в строку.

Входные данные:
На вход даётся число.

Выходные данные:
В выходной файл должна быть выведена полученная строка.*/

#include <iostream>
#include <string>
using namespace std;

string numberToString(int number) {
    string str = "";
    bool isNegative = false;

    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    while (number > 0) {
        char digit = '0' + (number % 10);
        str = digit + str;
        number /= 10;
    }

    if (isNegative) {
        str = "-" + str;
    }

    return str;
}

int main() {
    int number;
    cin >> number;

    string result = numberToString(number);

    cout << result << endl;

    return 0;
}