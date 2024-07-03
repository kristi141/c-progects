/*RU
Условие:
Даны два числа. Необходимо вычислить НОД этих чисел, используя 
алгоритм Евклида.
Примечание: НОД – наибольший общий делитель двух чисел.

Входные данные:
На вход даются два натуральных числа a, b (a, b ≤ 109).

Выходные данные:
В входной файл необходимо вывести единственное значение - НОД данных чисел.

ENG
Condition:
Two numbers are given. It is necessary to calculate the gcd of these numbers 
using Euclidean algorithm.
Note: GCD is the greatest common divisor of two numbers.

Input data:
The input is given two natural numbers a, b (a, b ≤ 109).

Output:
The only value that needs to be output to the input file is the gcd of 
these numbers.*/

#include <iostream>
using namespace std;

int main()
{
	int a;
	int b;

	cin >> a >> b;

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	cout  << a;

	return 0;
}