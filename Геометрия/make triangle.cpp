/*RU
Условие:
Постройте треугольник по двум сторонам и углу между ними.

Входные данные:
Программа получает на вход три действительных числа — длины двух сторон 
треугольника и величину угла между ними в градусах. Длины сторон — 
положительные числа, не превосходящие 104 , угол — положительное число 
меньшее 180.

Выходные данные:
Выведите 6 действительных чисел — координаты вершин какого-нибудь 
треугольника соответствующего входным данным с точностью не менее 6 
знаков после запятой.

Входные данные:
10 5 60

Выходные данные:
0.000000 0.000000
10.000000 0.000000
2.5000000000 4.3301270189

ENG
Condition:
Construct a triangle using two sides and the angle between them.

Input data:
The program receives three real numbers as input - the lengths of two sides
triangle and the size of the angle between them in degrees. Side lengths -
positive numbers not exceeding 104, angle is a positive number
less than 180.

Output:
Print 6 real numbers - the coordinates of the vertices of some
triangle corresponding to the input data with an accuracy of at least 6
decimal places.

Input data:
10 5 60

Output:
0.000000 0.000000
10.000000 0.000000
2.5000000000 4.3301270189       */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    double x;
    double y;
};

Point kramer(double a1, double b1, double c1, double a2, double b2, double c2) {
    Point res;
    double d = a1 * b2 - a2 * b1;
    double dx = c1 * b2 - c2 * b1;
    double dy = a1 * c2 - a2 * c1;

    res.x = dx / d;
    res.y = dy / d;

    return res;
}

void print(double sideLength1, double sideLength2, double degree) {
    degree = degree / 180 * M_PI;

    cout << "0.000000 0.000000" << endl;
    cout << fixed << setprecision(6) << sideLength1 << " " << "0.000000" << endl;

    Point coordinate = kramer(cos(degree), sin(degree), sideLength2, sin(degree), -cos(degree), 0);
    cout << fixed << setprecision(10) << coordinate.x << " " << coordinate.y << endl;
}

int main() {
    double sideLength1, sideLength2, degree;
    cin >> sideLength1 >> sideLength2 >> degree;

    print(sideLength1, sideLength2, degree);

    return 0;
}