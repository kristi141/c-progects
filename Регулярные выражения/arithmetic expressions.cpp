/*Условие:
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
каждую в отдельной строке*/

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