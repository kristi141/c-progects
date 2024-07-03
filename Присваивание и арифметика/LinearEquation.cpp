/*RU
Условие:
Даны два числа – коэффициенты уравнения ax + b = 0.
Необходимо решить данное уравнение.

Входные данные:
На вход даются два целых числа a и b - коэффициенты уравнения ax + b = 0.

Выходные данные:
В выходной файл должен быть выведен корень данного уравнения.
Если корней нет, выведите “NO SOLUTION”. 
Если корней бесконечно много, выведите “R”.

ENG
Condition:
Two numbers are given - the coefficients of the equation ax + b = 0.
This equation needs to be solved.

Input data:
The input is given two integers a and b - the coefficients of the equation ax + b = 0.

Output:
The root of this equation should be output to the output file.
If there are no roots, print “NO SOLUTION”.
If there are infinitely many roots, print “R”.*/

#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if ((a == 0) && (b != 0)){
		cout << "NO SOLUTION";
	}
	else if ((a == 0) && (b == 0)) {
		cout << "R";
	}
	else{
		cout << (-b) / a;
	}

	return 0;
}