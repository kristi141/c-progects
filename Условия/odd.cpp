/*RU
Условие:
Даны два числа.
Необходимо определить является ли только одно из них нечётным.

Входные данные:
На вход даются два натуральных числа.

Выходные данные:
В выходной файл должна быть выведена единица,
если только одно из них нечётное, и ноль в остальных случаях.

Входные данные:
21 20

Выходные данные:
1

ENG
Condition:
Given two numbers, one of which is even and the other is odd.
It is necessary to determine and derive the odd one from them.

Input data:
Two natural numbers are given as input.

Output:
The output file should contain a single value - an odd number.

Input data:
21 20

Output:
1                                                   */

#include <iostream>
using namespace std;

int main() {
	int a;
	int p;
	int res;
	int res1;

	cin >> a;
	cin >> p;

	res = p % 2;
	res1 = a % 2;
	

	if (res == 0 && res1 != 0) {
		cout << 1;
	}
	else if (res1 == 0 && res != 0) {
		cout << 1;
	}
	else if (res == 0 && res1 == 0) {
		cout << 0;
	}
	else {
		cout << 0;
	}
}