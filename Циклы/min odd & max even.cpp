/*RU
Условие:
Дана последовательность чисел.
Необходимо найти и вывести минимальный нечётный и максимальный чётный 
элементы данной последовательности.

Входные данные:
Первая строка входного файла содержит единственное число n – 
количество элементов последовательности.
Во второй строке находятся n целых чисел ai – элементы последовательности.

Выходные данные:
В выходной файл необходимо вывести два числа – минимальный нечётный и 
максимальный чётный элементы последовательности.
Если какого-то из этих элементов не существует в данной последовательности, 
выведите "-1" вместо этого элемента.

ENG
Condition:
Given a sequence of numbers.
It is necessary to find and display the minimum odd and maximum even
elements of this sequence.

Input data:
The first line of the input file contains a single number n –
number of sequence elements.
The second line contains n integers ai – elements of the sequence.

Output:
You need to output two numbers to the output file: the minimum odd number and
maximum even elements of the sequence.
If any of these elements does not exist in this sequence,
print "-1" instead of this element.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
    cin >> n;

	int min = -1; 
	int max = -1; 

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num % 2 == 0) { 
			if (max == -1 || num > max) {
				max = num;
			}
		}
		else {
			if (min == -1 || num < min) {
				min = num;
			}
		}
	}

	std::cout << min << " ";
	std::cout << max;

	return 0;
}