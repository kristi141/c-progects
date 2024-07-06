/*RU
Условие:
Дано натуральное число n.
Необходимо вычислить факториал числа n (n!).
Примечание: n! = 1*2*3*…*n

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 12).

Выходные данные:
В выходной файл необходимо вывести единственное значение -  
факториал числа n.

Входные данные:
5

Выходные данные:
120

ENG
Condition:
Given a natural number n.
It is necessary to calculate the factorial of the number n (n!).
Note: n! = 1*2*3*…*n

Input data:
The first line of the input file contains a natural number n (1 ≤ n ≤ 12).

Output:
The only value you need to output to the output file is - factorial of n.

Input data:
5

Output:
120                                                            */

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i;
    i = 2;

    int a;
    a = 1;

    if (n < 1 || n > 12) {
        cout << 0;
    }
    else
    {
    while (i <= n)
    {
        a *= i;
        i++;
    }
    cout << a;
    }
    return 0;
}