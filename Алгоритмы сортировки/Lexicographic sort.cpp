/*RU
Условие:
Дан набор строк, состоящий из n элементов.
Необходимо отсортировать заданный набор слов в лексикографическом порядке 
(в алфавитном порядке).

Входные данные:
На вход даётся количество слов (n), а затем сами слова.

Выходные данные:
В выходной файл должны быть выведены все слова в лексикографическом порядке.

ENG
Condition:
Given a set of strings consisting of n elements.
You need to sort a given set of words in lexicographical order
(In alphabet order).

Input data:
The input is given the number of words (n), and then the words themselves.

Output:
The output file should contain all words in lexicographic order.*/

#include <iostream>
#include <string>
using namespace std;

void merge(string* Arr, int first,int middle, int last) {
    string* tempArr = new string[last - first + 1];
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

void mergeSort(string* Arr, int first, int last) {
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

    string* Arr = new string[n];
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
