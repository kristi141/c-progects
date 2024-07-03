/*RU
Условие:
Дано натуральное число n.
Необходимо вывести наименьший делитель числа n, отличный от 1.
Гарантируется что число n – составное.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 109).

Выходные данные:
В выходной файл необходимо вывести единственное значение – 
наименьший делитель числа n.

ENG
Condition:
Given a natural number n.
You need to print the smallest divisor of n that is different from 1.
It is guaranteed that the number n is composite.

Input data:
The first line of the input file contains the natural number n (1 ≤ n ≤ 109).

Output:
The only value you need to output to the output file is:
the smallest divisor of n.*/

#include<iostream>
using namespace std;

int main() {
    int i;
    int n;

    i = 1;
    cin >> n;

    while (i <= n)
    {
        i++;
        if (n % i == 0)
        {
            cout << i;
            break;
        }
    }
    return 0;
}