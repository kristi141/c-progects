/*RU
Условие:
Дана последовательность чисел.
Необходимо вычислить сумму чётных элементов данной последовательности.

Входные данные:
На вход даются натуральное число n – количество элементов 
последовательности, а затем n натуральных чисел – элементы последовательности.

Выходные данные:
В выходной файл необходимо вывести единственное значение - 
сумму чётных элементов данной последовательности.

Входные данные:
5 1 2 3 4 5

1 1

Выходные данные:
6

0

ENG
Condition:
Given a sequence of numbers.
It is necessary to calculate the sum of the even elements of a given sequence.

Input data:
The input is a natural number n – the number of elements
sequence, and then n natural numbers - elements of the sequence.

Output:
The only value you need to output to the output file is -
the sum of the even elements of a given sequence.

Input data:
5 1 2 3 4 5

1 1

Output:
6

0               */

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num % 2 == 0) {
			sum += num;
			count++;
		}
	}

	if (count == 0) {
		sum = 0;
	}

	cout << sum;

	return 0;
}