/*Условие:
Дан целочисленный массив, состоящий из n элементов.
Необходимо реализовать стабильную сортировку для данного массива. 
Трудоемкость алгоритма не должна превышать O(nlogn).
Стабильная сортировка — сортировка, которая не меняет относительный порядок 
сортируемых элементов, имеющих одинаковое значение. (Например, дан массив: 
8 4 2 1 2 9, после сортировки данный массив будет выглядеть: 1 2 2 4 8 9. 
Обратите внимание, при использовании стабильной сортировки в отсортированном 
массиве сначала будет стоять 2-ка, индекс которой в первоначальном массиве 
был меньше.)

Входные данные:
На вход дается количество элементов массива(1<=n<=100000), а затем и сам массив.

Выходные данные:
В выходной файл должен быть выведен отсортированный массив.*/

#include <iostream>
using namespace std;

void merge(int* Arr, int first, int middle, int last) {
    int* tempArr = new int[last - first + 1];
    int left = first;
    int right = middle + 1;
    int index = 0;

    while (left <= middle && right <= last) {
        if (Arr[left] <= Arr[right]) {
            tempArr[index] = Arr[left];
            left++;
        }
        else {
            tempArr[index] = Arr[right];
            right++;
        }
        index++;
    }

    while (left <= middle) {
        tempArr[index] = Arr[left];
        left++;
        index++;
    }

    while (right <= last) {
        tempArr[index] = Arr[right];
        right++;
        index++;
    }

    for (int i = 0; i < index; i++) {
        Arr[first + i] = tempArr[i];
    }

    delete[] tempArr;
}

void mergeSort(int* Arr, int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        mergeSort(Arr, first, middle);
        mergeSort(Arr, middle + 1, last);
        merge(Arr, first, middle, last);
    }
}

int main() {
    int n;
    cin >> n;

    int* Arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }

    mergeSort(Arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;

    delete[] Arr;
    return 0;
}