/*RU
Условие:
Даны координаты X1 и X2 концов отрезка на числовой прямой. 
Необходимо написать функцию которая выводит длину данного отрезка.

Входные данные:
На вход даются два числа X1 и X2 – координаты концов отрезка 
(-10^9 ≤ X1 < X2 ≤ 10^9) (5 8)

Выходные данные:
В выходной файл необходимо вывести длину отрезка. (3)

ENG
Condition:
The coordinates X1 and X2 of the ends of the segment on the number line are given.
It is necessary to write a function that displays the length of a given segment.

Input data:
Two numbers X1 and X2 are given as input - the coordinates of the ends of the segment
(-10^9 ≤ X1 < X2 ≤ 10^9)

Output:
The length of the segment must be output to the output file.*/

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