/*Условие:
Постройте треугольник по трем сторонам.

Входные данные:
Программа получает на вход три действительных числа — длины сторон 
треугольника. Длина сторон — положительные числа, не превосходящие 104 , 
удовлетворяющие неравенству треугольника.

Выходные данные:
Выведите 6 действительных чисел — координаты вершин какого-нибудь 
треугольника соответствующего входным данным с точностью не менее 6 знаков 
после запятой.*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Points {
    double x;
    double y;
};

struct Triangle {
    double firstSide;
    double secondSide;
    double thirdSide;
};

double findFirstCorner(const Triangle& triangle) {
    double cosA = (triangle.firstSide * triangle.firstSide + triangle.secondSide * triangle.secondSide
        - triangle.thirdSide * triangle.thirdSide) / (2 * triangle.firstSide * triangle.secondSide);

    return acos(cosA);
}

int main() {
    Triangle triangle;
    cin >> triangle.firstSide >> triangle.secondSide >> triangle.thirdSide;

    Points firstPoint = { 0.0, 0.0 };
    Points secondPoint = { triangle.firstSide, 0.0 };

    double firstCorner = findFirstCorner(triangle);

    Points thirdPoint = {
        cos(firstCorner) * triangle.secondSide,
        sin(firstCorner) * triangle.secondSide
    };

    cout << fixed << setprecision(6) << firstPoint.x << " " << firstPoint.y << endl;
    cout << fixed << setprecision(6) << secondPoint.x << " " << secondPoint.y << endl;
    cout << fixed << setprecision(6) << thirdPoint.x << " " << thirdPoint.y << endl;

    return 0;
}