/*RU
Условие:
Дан массив, состоящий из n элементов.
Необходимо отсортировать его “Пузырьком” в порядке неубывания и 
вывести отсортированный массив.

Входные данные:
На вход дается значение n - количество элементов в массиве, а затем 
n чисел – элементы массива.

Выходные данные:
В выходной файл необходимо вывести отсортированный массив.

ENG
Condition:
Given an array consisting of n elements.
It is necessary to sort it with a “Bubble” in non-descending order and
output the sorted array.

Input data:
The input is given the value n - the number of elements in the array, and then
n numbers are array elements.

Output:
The sorted array must be output to the output file.*/

#include <iostream>
using namespace std;

int main() {
	int arr[10000];
	int i, j, n, temp;
	cin >> n;

	for (i = 0; i < n; i++)
		cin >> arr[i];

	for (j = 0; j < n - 1; j++) {
		for (i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
	}

	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}