/*RU
Условие:
Дан массив, состоящий из n элементов.
Необходимо вывести только чётные элементы данного массива, 
сохранив их порядок.

Входные данные:
Первая строка входного файла содержит единственное натуральное 
число n – количество элементов в массиве.
Во второй строке находятся идут n целых чисел – элементы массива.

Выходные данные:
В выходной файл необходимо вывести новую последовательность чисел, 
составленную только из чётных элементов заданного массива.

ENG
Condition:
Given an array consisting of n elements.
It is necessary to output only the even elements of the given array,
keeping them in order.

Input data:
The first line of the input file contains a single natural
number n – number of elements in the array.
The second line contains n integers - array elements.

Output:
You need to output a new sequence of numbers to the output file,
composed only of even elements of a given array.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			cout << arr[i] << " ";
		}
	}

	return 0;
}