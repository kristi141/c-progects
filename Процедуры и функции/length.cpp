/*Условие:
Даны координаты X1 и X2 концов отрезка на числовой прямой. 
Необходимо написать функцию которая выводит длину данного отрезка.

Входные данные:
На вход даются два числа X1 и X2 – координаты концов отрезка 
(-10^9 ≤ X1 < X2 ≤ 10^9)

Выходные данные:
В выходной файл необходимо вывести длину отрезка.*/

#include <iostream>
using namespace std;

int lineSegment(int x1, int x2, int length){
   if (x2 > x1) {
        return length = x2 - x1;
    }
    else {
        return length = x1 - x2;
    }    
}

int main() {
    long long x1, x2, length;
    cin >> x1 >> x2;
    cout << lineSegment(x1,x2, length) << endl;
    
    return 0;
}