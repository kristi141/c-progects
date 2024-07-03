/*RU
Условие:
Постройте треугольник по стороне и двум прилегающим к ней углам.

Входные данные:
Программа получает на вход три действительных числа — длину стороны 
треугольника и величины двух углов между ними в градусах. Длина стороны — 
положительное число, не превосходящее 104 , углы — положительные числа, 
дающие в сумме меньше 180.

Выходные данные:
Выведите 6 действительных чисел — координаты вершин какого-нибудь 
треугольника соответствующего входным данным с точностью не менее 6 знаков 
после запятой.

ENG
Condition:
Construct a triangle using a side and two adjacent angles.

Input data:
The program receives three real numbers as input - the length of the side
triangle and the magnitude of the two angles between them in degrees. 
Side length - a positive number not exceeding 104, angles are positive numbers,
giving a total of less than 180.

Output:
Print 6 real numbers - the coordinates of the vertices of some
triangle corresponding to the input data with an accuracy of at least 6 digits
after the comma.*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926535;

struct Triangle {
private:
    double xA, yA, xB, yB, xC, yC;

public:
    void calculateVertices(double sideA, double cornerA, double cornerB) {
        double cornerC = 180 - cornerA - cornerB;

        double cornerDegreeToRadianA = cornerA / 180 * PI;
        double cornerDegreeToRadianB = cornerB / 180 * PI;
        double cornerDegreeToRadianC = cornerC / 180 * PI;

        double sideB = sideA * (sin(cornerDegreeToRadianA) / 
        sin(cornerDegreeToRadianC));
        double sideC = sideA * (sin(cornerDegreeToRadianB) / 
        sin(cornerDegreeToRadianC));

        xA = 0; yA = 0;
        xB = sideA; yB = 0;
        xC = sideC * cos(cornerDegreeToRadianB);
        yC = sideC * sin(cornerDegreeToRadianB);
    }

    void printVertices() {
        cout << fixed;
        cout.precision(10);
        cout << xA << ' ' << yA << endl << xB << ' ' << yB << endl 
        << xC << ' ' << yC;
    }
};

int main() {
    double sideA, cornerA, cornerB;
    cin >> sideA >> cornerA >> cornerB;

    Triangle triangular;
    triangular.calculateVertices(sideA, cornerA, cornerB);
    triangular.printVertices();

    return 0;
}