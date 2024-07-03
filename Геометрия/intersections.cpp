/*RU
Условие:
Найдите точку пересечения высот данного треугольника

Входные данные:
Программа получает на вход координаты трех вершин треугольника 
(сначала координаты первой вершины, затем второй, затем третьей). 
Координаты — пара целых чисел, не превосходящих 104 по модулю.

Выходные данные:
Выведите два числа — координаты точки пересечения высот данного треугольника 
с точностью не меньше 6 знаков после запятой

ENG
Condition:
Find the point of intersection of the altitudes of a given triangle

Input data:
The program receives as input the coordinates of the three vertices of a triangle
(first the coordinates of the first vertex, then the second, then the third).
Coordinates are a pair of integers not exceeding 104 in modulo.

Output:
Print two numbers - the coordinates of the point of intersection of the 
heights of this triangle with an accuracy of at least 6 decimal places*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Points {
    double x;
    double y;
};

void kramer(double a1, double b1, double c1, double a2, double b2, double c2,
    Points& value) {
    double d = a1 * b2 - a2 * b1;
    double dx = c1 * b2 - c2 * b1;
    double dy = a1 * c2 - a2 * c1;
    value.x = dx / d;
    value.y = dy / d;
}

void heighstIntersection(Points firstVertex, Points secondVertex,
    Points thirdVertex) {
    double a1 = thirdVertex.x - secondVertex.x;
    double b1 = thirdVertex.y - secondVertex.y;
    double c1 = firstVertex.x * (thirdVertex.x - secondVertex.x) +
        firstVertex.y * (thirdVertex.y - secondVertex.y);

    double a2 = thirdVertex.x - firstVertex.x;
    double b2 = thirdVertex.y - firstVertex.y;
    double c2 = secondVertex.x * (thirdVertex.x - firstVertex.x) +
        secondVertex.y * (thirdVertex.y - firstVertex.y);

    Points intersection;

    kramer(a1, b1, c1, a2, b2, c2, intersection);

    cout << fixed << setprecision(6) << intersection.x << " "
        << intersection.y << endl;
}

int main() {
    Points firstVertex, secondVertex, thirdVertex;

    cin >> firstVertex.x >> firstVertex.y >> secondVertex.x >> secondVertex.y
        >> thirdVertex.x >> thirdVertex.y;

    heighstIntersection(firstVertex, secondVertex, thirdVertex);

    return 0;
}
