/*RU
Условие:
Даны два числа. 
Вам необходимо считать их значения в переменные,
а затем поменять значения этих перменных местами,
без использования третьей переменной.

Входные данные:
На вход даются два целых числа.

Выходные данные:
В выходной файл выведите измененные значения переменных.

ENG
Condition:
Two numbers are given.
You need to read their values ​​into variables,
and then swap the values ​​of these variables,
without using a third variable.

Input data:
Two integers are given as input.

Output:
Output the changed variable values ​​to the output file.*/

#include<iostream>
using namespace std;

int main() {
	int a;
	int s;
	cin >> a;
	cin >> s;

	a = a + s;
	s = s - a;
	s = -s;
	a = a - s;
	cout << a << " ";
	cout << s;
}