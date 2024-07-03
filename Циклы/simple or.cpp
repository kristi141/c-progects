/*RU
Условие:
Дано натуральное число n.
Необходимо определить, является ли оно простым.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 109).

Выходные данные:

В выходной файл необходимо вывести «Yes», если число n является простым, 
и «No» в противном случае.

ENG
Condition:
Given a natural number n.
It is necessary to determine whether it is simple.

Input data:
The first line of the input file contains the natural number n (1 ≤ n ≤ 109).

Output:

“Yes” should be output to the output file if the number n is prime,
and "No" otherwise.*/

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