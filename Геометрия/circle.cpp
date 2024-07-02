/*Условие:
Найдите координаты центра вписанной окружности данного треугольника.

Входные данные:
Программа получает на вход координаты трех вершин треугольника 
(сначала координаты первой вершины, затем второй, затем третьей). 
Координаты - пара целых чисел, не превосходящиx 104 по модулю.

Выходные данные:
Bыведите два числа - координаты центра вписанной окружности данного 
треугольника с точностью не меньше 6 знаков после запятой.*/

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

double triangleSide(const Points& firstPoint, const Points& secondPoint) {
    return sqrt(pow(firstPoint.x - secondPoint.x, 2) + pow(firstPoint.y - 
    secondPoint.y, 2));
}

void coordinatesCenterInscribedCircle(const Points& firstPoint,
const Points& secondPoint, const Points& thirdPoint, Points& center) {
    
    double firstSideOfTriangle = triangleSide(secondPoint,thirdPoint);
    double secondSideOfTriangle = triangleSide(firstPoint,thirdPoint);
    double thirdSideOfTriangle = triangleSide(firstPoint,secondPoint);

    center.x = (firstSideOfTriangle * firstPoint.x + secondSideOfTriangle *
    secondPoint.x + thirdSideOfTriangle * thirdPoint.x) / (firstSideOfTriangle +
    secondSideOfTriangle + thirdSideOfTriangle);
    
    center.y = (firstSideOfTriangle * firstPoint.y + secondSideOfTriangle *
    secondPoint.y + thirdSideOfTriangle * thirdPoint.y) /
    (firstSideOfTriangle + secondSideOfTriangle + thirdSideOfTriangle);
}

int main() {
    Triangle triangle;

    cin >> triangle.firstPoint.x >> triangle.firstPoint.y
    >> triangle.secondPoint.x >> triangle.secondPoint.y >> triangle.thirdPoint.x 
    >> triangle.thirdPoint.y;
    
    Points center;
    
    coordinatesCenterInscribedCircle(triangle.firstPoint, 
    triangle.secondPoint, triangle.thirdPoint, center);

    cout << fixed << setprecision(6) << center.x << " " << center.y << endl;

    return 0;
}