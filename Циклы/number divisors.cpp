/*RU
Условие:
Дано натуральное число n.
Необходимо вывести количество делителей числа n (включая 1 и n).

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 109).

Выходные данные:
В выходной файл необходимо вывести единственное значение – 
количество делителей числа n (включая 1 и n).

Входные данные:
12

Выходные данные:
6

ENG
Condition:
Given a natural number n.
You need to print the number of divisors of the number n (including 1 and n).

Input data:
The first line of the input file contains the natural number n (1 ≤ n ≤ 109).

Output:
The only value you need to output to the output file is:
the number of divisors of n (including 1 and n).

Input data:
12

Output:
6                                                   */

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a;
    a = 0;

    int i;
    i = 1;
 

    while (i * i <= n)
    {
        if (n % i == 0)
        {
            a += 2;
            if (i * i == n) {
                a--;
            }
        }
        i++;
    }
    cout << a;
    return 0;
}