/*RU
Условие:
Дано натуральное число n.
Необходимо вывести через пробел все натуральные числа от 1 до n.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n ≤ 109).

Выходные данные:
В выходной файл необходимо вывести через пробел все натуральные числа 
от 1 до n.

ENG
Condition:
Given a natural number n.
It is necessary to print all natural numbers from 1 to n separated by a space.

Input data:
The first line of the input file contains the natural number n (1 ≤ n ≤ 109).

Output:
All natural numbers must be printed in the output file, separated by spaces.
from 1 to n.*/

#include<iostream>
using namespace std;

int main() {
    int n;
    int i;
    i = 1;

    cin >> n;
    while (i < n + 1) {
        cout << i << " ";
        i++;
    }
}