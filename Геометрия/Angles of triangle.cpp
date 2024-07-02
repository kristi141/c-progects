/*Условие:
Дан треугольник. Определите величину самого большого из его углов.

Входные данные:
Программа получает на вход координаты трех вершин треугольника 
(сначала координаты первой вершины, затем второй, затем третьей). 
Координаты - пара целых чисел, не превосходящих 10^4 по модулю.

Выходные данные:
Выведите единственное число - величину самого большого угла треугольника 
в градусах с точностью не меньше 6 знаков после запятой*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Points {
    double x;
    double y;
};

struct Triangle {
    Points firstPoint;
    Points secondPoint;
    Points thirdPoint;
};

double angle(Points firstPoint, Points secondPoint, Points thirdPoint) {
    double a = sqrt((secondPoint.x - firstPoint.x) *
        (secondPoint.x - firstPoint.x) + (secondPoint.y - firstPoint.y) *
        (secondPoint.y - firstPoint.y));

    double b = sqrt((secondPoint.x - thirdPoint.x) *
        (secondPoint.x - thirdPoint.x) + (secondPoint.y - thirdPoint.y) *
        (secondPoint.y - thirdPoint.y));

    double c = sqrt((thirdPoint.x - firstPoint.x) *
        (thirdPoint.x - firstPoint.x) + (thirdPoint.y - firstPoint.y) *
        (thirdPoint.y - firstPoint.y));

    double firstAngle = acos((b * b + c * c - a * a) / (2 * b * c));
    double secondAngle = acos((a * a + b * b - c * c) / (2 * a * b));
    double thirdAngle = acos((a * a + c * c - b * b) / (2 * a * c));

    return max(firstAngle, max(secondAngle, thirdAngle)) * 180 / M_PI;
}

int main() {
    Triangle triangle;
    cin >> triangle.firstPoint.x >> triangle.firstPoint.y
        >> triangle.secondPoint.x >> triangle.secondPoint.y
        >> triangle.thirdPoint.x >> triangle.thirdPoint.y;

    double maxAngle = angle(triangle.firstPoint, triangle.secondPoint,
        triangle.thirdPoint);

    cout << fixed << setprecision(6) << maxAngle << endl;

    return 0;
}