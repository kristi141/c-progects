/*Условие:
Вася написал на длинной полоске бумаги большое число и решил похвастаться 
своему старшему брату Пете этим достижением. Но только он вышел из комнаты, 
чтобы позвать брата, как его сестра Катя вбежала в комнату и разрезала 
полоску бумаги на несколько частей. В результате, на каждой части оказалось 
одна или несколько идущих подряд цифр.
Теперь Вася не может вспомнить, какое именно число он написал. Только помнит, 
что оно было очень большое. Чтобы утешить младшего брата, Петя решил 
выяснить, какое максимальное число могло быть написано на полоске бумаги 
перед разрезанием. Помогите ему!

Входные данные:
На вход дается количество частей (1 ≤ n ≤ 1000), а затем n строк, в которой 
содержится от 1 до 100 цифр. Гарантируется, что хотя бы в одной строке 
первая цифра отлична от нуля.

Выходные данные:
В выходной файл должно быть выведено единственное значение - максимальное 
число, которое могло быть написано на полоске перед разрезанием.*/

#include <iostream>
#include <string>
using namespace std;

void merge(string* Arr, int first,int middle, int last) {
    string* tempArr = new string[last - first + 1];
    int left = first;
    int right = middle + 1;
    int index = 0;

    while (left <= middle && right <= last) {
        if (Arr[left] + Arr[right] > Arr[right] + Arr[left]) {
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
        cout << Arr[i];
    }
    cout << endl;

    delete[] Arr;
    return 0;
}
