/*RU
Условие:
Необходимо написать процедуру, которая будет сортировать заданный массив.

Входные данные:
Первая строка входного файла содержит единственное число N – количество 
элементов массива (1 ≤ N ≤ 1000).
Вторая строка содержит N чисел – элементы массива. 
Элементы не превосходят 100000.

Выходные данные:
В выходной файл необходимо вывести отсортированный массив.

Входные данные:
5
7 3 0 1 4

Выходные данные:
0 1 3 4 7

ENG
Condition:
It is necessary to write a procedure that will sort a given array.

Input data:
The first line of the input file contains a single number N - quantity
array elements (1 ≤ N ≤ 1000).
The second line contains N numbers - array elements.
Elements do not exceed 100000.

Output:
The sorted array must be output to the output file.*/

#include <iostream>
using namespace std;

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    bubbleSort(array, N);

    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }

    return 0;
}