/*RU
Условие:
Даны два числа, одно из которых чётное, а второе нечётное.
Необходимо определить и вывести нечётное из них.

Входные данные:
На вход даются два натуральных числа.

Выходные данные:
В выходной файл должно быть выведено единственное значение - нечётное число.

ENG
Condition:
Given two numbers, one of which is even and the other is odd.
It is necessary to determine and derive the odd one from them.

Input data:
Two natural numbers are given as input.

Output:
The output file should contain a single value - an odd number.*/

#include<iostream>
using namespace std;

int main() {
	int e;
	int f;
	cin >> e;
	cin >> f;
	if (e % 2) {
		cout << e;
	}
	else {
		cout << f;
	}
}