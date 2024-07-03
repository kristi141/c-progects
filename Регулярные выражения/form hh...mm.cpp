/*RU
Условие:
Вам дан набор строк, разделенных между собой символами переноса строки. 
Найдите все корректные подстроки вида чч:мм (00 ≤ чч ≤ 23, 00 ≤ мм ≤ 59).

Входные данные:
Вам дано некоторое количество строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все необходимые подстроки в порядке их следования в тексте, 
отделяя каждую переносом строки.

ENG
Condition:
You are given a set of lines separated by line breaks.
Find all valid substrings of the form hh:mm (00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59).

Input data:
You are given a number of lines separated by symbols
line break.

Output:
Print all the necessary substrings in the order they appear in the text,
separating each with a line break.*/

#include <iostream>
#include <regex>
using namespace std;

int main() {
string input;

while (getline(cin, input)) {
    regex pattern("(([01][0-9])|(2[0-3])):[0-5][0-9]");
    smatch match;

    while (regex_search(input, match, pattern)) {
        cout << match.str() << endl; 
        input = match.suffix().str();
    }
}

return 0;
}