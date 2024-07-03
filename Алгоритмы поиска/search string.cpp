/*Ru
Условие:
Дан отсортированный в лексикографическом порядке массив, состоящий из n слов.
Необходимо для каждого из m запросов выяснить входит ли заданное слово в 
данный массив.

Входные данные:
В первой строке входного файла дано значение n(1<=n<=100000) - 
количество элементов массива.
Во второй строке входного файла дан сам массив.
В третьей строке входного файла дано значение m(1<=m<=100000) – 
количество запросов.
В каждой из следующих m строк задано слово (для каждого запроса слова 
могут быть как различны, так и одинаковы).

Выходные данные:
Для каждого запроса в выходной файл должно быть выведено единственное 
значение - номер слова в массиве или -1, если такого слова нет.
Значение для каждого нового запроса должно быть выведено в отдельной строке.

Eng
Condition:
Given an array sorted in lexicographic order, consisting of n words.
For each of the m queries, it is necessary to find out whether the given word is included in
given array.

Input data:
The first line of the input file contains the value n(1<=n<=100000) -
number of array elements.
The second line of the input file contains the array itself.
The third line of the input file gives the value m(1<=m<=100000) –
number of requests.
Each of the next m lines contains a word (for each word request
may be different or the same).

Output:
For each request, the output file must contain a single
value is the number of the word in the array or -1 if there is no such word.
The value for each new request should be printed on a separate line.*/

#include <iostream>
using namespace std;

int main()
{
	int size;
	cin >> size;
	string* arr = new string[size];
	string key;
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