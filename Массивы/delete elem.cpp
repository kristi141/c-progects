/*RU
Условие:
Дан массив, состоящий из n элементов, и значение k.
Необходимо удалить элемент с номером k из данного массива, 
сместив последующие элементы.

Входные данные:
В первой строке входного файла даётся натуральное число n – 
количество элементов в массиве.
Во второй строке находятся n чисел – элементы массива.
В третьей строке входного файла дано целое чисто k -  номер удаляемого 
элемента (1 ≤ k ≤ n).

Выходные данные:
В выходной файл необходимо вывести измененный массив.

Входные данные:
1)
5
1 5 2 5 3
3

2)
1
1
1

Выходные данные:
1)
1 5 5 3

2)          (nothing)

ENG
Condition:
Given an array of n elements and a value k.
It is necessary to remove element number k from the given array,
shifting subsequent elements.

Input data:
The first line of the input file contains the natural number n –
number of elements in the array.
The second line contains n numbers - elements of the array.
The third line of the input file contains a pure integer k - the number of the file to be deleted
element (1 ≤ k ≤ n).

Output:
The modified array must be output to the output file.

Input data:
1)
5
1 5 2 5 3
3

2)
1
1
1

Output:
1)
1 5 5 3

2)          (nothing)                               */

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

	int k;
	cin >> k;

	for (int i = k - 1; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}

	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}