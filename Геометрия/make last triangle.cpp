/*RU
Условие:
Постройте треугольник по трем сторонам.

Входные данные:
Программа получает на вход три действительных числа — длины сторон 
треугольника. Длина сторон — положительные числа, не превосходящие 104 , 
удовлетворяющие неравенству треугольника.

Выходные данные:
Выведите 6 действительных чисел — координаты вершин какого-нибудь 
треугольника соответствующего входным данным с точностью не менее 6 знаков 
после запятой.

ENG
Condition:
Construct a triangle with three sides.

Input data:
The program receives three real numbers as input - the lengths of the sides
triangle. Side lengths are positive numbers not exceeding 104,
satisfying the triangle inequality.

Output:
Print 6 real numbers - the coordinates of the vertices of some
triangle corresponding to the input data with an accuracy of at least 
6 digits after the comma.*/

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