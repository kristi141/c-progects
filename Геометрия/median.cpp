/*Условие:
Найдите точку пересечения медиан данного треугольника..

Входные данные:
Программа получает на вход координаты трех вершин треугольника 
(сначала координаты первой вершины, затем второй, затем третьей). 
Координаты - пара целых чисел, не превосходящиx 104 по модулю.

Выходные данные:
Bыведите два числа - координаты точки пересечения медиан данного треугольника 
с точностью не меньше 6 знаков после запятой.*/

#include <iostream>
#include <iomanip>
using namespace std;

struct Points {
    double x;
    double y;
};

struct Median {
    Points point1;
    Points point2;
    Points point3;
};

Points medianIntersection(Points point1, Points point2, Points point3) {
    double intersection1 = (point1.x + point2.x + point3.x) / 3;
    double intersection2 = (point1.y + point2.y + point3.y) / 3;

    Points result;
    result.x = intersection1;
    result.y = intersection2;

    return result;
}

int main() {
    Median median;
    cin >> median.point1.x >> median.point1.y >> median.point2.x 
    >> median.point2.y >> median.point3.x >> median.point3.y;

    Points intersection = medianIntersection(median.point1, median.point2, 
    median.point3);

    cout << fixed << setprecision(6) << intersection.x << " "
    << intersection.y << endl;

    return 0;
}