/*RU
Условие:
Даны окружность и точка.
Необходимо определить лежит ли точка на данной окружности.

Входные данные:
На вход даны пять целых чисел чисел – координаты центра окружности,
радиус и координаты точки.
Все координаты даны в декартовой системе координат (x; y).
Все числа по модулю не превышают 1000.

Выходные данные:
В выходной файл должна быть выведена единица,
 если точка лежит на окружности, и ноль в противном случае.
 
 ENG
 Condition:
Given a circle and a point.
It is necessary to determine whether a point lies on a given circle.

Input data:
The input is given five integers of numbers - the coordinates of the center 
of the circle,radius and coordinates of the point.
All coordinates are given in the Cartesian coordinate system (x; y).
All numbers modulo do not exceed 1000.

Output:
One should be output to the output file,
if the point lies on the circle, and zero otherwise.*/

 #include <iostream>
using namespace std;

int main() {	
	int x0;
	int y0;
	int r;
	int x;
	int y;
	
	cin >> x0 >> y0 >> r >> x >> y ;

	if (((x - x0) * (x - x0) + (y - y0) * (y - y0)) == (r * r)) 
		cout << "1";
	else 
		cout << "0";
return 0;
	
}