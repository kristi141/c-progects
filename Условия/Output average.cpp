/*RU
Условие:
Даны три числа.
Необходимо найти и вывести среднее из них по величине.

Входные данные:
На вход даются три различных натуральных числа, по модулю не превышающих 10^6.

Выходные данные:
В выходной файл должно быть выведено единственное значение - 
среднее по величине число.

ENG
Condition:
Three numbers are given.
It is necessary to find and derive the average of them in magnitude.

Input data:
The input is given three different natural numbers, modulo not exceeding 10^6.

Output:
A single value should be output to the output file -
average number.*/

#include <iostream>
using namespace std;

int main() {
	int a;
	int q;
	int m;

	cin >> a;
	cin >> q;
	cin >> m;
	if (a > q && a < m || a < q && a > m ) {
		cout << a;
	}
	else if (q > a && q < m || q > m && q < a) {
		cout << q;
	}
	else {
		cout << m;
	}
}