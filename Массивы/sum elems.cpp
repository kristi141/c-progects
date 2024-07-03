/*RU
Условие:
Дан массив, состоящий из n элементов.
Необходимо посчитать и вывести сумму элементов с k по m.

Входные данные:
В первой строке входного файла дано три числа: n – количество элементов 
в массиве, k и m (1 ≤ k ≤ m ≤ n) – номера элементов.
Во второй строке входного файла дано n чисел – элементы массива.

Выходные данные:
В выходной файл необходимо вывести единственное значение - искомую сумму.

Входные данные:
1)
1 1 1
1

2)
5 2 3
1 2 3 4 5

Выходные данные:
1) 1
2) 5

ENG
Condition:
Given an array consisting of n elements.
It is necessary to calculate and display the sum of elements from k to m.

Input data:
The first line of the input file contains three numbers: n – number of elements
in the array, k and m (1 ≤ k ≤ m ≤ n) – numbers of elements.
The second line of the input file contains n numbers - array elements.

Output:
The only value that needs to be output to the output file is the 
required amount.

Input data:
1)
1 1 1
1

2)
5 2 3
1 2 3 4 5

Output:
1) 1
2) 5                                */

#include <iostream>
using namespace std;

int main()
{
	int n, k, m;
	int sum = 0;

	cin >> n;
	cin >> k >> m;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = k - 1; i <= m - 1; i++) {
		sum += arr[i];
	}

	cout << sum;

	return 0;
}