/*Ru
Условие:
Дан отсортированный целочисленный массив, состоящий из n элементов.
Необходимо для каждого из m запросов найти номер первого и последнего 
вхождения заданного элемента k в данный массив.

Входные данные:
В первой строке входного файла дано значение n(1<=n<=100000) - 
количество элементов массива.
Во второй строке входного файла дан сам массив.
В третьей строке входного файла дано значение m(1<=m<=100000) – 
количество запросов.
В каждой из следующих m строк дано единственное число – значение k 
(для каждого запроса значение k может быть как различно, так и одинаково).

Выходные данные:
Для каждого запроса в выходной файл должно быть выведено два значения – 
номер первого вхождения и номер последнего вхождения элемента k в массив 
или «Not found», если такого элемента в массиве нет.
Значение для каждого нового запроса должно быть выведено в отдельной строке.

Eng
Condition:
Given a sorted integer array consisting of n elements.
For each of m queries, it is necessary to find the number of the first and last
occurrence of a given element k in a given array.

Input data:
The first line of the input file contains the value n(1<=n<=100000) -
number of array elements.
The second line of the input file contains the array itself.
The third line of the input file gives the value m(1<=m<=100000) –
number of requests.
Each of the next m lines contains a single number - the value k
(for each request the value of k can be either different or the same).

Output:
For each request, two values ​​should be output to the output file −
number of the first occurrence and number of the last occurrence of element k in the array
or “Not found” if there is no such element in the array.
The value for each new request should be printed on a separate line.*/

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

		long long start = 0, end = size - 1;
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

		start = 0, end = size - 1;
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
			cout << first + 1 << " " << last + 1 << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	}
	return 0;
}