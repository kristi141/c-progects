/*Условие:
Дано натуральное число n.
Необходимо вывести первые n простых чисел в порядке возрастания.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 106).

Выходные данные:
В выходной файл  необходимо вывести первые n простых чисел в 
порядке возрастания.*/

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