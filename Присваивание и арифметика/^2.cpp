/*RU
Условие:
Дано число.
Необходимо найти квадрат данного числа.

Входные данные:
На вход дается само число.

Выходные данные:
В выходной файл должно быть выведено единственное значение – 
квадрат данного числа. (5)

ENG
Condition:
A number is given.
You need to find the square of a given number.(25)

Input data:
The number itself is given as input.

Output:
The output file should contain a single value -
square of a given number.*/

#include <iostream>
using namespace std;

int main() {
	int a;
	int square;

	cin >> a;
	square = a * a;
	cout << square ;
}