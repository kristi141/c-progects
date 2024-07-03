/*RU
Условие:
Дана последовательность чисел.
Необходимо отсортировать её в порядке неубывания.

Входные данные:
На вход даётся натуральное число n (n ≤ 1000) – количество чисел 
в последовательности, далее идут n целых чисел - элементы последовательности.

Выходные данные:
В выходной файл необходимо вывести отсортированную последовательность.

Входные данные:
1)
5 5 4 3 2 1

2)
1 1

Выходные данные:
1)
1 2 3 4 5

2) 1

ENG
Condition:
Given a sequence of numbers.
It is necessary to sort it in non-descending order.

Input data:
The input is a natural number n (n ≤ 1000) – the number of numbers
in the sequence, then there are n integers - the elements of the sequence.

Output:
The sorted sequence must be output to the output file.

Input data:
1)
5 5 4 3 2 1

2)
1 1

Output:
1)
1 2 3 4 5

2) 1                      */

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}