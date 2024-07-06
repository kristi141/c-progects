/*RU
Условие:
Дано число. Выведите символ, соответствующий данному числу в ASCII таблице.
ASCII таблица – таблица, в которой некоторым распространённым печатным и 
непечатным символам сопоставлены числовые коды.

Входные данные:
На вход даётся натуральное число a (32 < a < 256)

Выходные данные:
В выходной файл должен быть выведен соответствующий символ.

Входные данные:
1)35

2)48

Выходные данные:
1)#

2)0

ENG
Condition:
A number is given. Print the character corresponding to the given number in the ASCII table.
ASCII table - a table in which some common printed and
non-printable characters are assigned numeric codes.

Input data:
The input is a natural number a (32 < a < 256)

Output:
The corresponding symbol must be output to the output file.

Input data:
1)35

2)48

Output:
1)#

2)0                                                              */

#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << (char)a;
	return 0;
}