/*RU
Условие:
Дан массив, состоящий из n элементов, и некоторое значение x.
Необходимо вставить элемент x на k-ое место в данный массив, 
сместив последующие элементы.

Входные данные:
Первая строка входного файла содержит единственное натуральное 
число n – количество элементов в массиве.
Во второй строке находятся n чисел – элементы массива.
В третьей строке входного файла даны два числа: k – номер, 
куда необходимо вставить новый элемент (1 ≤ k), и целое 
число x – новый элемент.

Выходные данные:
В выходной файл необходимо вывести изменённый массив

ENG
Condition:
Given an array consisting of n elements and some value x.
It is necessary to insert element x at the k-th place in the given array,
shifting subsequent elements.

Input data:
The first line of the input file contains a single natural
number n – number of elements in the array.
The second line contains n numbers - elements of the array.
The third line of the input file contains two numbers: k – number,
where you need to insert a new element (1 ≤ k), and an integer
number x is a new element.

Output:
The modified array must be output to the output file*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k, x;
    cin >> k >> x;

    for (int i = n; i >= k; i--) {
        arr[i] = arr[i - 1];
    }

    arr[k - 1] = x;

    for (int i = 0; i < n + 1; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}