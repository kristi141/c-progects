/*RU
Условие:
Дана последовательность целых чисел. Необходимо определить, 
является ли она арифметической прогрессией.

Входные данные:
На вход даётся натуральное число n – количество чисел в последовательности. 
Далее идут n целых чисел – элементы последовательности.

Выходные данные:
В выходной файл необходимо вывести "1", если последовательность 
является арифметической прогрессией, и "0", если нет.

Входные данные:
5 1 2 3 4 5

3 1 2 5

Выходные данные:
1

0

ENG
Condition:
Given a sequence of integers. It is necessary to determine
Is it an arithmetic progression?

Input data:
The input is a natural number n – the number of numbers in the sequence.
Next come n integers - elements of the sequence.

Output:
It is necessary to output "1" to the output file if the sequence
is an arithmetic progression, and "0" if not.

Input data:
5 1 2 3 4 5

3 1 2 5

Output:
1

0                                                          */

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* seq = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	int difference = seq[1] - seq[0];

	for (int i = 2; i < n; i++) {
		if (seq[i] - seq[i - 1] != difference) {
			cout << "0";
			delete[] seq;
			return 0;
		}
	}

	cout << "1";

	return 0;
}