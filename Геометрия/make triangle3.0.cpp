/*RU
Условие:
Постройте треугольник по двум углам и медиане, проведенной из третьего угла.

Входные данные:
Программа получает на вход три действительных числа — длину медианы и 
градусные меры двух углов. Длина медианы — положительное число, не 
превосходящее 104, углы — положительные числа, в сумме меньшие 180.

Выходные данные:
Выведите 6 действительных чисел — координаты вершин какого-нибудь 
треугольника соответствующего входным данным с точностью не менее 6 знаков 
после запятой.

ENG
Condition:
Construct a triangle using two angles and a median drawn from the third angle.

Input data:
The program receives three real numbers as input: the length of the median and
degree measures of two angles. The length of the median is a positive number, not
exceeding 104, the angles are positive numbers, the sum of which is less than 180.

Output:
Print 6 real numbers - the coordinates of the vertices of some
triangle corresponding to the input data with an accuracy of at least 6 digits
after the comma.*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double Pi = 3.1415926535;

double findThirdCorner(double firstCorner, double secondCorner) {

    return 180 - firstCorner - secondCorner;
}

double findSecondSide(double cornerCAB, double cornerACB, double cornerCBA,
double meddian) {

    double AC = 2 * meddian / sqrt(sin(cornerCAB * Pi / 180) * 
    sin(cornerCAB * Pi / 180) /
        (sin(cornerCBA * Pi / 180) * sin(cornerCBA * Pi / 180)) + 1
        + 2 * sin(cornerCAB * Pi / 180) * cos(cornerACB * Pi / 180) / 
        sin(cornerCBA * Pi / 180));

    return AC;
}

double findFirstSide(double secondSide, double cornerACB, double cornerCBA) {

    double AB = secondSide * sin(cornerACB * Pi / 180) / 
    sin(cornerCBA * Pi / 180);

    return AB;
}

int main() {

    double meddian, firstCorner, secondCorner;

    cin >> meddian;
    cin >> firstCorner >> secondCorner;

    double y, x;
    double thirdCorner = findThirdCorner(firstCorner, secondCorner);
    double secondSide = findSecondSide(firstCorner, thirdCorner,
    secondCorner, meddian);
    double firstSide = findFirstSide(secondSide, thirdCorner, secondCorner);

    cout << "0.000000 0.000000" << endl;;
    cout << fixed << setprecision(6) << firstSide << " ";
    cout << "0.000000" << endl;

    x = cos(firstCorner * Pi / 180) * secondSide;
    y = sin(firstCorner * Pi / 180) * secondSide;
    cout << fixed << setprecision(10) << x << " ";
    cout << fixed << setprecision(10) << y << " ";

    return 0;
}