/*RU
Условие:
Дано натуральное число n.
Необходимо вывести первые n простых чисел в порядке возрастания.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 106).

Выходные данные:
В выходной файл  необходимо вывести первые n простых чисел в 
порядке возрастания.

Входные данные:
5

Выходные данные:
2 3 5 7 11

ENG
Condition:
Given a natural number n.
You need to print the first n prime numbers in ascending order.

Input data:
The first line of the input file contains a natural number n (1 ≤ n ≤ 106).

Output:
The output file must contain the first n prime numbers in
ascending order.

Input data:
5

Output:
2 3 5 7 11                           */

#include <iostream>
using namespace std;

bool isPrime(int num) {
	if (num <= 1) {
		return false;
	}

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	int count = 0;
	int num = 2;

	
	while (count < n) {
		if (isPrime(num)) {
			cout << num << " ";
			count++;
		}
		num++;
	}
}