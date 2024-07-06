/*RU
Условие:
Дан набор цифр. Считайте его строкой и переведите в число. 
Выведите полученное число.

Входные данные:
На вход даётся набор цифр, соответствующий целому числу.

Выходные данные:
В выходной файл должно быть выведено соответствующее число.

Входные данные:
1)-12345
2)54321

Выходные данные:
1)-12345
2)54321

ENG
Condition:
Given a set of numbers. Treat it as a string and convert it to a number.
Print the resulting number.

Input data:
The input is a set of digits corresponding to an integer.

Output:
The corresponding number should be output to the output file.

Input data:
1)-12345
2)54321

Output:
1)-12345
2)54321                                                  */

#include <iostream>
using namespace std;

int main() {
	string digits;

	cin >> digits;

	int number = 0;
	int sign = 1;


	if (digits[0] == '-') {
		sign = -1;
		digits = digits.substr(1);
	}

	for (char c : digits) {
		number = number * 10 + (c - '0');
	}

	number *= sign;
	cout << number;

	return 0;
}