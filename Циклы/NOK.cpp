/*RU
Условие:
Даны два натуральных числа a и b.
Необходимо найти и вывести их наименьшее общее кратное.
Примечание : наименьшее общее кратное двух чисел – наименьшее число, 
делящееся на каждое из этих чисел.

Входные данные:
В первой строке входного файла даны два натуральных числа a и b 
(1 ≤ a,b ≤ 10^8).

Выходные данные:
В выходной файл необходимо вывести единственное значение - 
наименьшее общее кратное чисел a и b.

ENG
Condition:
Given two natural numbers a and b.
It is necessary to find and display their least common multiple.
Note: The least common multiple of two numbers is the smallest number
divisible by each of these numbers.

Input data:
The first line of the input file contains two natural numbers a and b
(1 ≤ a,b ≤ 10^8).

Output:
The only value you need to output to the output file is -
the least common multiple of a and b.*/

#include <iostream>
using namespace std;

int main() {
	long a, b, hcf, temp, res;
	cin >> a >> b;

	hcf = a;
	temp = b;

	while (hcf != temp) {
		if (hcf > temp)
			hcf -= temp;
		else temp -= hcf;
	}
	res = (a * b) / hcf;
	cout << res;
	return 0;
}