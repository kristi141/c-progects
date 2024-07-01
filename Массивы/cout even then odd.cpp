/*Условие:
Дан массив, состоящий из n элементов.
Необходимо вывести сначала чётные элементы массива, а затем нечётные, 
сохранив их порядок.

Входные данные:
В первой строке входного файла дано натуральное число n – 
количество элементов в массиве.
Во второй строке даны n целых чисел – элементы массива.

Выходные данные:
В выходной файл необходимо вывести чётные, а затем нечётные 
элементы массива.*/

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