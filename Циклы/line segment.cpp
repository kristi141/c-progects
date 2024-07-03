/*RU
Условие:
Даны два отрезка таких, что длина первого больше длины второго.
Необходимо замостить первый отрезок вторым и вывести координаты, в которых 
располагаются концы меньшего отрезка.
Гарантируется, что больший отрезок можно замостить меньшим так, 
что суммарная длина меньших отрезков будет равна длине большего.

Входные данные:
Входной файл содержит три числа – координаты X1 и X2 концов первого отрезка 
(0 ≤ X1 < X2 ≤ 2*109) и длину L второго отрезка (1 ≤ L ≤ 104).

Выходные данные:
В выходной файл необходимо вывести через пробел все координаты числовой 
прямой, в которых будут располагаться концы меньших отрезков при замощении 
большего.

ENG
Condition:
Given two segments such that the length of the first is greater than the l
ength of the second. It is necessary to tile the first segment with the 
second and display the coordinates in which the ends of the smaller segment 
are located. It is guaranteed that a larger segment can be tiled with a 
smaller one so that that the total length of the smaller segments will be 
equal to the length of the larger one.

Input data:
The input file contains three numbers - coordinates X1 and X2 of the ends of 
the first segment
(0 ≤ X1 < X2 ≤ 2*109) and the length L of the second segment (1 ≤ L ≤ 104).

Output:
In the output file you must output all numeric coordinates separated by spaces.
straight line, in which the ends of smaller segments will be located when 
tiling more.*/

#include <iostream>
using namespace std;

int main() {
	int X1, X2, L;
	cin >> X1 >> X2 >> L;

	int distance = X2 - X1;
	int numSegments = distance / L;
	int remaining = distance % L;

	cout << X1 << " ";

	for (int i = 0; i < numSegments; i++) {
		X1 += L;
		cout << X1 << " ";
	}

	X1 += remaining;

	return 0;
}