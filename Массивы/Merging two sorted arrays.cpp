/*Условие:
Даны два отсортированных в порядке неубывания массива.
Необходимо слить их в один отсортированный массив.

Входные данные:
В первой строке входного файла даны два натуральных числа n и m – 
размеры массивов.
Во второй строке входного файла даны n целых чисел – элементы первого массива.
В третьей строке входного файла даны m целых чисел – элементы второго массива.

Выходные данные:
В выходной файл необходимо вывести слитый отсортированный массив.*/

#include <iostream>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int* arr1 = new int[n];
	int* arr2 = new int[m];
	int* sortArr = new int[n + m];
	int i = 0, j = 0, k = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	while (i < n && j < m) {
		if (arr1[i] <= arr2[j]) {
			sortArr[k] = arr1[i];
			i++;
		}
		else {
			sortArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < n) {
		sortArr[k] = arr1[i];
		i++;
		k++;
	}

	while (j < m) {
		sortArr[k] = arr2[j];
		j++;
		k++;
	}

	for (int i = 0; i < n + m; i++) {
		cout << sortArr[i] << " ";
	}

	return 0;
}