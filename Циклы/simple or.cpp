/*Условие:
Дано натуральное число n.
Необходимо определить, является ли оно простым.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 109).

Выходные данные:

В выходной файл необходимо вывести «Yes», если число n является простым, 
и «No» в противном случае.*/

#include<iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	if (isPrime(n))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}