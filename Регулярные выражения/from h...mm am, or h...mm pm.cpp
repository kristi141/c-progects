/*RU
Условие:
Вам дан набор строк, разделенных между собой символами переноса строки.
Вам необходимо найти все корректные подстроки вида чч:мм  
(00 ≤ чч ≤ 23, 00 ≤ мм ≤ 59), или ч:мм am (0≤ч≤12, 00 ≤ мм ≤ 59), или ч:мм 
pm (0≤ч≤12, 00 ≤ мм ≤ 59).
Обратите внимание, что в корректных подстроках вида «ч:мм am» и «ч:мм pm» 
значение времени (ч:мм) отделено от обозначения времени суток (am /pm) 
символом пробела.

Входные данные:
Во входном файле вам дан набор строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все наибольшие корректные подстроки в порядке их следования в 
тексте, каждую в отдельной строке.

Входные данные:
aaa3:12bbb
d5:54 amsdp
13:23

Выходные данные:
5:54 am
13:23

ENG
Condition:
You are given a set of lines separated by line breaks.
You need to find all valid substrings of the form hh:mm
(00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59), or h:mm am (0≤h≤12, 00 ≤ mm ≤ 59), or h:mm
pm (0≤h≤12, 00 ≤ mm ≤ 59).
Please note that in the correct substrings of the form “h:mm am” and “h:mm pm”
The time value (h:mm) is separated from the time of day (am / pm)
space character.

Input data:
In the input file you are given a set of lines separated by characters
line break.

Output:
Print all the largest valid substrings in the order they appear in
text, each on a separate line.

Input data:
aaa3:12bbb
d5:54 amsdp
13:23

Output:
5:54 am
13:23                                      */

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        regex pattern("([0-9]|(1[0-2])):[0-5][0-9]\\s(am|pm)|((([01][0-9])|(2[0-3])):[0-5][0-9])");

        auto wordStart = sregex_iterator(input.begin(), input.end(), pattern);
        auto wordEnd = sregex_iterator();

        for (sregex_iterator i = wordStart; i != wordEnd; ++i) {
            smatch match = *i;
            cout  << match.str() << endl;
        }
    }

    return 0;
}