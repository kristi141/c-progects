/*RU
Условие:
Дан массив.
Необходимо вывести его в обратном порядке.

Входные данные:
На вход дается сам массив.

Выходные данные:
В выходной файл необходимо вывести через пробел элементы заданного массива 
в обратном порядке.

ENG
Condition:
Given an array.
You need to remove it in reverse order.

Input data:
The array itself is given as input.

Output:
It is necessary to output the elements of the specified array separated by 
spaces into the output file in reverse order.*/

#include <iostream>
using namespace std;

int main()
{
    int arr[100001];
    int x, i = 0;
    while (cin >> x) {
        arr[i] = x;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j] << " ";
    }
    return 0;
}