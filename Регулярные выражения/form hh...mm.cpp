/*Условие:
Вам дан набор строк, разделенных между собой символами переноса строки. 
Найдите все корректные подстроки вида чч:мм (00 ≤ чч ≤ 23, 00 ≤ мм ≤ 59).

Входные данные:
Вам дано некоторое количество строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все необходимые подстроки в порядке их следования в тексте, 
отделяя каждую переносом строки.*/

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