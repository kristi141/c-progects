/*Условие:
Дан отсортированный целочисленный массив, содержащий повторяющиеся элементы 
и состоящий из n элементов.
Необходимо для каждого из m запросов найти, какое количество раз в данном 
массиве встречается заданное значение k.

Входные данные:
В первой строке входного файла дано значение n(1<=n<=100000) - 
количество элементов массива.
Во второй строке входного файла дан сам массив.
В третьей строке входного файла дано значение m(1<=m<=100000) – 
количество запросов.
В каждой из следующих m строк дано единственное число – значение k 
(для каждого запроса значение k может быть как различно, так и одинаково).

Выходные данные:
Для каждого запроса в выходной файл должно быть выведено единственное 
значение - количество вхождений числа k в массив, если элемента k в массиве 
нет, то необходимо вывести - «Not found».
Значение для каждого нового запроса должно быть выведено в отдельной строке.*/

#include <iostream>
using namespace std;

int main()
{
	long long size;
	cin >> size;
	long long* arr = new long long[size];
	long long key = 0;

	for (long long i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	long long request;
	cin >> request;

	for (long long i = 0; i < request; i++) {
		cin >> key;

		long long start = 0;
		long long end = size - 1;
		long long first = -1;
		while (start <= end) {
			long long mid = (start + end) / 2;
			if (arr[mid] == key) {
				first = mid;
				end = mid - 1;
			}
			else if (arr[mid] < key) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		start = 0;
		end = size - 1;
		long long last = -1;
		while (start <= end) {
			long long mid = (start + end) / 2;
			if (arr[mid] == key) {
				last = mid;
				start = mid + 1;
			}
			else if (arr[mid] < key) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		if (first != -1 && last != -1)
		{
			cout << (last - first + 1) << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}

	}
	delete[] arr;
	return 0;
}