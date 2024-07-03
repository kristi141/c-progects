/*RU
Условие:
Даны два отсортированных в порядке неубывания массива.
Необходимо слить их в один отсортированный массив.

Входные данные:
В первой строке входного файла даны два натуральных числа n и m – 
размеры массивов.
Во второй строке входного файла даны n целых чисел – элементы первого массива.
В третьей строке входного файла даны m целых чисел – элементы второго массива.

Выходные данные:
В выходной файл необходимо вывести слитый отсортированный массив.

Входные данные:
1)
5 5
1 3 5 7 9
2 4 6 8 10

2)
1 2
2
1 3

Выходные данные:
1)
1 2 3 4 5 6 7 8 9 10

2)
1 2 3

ENG
Condition:
Given two arrays sorted in non-decreasing order.
It is necessary to merge them into one sorted array.

Input data:
The first line of the input file contains two natural numbers n and m –
array sizes.
The second line of the input file contains n integers - elements of the first array.
The third line of the input file contains m integers – elements of the second array.

Output:
The merged sorted array must be output to the output file.

Input data:
1)
5 5
1 3 5 7 9
2 4 6 8 10

2)
1 2
2
1 3

Output:
1)
1 2 3 4 5 6 7 8 9 10

2)
1 2 3                                                    */

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