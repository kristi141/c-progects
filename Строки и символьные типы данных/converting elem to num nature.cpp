/*RU
Условие:
Дан набор цифр. Считайте его строкой и переведите в число. 
Выведите полученное число.

Входные данные:
На вход даётся набор цифр, соответствующий числу.

Выходные данные:
В выходной файл должно быть выведено соответствующее число.

ENG
Condition:
Given a set of numbers. Treat it as a string and convert it to a number.
Print the resulting number.

Input data:
The input is given a set of digits corresponding to the number.

Output:
The corresponding number should be output to the output file.*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;

    int result = 0;
    for (size_t i = 0; i < a.length(); i++) {
        result = result * 10 + (a[i] - '0');
    }

   cout << result;
}