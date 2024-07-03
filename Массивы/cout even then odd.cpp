/*RU
Условие:
Дан массив, состоящий из n элементов.
Необходимо вывести сначала чётные элементы массива, а затем нечётные, 
сохранив их порядок.

Входные данные:
В первой строке входного файла дано натуральное число n – 
количество элементов в массиве.
Во второй строке даны n целых чисел – элементы массива.

Выходные данные:
В выходной файл необходимо вывести чётные, а затем нечётные 
элементы массива.

ENG
Condition:
Given an array consisting of n elements.
It is necessary to display the even elements of the array first, and then 
the odd ones, keeping them in order.

Input data:
The first line of the input file contains a natural number n –
number of elements in the array.
The second line contains n integers – array elements.

Output:
It is necessary to output even and then odd ones to the output file.
array elements.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	std::cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			std::cout << arr[i] << " ";
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			std::cout << arr[i] << " ";
		}
	}

	return 0;
}