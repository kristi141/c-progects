/*RU
Условие:
Дана строка. Напишите функцию для перевода её в число.

Входные данные:
На вход даётся число в виде строки.

Выходные данные:
В выходной файл должно быть выведено полученное число.

ENG
Condition:
Given a string. Write a function to convert it to a number.

Input data:
The input is a number in the form of a string.

Output:
The resulting number should be printed in the output file.*/

#include <iostream>
using namespace std;

int stringToNumber(string str) {
    int number = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    while (i < str.length()) {
        number = number * 10 + (str[i] - '0');
        i++;
    }

    return number * sign;
}

int main() {
    string str;
    cin >> str;

    int result = stringToNumber(str);

    cout << result << endl;

    return 0;
}