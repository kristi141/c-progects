/*Условие:
Даны два целых числа a и b. Напишите процедуру, которая выведет их сумму.

Входные данные:
В первой строке записаны числа a и b (-109 ≤ a,b≤109 ).

Выходные данные:
Выведите a+b.*/

#include <iostream>
using namespace std;

void sum(int a, int b) {
		int result = a + b;
		cout << result;
	}

int main() {
		int a, b;
		cin >> a >> b;

		sum(a, b);

		return 0;
}