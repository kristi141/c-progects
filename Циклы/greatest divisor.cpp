/*RU
Условие:
Дано натуральное число n.
Необходимо вывести наибольший делитель числа n, отличный от n.
Гарантируется что число n – составное.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 109).

Выходные данные:
В выходной файл необходимо вывести единственное значение -  
наибольший делитель числа n.

ENG
Condition:
Given a natural number n.
It is necessary to print the greatest divisor of the number n, different from n.
It is guaranteed that the number n is composite.

Input data:
The first line of the input file contains the natural number n (1 ≤ n ≤ 109).

Output:
The only value you need to output to the output file is -
greatest divisor of n.*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int large; 
    int i;
    i = 2;
    large = n;

    while (i * i <= n)
    {
        if (n % i == 0)
        {
            large = n / i;
            break;
        }
        i++;
    }
    cout << large;
    return 0;
}