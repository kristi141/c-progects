/*RU
Условие:
Постройте квадрат по двум точкам — соседним вершинам квадрата.

Входные данные:
Программа получает на вход координаты двух соседних вершин квадрата 
(сначала координаты первой вершины, затем второй). 
Координаты — пара целых чисел, не превосходящих 104 по абсолютной величине.

Выходные данные:
Выведите 4 числа — координаты двух оставшихся вершин квадрата.

Входные данные:
1 1
2 4

Выходные данные:
-1 5 -2 2

ENG
Condition:
Construct a square using two points - adjacent vertices of the square.

Input data:
The program receives as input the coordinates of two adjacent vertices of a square
(first the coordinates of the first vertex, then the second).
Coordinates are a pair of integers not exceeding 104 in absolute value.

Output:
Print 4 numbers — the coordinates of the two remaining vertices of the square.

Input data:
1 1
2 4

Output:
-1 5 -2 2             */

#include <iostream>
#include <cmath>
using namespace std;

struct Points {
    double x;
    double y;
};

struct Square {
    Points firstVertexOfSquare;
    Points secondVertexOfSquare;
};

Points distanceBetweenTwoVertex(Points firstVertexOfSquare, 
Points secondVertexOfSquare) {
    double side = abs(firstVertexOfSquare.x - secondVertexOfSquare.x);

    Points firstNeighboringVertexOfSquare = { secondVertexOfSquare.x +
    (firstVertexOfSquare.y - secondVertexOfSquare.y), secondVertexOfSquare.y +
    (secondVertexOfSquare.x - firstVertexOfSquare.x) };
    
    Points secondNeighboringVertexOfSquare = { firstVertexOfSquare.x + 
    (firstVertexOfSquare.y - secondVertexOfSquare.y), firstVertexOfSquare.y + 
    (secondVertexOfSquare.x - firstVertexOfSquare.x) };

    cout << firstNeighboringVertexOfSquare.x << " "
    << firstNeighboringVertexOfSquare.y << " " 
    << secondNeighboringVertexOfSquare.x << " " 
    << secondNeighboringVertexOfSquare.y << endl;

    return firstNeighboringVertexOfSquare;
}

int main() {
    Points side1, side2;

    cin >> side1.x >> side1.y >> side2.x >> side2.y;
    distanceBetweenTwoVertex(side1, side2);

    return 0;
}

