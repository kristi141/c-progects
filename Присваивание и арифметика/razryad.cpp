/*RU
Условие:
Дано трёхзначное число.

Входные данные:
На вход дается натуральное трёхзначное число. (123)

Выходные данные:
В выходной файл через пробел должны быть выведены разряды этого числа.(1 2 3)

ENG
Condition:
A three-digit number is given.

Input data:
The input is a natural three-digit number.

Output:
The digits of this number must be displayed in the output file, separated 
by spaces.*/

#include <iostream>
using namespace std;

int main() {
	int x = 0;
	int a;
	int b;
	int c;

	cin >> x;
	a = x / 100;
	b = (x % 100) / 10;
	c = x % 10;
	cout << a << " " << b << " " << c;
}