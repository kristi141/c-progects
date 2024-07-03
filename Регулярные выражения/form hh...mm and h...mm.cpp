/*RU
Условие:
Вам дан набор строк, разделенных между собой символами переноса строки. 
Найдите все корректные подстроки вида чч:мм (00 ≤ чч ≤ 23, 00 ≤ мм ≤ 59) ИЛИ 
ч:мм(0≤ч≤12, 00 ≤ мм ≤ 59).

Входные данные:
Вам дано некоторое количество строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все подстроки вида чч:мм (00 ≤ чч ≤ 23, 00 ≤ мм ≤ 59)  ИЛИ 
ч:мм(0≤ч≤12, 00 ≤ мм ≤ 59) в порядке их следования в тексте, каждую в 
отдельной строке

ENG
Condition:
You are given a set of lines separated by line breaks.
Find all valid substrings of the form hh:mm (00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59) OR
h:mm(0≤h≤12, 00 ≤ mm ≤ 59).

Input data:
You are given a number of lines separated by symbols line break.

Output:
Print all substrings of the form hh:mm (00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59) OR
h:mm(0≤h≤12, 00 ≤ mm ≤ 59) in the order they appear in the text, each in
separate line*/

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string input;

    while (getline(cin, input)) {
        regex pattern("((([01]?[0-9])|(2[0-3])):[0-5][0-9])|(([0-9]|1[0-2]):[0-5][0-9])");
        smatch match;

        while (regex_search(input, match, pattern)) {
            cout << match.str() << endl;
            input = match.suffix().str();
        }
    }

    return 0;
}