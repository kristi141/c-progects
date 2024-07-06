/*RU
Условие:
Даны два числа.
Необходимо найти и вывести частное и остаток от деления первого числа 
на второе, без использования оператора деления.

Входные данные:
На вход даются два натуральных числа.

Выходные данные:
В выходной файл необходимо вывести через пробел два числа - 
частное от деления первого на второе, а затем остаток.

Входные данные:
4 2

Выходные данные:
2 0

ENG
Condition:
Two numbers are given.
It is necessary to find and display the quotient and remainder of the 
division of the first numberto the second, without using the division operator.

Input data:
Two natural numbers are given as input.

Output:
You need to output two numbers separated by spaces into the output file -
the quotient of the first divided by the second, and then the remainder.

Input data:
4 2

Output:
2 0                                                    */

#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = 0;
	int d = 0;

	while (a >= b) {
		a -= b;
		c++;
	}

	d = a;

	cout << c << " " << d;

	return 0;
}