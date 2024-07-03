/*RU
Условие:
Дано число. Необходимо определить количество разрядов этого числа.

Входные данные:
На вход даётся натуральное число n (n ≤ 109).

Выходные данные:
В выходной файл необходимо вывести единственное значение - 
количество разрядов числа n.

ENG
Condition:
A number is given. It is necessary to determine the number of digits of 
this number.

Input data:
The input is a natural number n (n ≤ 109).

Output:
The only value you need to output to the output file is -
number of digits of number n.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int digit = 0;

	if (n == 0) {
		digit = 1;
	}
	else {
		while (n != 0) {
			n /= 10;
			digit++;
		}
	}

	cout << digit;

	return 0;
}