/*RU
Условие:
Дано натуральное число n.
Необходимо вывести все натуральные простые числа от 1 до n (включительно).

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 106).

Выходные данные:
В выходной файл необходимо вывести все простые числа от 1 до n через пробел 
в порядке возрастания.

Входные данные:
1) 12
2) 23

Выходные данные:
1)
2 3 5 7 11

2)
2 3 5 7 11 13 17 19 23

ENG
Condition:
Given a natural number n.
It is necessary to print all natural prime numbers from 1 to n (inclusive).

Input data:
The first line of the input file contains a natural number n (1 ≤ n ≤ 106).

Output:
All prime numbers from 1 to n must be output to the output file, separated 
by spaces.in ascending order.

Input data:
1) 12
2) 23

Output:
1)
2 3 5 7 11

2)
2 3 5 7 11 13 17 19 23*/

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