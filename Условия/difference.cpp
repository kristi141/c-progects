/*RU
Условие:
Дано трёхзначное число.
Необходимо определить являются ли все цифры в нём различными.

Входные данные:
На вход даётся натуральное трёхзначное число.

Выходные данные:
В выходной файл должна быть выведена единица, 
если все цифры в числе различны, и ноль в противном случае.

Входные данные:
123

Выходные данные:
1

ENG
Condition:
A three-digit number is given.
It is necessary to determine whether all the numbers in it are different.

Input data:
The input is a natural three-digit number.

Output:
One should be output to the output file,
if all digits in a number are different, and zero otherwise.

Input data:
123

Output:
1                                       */

#include<iostream>
using namespace std;

int main() {
	int x;
	int x1;
	int x2;
	int x3;

	cin >> x;

	x1 = x % 10;
	x2 = (x % 100) / 10;
	x3 = x / 100;

	if (x1 == x2 || x2 == x3 || x3 == x1) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}