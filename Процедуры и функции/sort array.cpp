/*Условие:
Необходимо написать процедуру, которая будет сортировать заданный массив.

Входные данные:
Первая строка входного файла содержит единственное число N – количество 
элементов массива (1 ≤ N ≤ 1000).
Вторая строка содержит N чисел – элементы массива. 
Элементы не превосходят 100000.

Выходные данные:
В выходной файл необходимо вывести отсортированный массив.*/

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