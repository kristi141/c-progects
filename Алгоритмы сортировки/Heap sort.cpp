/*Условие:
Дан целочисленный массив, состоящий из n элементов.
Необходимо реализовать сортировку кучей (heap sort) для данного массива.

Входные данные:
На вход дается количество элементов массива(n), а затем и сам массив.

Выходные данные:
В выходной файл должен быть выведен отсортированный массив.*/

#include<iostream>
using namespace std;

void pyramid(int arr[], int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[large])
        large = left;
    if (right < n && arr[right] > arr[large])
        large = right;
    if (large != i) {
        swap(arr[i], arr[large]);
        pyramid(arr, n, large);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        pyramid(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        pyramid(arr, i, 0);
    }
}

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heapSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}