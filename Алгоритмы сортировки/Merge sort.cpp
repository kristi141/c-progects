/*RU
Условие:
Дан целочисленный массив, состоящий из n элементов.
Необходимо реализовать сортировку слиянием (merge sort) для данного массива.

Входные данные:
На вход дается количество элементов массива(n), а затем и сам массив.

Выходные данные:
В выходной файл должен быть выведен отсортированный массив.

ENG
Condition:
Given an integer array consisting of n elements.
It is necessary to implement merge sort for this array.

Input data:
The input is the number of elements of the array (n), and then the array itself.

Output:
A sorted array should be output to the output file.*/

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