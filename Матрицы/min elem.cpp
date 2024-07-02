/*Условие:
Дана матрица. Найдите её наименьший элемент.

Входные данные:
На вход даётся два натуральных числа n и m (n ≤ 1000, m ≤ 100).
 Далее в n строках даётся по m целых чисел – элементы матрицы.

Выходные данные:
Выведите наименьший элемент матрицы.*/

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int matrix[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int minimalElement = matrix[0][0]; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < minimalElement) {
                minimalElement = matrix[i][j];
            }
        }
    }

    cout << minimalElement;

    return 0;
}