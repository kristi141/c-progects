/*RU
Условие:
Дан массив, состоящий из n элементов.
Необходимо вывести его в обратном порядке.

Входные данные:
В первой строке входного файла дано натуральное число n – 
количество элементов в массиве.
Во второй строке входного файла даны n чисел – элементы массива.

Выходные данные:
В выходной файл необходимо через пробел вывести элементы массива 
в обратном порядке.

ENG
Condition:
Given an array consisting of n elements.
You need to remove it in reverse order.

Input data:
The first line of the input file contains a natural number n –
number of elements in the array.
The second line of the input file contains n numbers - array elements.

Output:
It is necessary to print the array elements separated by spaces into the 
output file in reverse order.*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}