/* Ru
Условие:
Дан отсортированный целочисленный массив, состоящий из n элементов.
Необходимо для каждого из m запросов реализовать бинарный поиск: 
выяснить за логарифмическое время -О(log(n)) существует ли заданное 
значение k в массиве.
Гарантируется, что в массиве нет дублирующихся элементов.

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
значение - номер элемента k в массиве или -1, если такого элемента в 
массиве нет.
Значение для каждого нового запроса должно быть выведено в отдельной строке.

Eng
Condition:
Given a sorted integer array consisting of n elements.
It is necessary to implement a binary search for each of the m queries:
find out in logarithmic time -O(log(n)) whether a given object exists
k value in the array.
It is guaranteed that there are no duplicate elements in the array.

Input data:
The first line of the input file contains the value n(1<=n<=100000) -
number of array elements.
The second line of the input file contains the array itself.
The third line of the input file gives the value m(1<=m<=100000) –
number of requests.
Each of the next m lines contains a single number - the value k
(for each request the value of k can be either different or the same).

Output:
For each request, the output file must contain a single
value is the number of element k in the array or -1 if there is such an element in
no array.
The value for each new request should be printed on a separate line.*/

#include <iostream>
using namespace std;

int main()
{
	int size;
	cin >> size;
	int* arr = new int[size];
	int key = 0;
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	int request;
	cin >> request;

	for (int i = 0; i < request; i++) {
		cin >> key;
		int left = 0, right = size - 1;
		int midd = 0;
		while (1)
		{
			midd = (left + right) / 2;

			if (key < arr[midd])
			{
				right = midd - 1;
			}
			else if (key > arr[midd]) {
				left = midd + 1;
			}				
			else
			{
				index = midd;
				break;
			}

			if (left > right)
			{
				index = -1;
				break;
			}
		}

		if (index >= 0)
			cout << index + 1 << " " << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}