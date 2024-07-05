/*RU
Условие:
Корректным арифметическим выражением будем считать строку, состоящую из 
положительных чисел, разделенных  между собой знаками арифметических операций 
(-,*,/,+) без пробелов. Одна цифра также считается корректным арифметическим 
выражением.
Вам необходимо найти подстроки, содержащие в себе корректные арифметические 
выражения.

Входные данные:
Вам дано некоторое количество строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все наибольшие корректные подстроки в порядке их следования в тексте, 
каждую в отдельной строке

Входные данные:
a+5*42/0
a1a

Выходные данные:
5*42
1

ENG
Condition:
A correct arithmetic expression will be considered a string consisting of
positive numbers separated by arithmetic signs
(-,*,/,+) without spaces. One digit is also considered valid arithmetic
expression.
You need to find substrings containing correct arithmetic
expressions.

Input data:
You are given a number of lines separated by symbols
line break.

Output:
Print all the largest valid substrings in the order they appear in the text,
each on a separate line

Input data:
a+5*42/0
a1a

Output:
5*42
1                                               */

#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    string input;
    string line;

    while (getline(cin, line)) {
        input += line + "\n";
    }

    regex expression("[1-9]\\d*([\\-\\+\\*\\/][1-9]\\d*)*");
    smatch match;
    string::const_iterator searchStart(input.cbegin());

    while (regex_search(searchStart, input.cend(), match, expression)) {
        string expression = match.str();
        cout << expression << endl;
        searchStart = match.suffix().first;
    }

    return 0;
}