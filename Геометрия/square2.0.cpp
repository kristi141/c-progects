/*Условие:
Постройте квадрат по двум точкам – противоположным вершинам квадрата.

Входные данные:
Программа получает на вход координаты двух противоположных вершин квадрата 
(сначала координаты первой вершины, затем второй). 
Координаты — пара целых чисел, не превосходящих 104 по абсолютной величине.

Выходные данные:
Выведите 4 числа — координаты двух оставшихся вершин квадрата.*/

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
    Points thirdVertexOfSquare;
    Points fourthVertexOfSquare;
};

void distanceBetweenTwoVertex(Square square) {
  
   double middle1 = (square.firstVertexOfSquare.x + 
   square.secondVertexOfSquare.x) / 2;
  double middle2 = (square.firstVertexOfSquare.y + 
  square.secondVertexOfSquare.y) / 2;
  
  double differencex = abs(square.firstVertexOfSquare.x - middle1);
  double differencey = abs(square.firstVertexOfSquare.y - middle2);

  if ((square.firstVertexOfSquare.y > square.secondVertexOfSquare.y &&
  square.firstVertexOfSquare.x < square.secondVertexOfSquare.x) || 
  (square.firstVertexOfSquare.y < square.secondVertexOfSquare.y && 
  square.firstVertexOfSquare.x > square.secondVertexOfSquare.x)) {
square.thirdVertexOfSquare.x = middle1 + differencey;
square.thirdVertexOfSquare.y = middle2 + differencex;

square.fourthVertexOfSquare.x = middle1 - differencey;
square.fourthVertexOfSquare.y = middle2 - differencex;

}
else {
square.thirdVertexOfSquare.x = middle1 + differencey;
square.thirdVertexOfSquare.y = middle2 - differencex;

square.fourthVertexOfSquare.x = middle1 - differencey;
square.fourthVertexOfSquare.y = middle2 + differencex;
}

    cout << square.thirdVertexOfSquare.x << " " 
    << square.thirdVertexOfSquare.y << " "
        << square.fourthVertexOfSquare.x << " "
        << square.fourthVertexOfSquare.y << endl;
}

int main() {
    Square square;
    cin >> square.firstVertexOfSquare.x >> square.firstVertexOfSquare.y
        >> square.secondVertexOfSquare.x >> square.secondVertexOfSquare.y;

    distanceBetweenTwoVertex(square);

    return 0;
}
