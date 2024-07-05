/*RU
Условие:
Дано два числа. Поменяйте их местами в процедуре.

Входные данные:
На вход даётся два числа. (2 3)

Выходные данные:
Выведите изменённые переменные. (3 2)

ENG
Condition:
Two numbers are given. Swap them in the procedure.

Input data:
Two numbers are given as input.

Output:
Print the changed variables.*/

#include <iostream>
using namespace std;

void swapNumbers(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a, b;

	cin >> a >> b;
	swapNumbers(a, b);
	cout << a << " " << b;

	return 0;
}