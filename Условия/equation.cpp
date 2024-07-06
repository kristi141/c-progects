/*RU
Условие:
Дано уравнение:
ax2 + bx + c = 0.
Необходимо написать программу, которая по введённым целочисленным параметрам 
a,b,c решит это уравнение.

Входные данные:
На вход даются три целых числа - a,b,c, по модулю не превышающих 1000.

Выходные данные:
В выходной файл через пробел необходимо вывести количество корней 
этого уравнения, после этого все корни этого уравнения в порядке неубывания, 
если этого сделать нельзя, то вывести -1.

Входные данные:
1)
1 -2 1

2)
1 -8 15

Выходные данные:
1)
1 1

2)
2 3 5

ENG
Condition:
Given the equation:
ax2 + bx + c = 0.
It is necessary to write a program that, based on the entered integer parameters
a,b,c will solve this equation.

Input data:
Three integers are given as input - a, b, c, modulo not exceeding 1000.

Output:
The number of roots must be printed in the output file separated by spaces.
this equation, after that all the roots of this equation in non-decreasing order,
if this cannot be done, then output -1.

Input data:
1)
1 -2 1

2)
1 -8 15

Output:
1)
1 1

2)
2 3 5                                                     */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  long double a;
  long double b;
  long double c;
  long double D;
  
  cin >> a >> b >> c;
  
   D = b * b - 4.0 * a * c;
  if(a != 0 && b == 0 && c == 0)
    cout << 1 << " " << 0;
  else{
    if(a == 0){
      if(b == 0 && c == 0)
        cout << -1;
      else if(b == 0 && c != 0)
        cout << 0;
      else
        cout << 1 << " " << -1.0 * c / b;
    }
    else{
      if(D < 0){
        cout << 0;
      }
      else if(D == 0){
        cout << 1 << " " << -1.0 * b / (2.0 * a);
      }
      else{
        long double x1;
        long double x2;
        x1 = (-1.0 * b - sqrt(D))/(2.0 * a);
        x2 = (-1.0 * b + sqrt(D))/(2.0 * a);
        if(x1 <= x2)
          cout << 2 << " " << x1 << " " << x2;
        else
          cout << 2 << " " << x2 << " " << x1;
      }
    }
  }
  return 0;
}