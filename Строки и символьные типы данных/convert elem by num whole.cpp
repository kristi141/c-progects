/*Условие:
Дан набор цифр. Считайте его строкой и переведите в число. 
Выведите полученное число.

Входные данные:
На вход даётся набор цифр, соответствующий целому числу.

Выходные данные:
В выходной файл должно быть выведено соответствующее число.*/

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