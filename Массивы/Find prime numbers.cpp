/*Условие:
Дано натуральное число n.
Необходимо вывести все натуральные простые числа от 1 до n (включительно).

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 106).

Выходные данные:
В выходной файл необходимо вывести все простые числа от 1 до n через пробел 
в порядке возрастания.*/

#include <iostream>
using namespace std;

bool prime(int num) {
	if (num < 2) {
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
	std::cin >> n;

	for (int i = 2; i <= n; i++) {
		if (prime(i)) {
			std::cout << i << " ";
		}
	}

	return 0;
}