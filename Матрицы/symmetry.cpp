/*Условие:
Дана целочисленная матрица. Проверьте, обладает ли она вертикальной или 
горизонтальной симметричностью.

Входные данные:
В первой строке записаны натуральные числа n и m (1 ≤ n,m≤103 ) – 
количество строк и столбцов матрицы.
В следующих n строках записано по m чисел – значения ячеек 
матрицы (1 ≤matrixi,j ≤109).

Выходные данные:
Выведите “Yes”, если матрица обладает вертикальной (a[i][j] = a[n-i][j]) или 
горизонтальной (a[i][j] = a[i][m-j]) симметричностью, иначе – выведите “No”.*/

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

    bool isVerticalSymmetric = true;
    bool isHorizontalSymmetric = true;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != matrix[n - i - 1][j]) {
                isVerticalSymmetric = false;
                break;
            }
        }
        if (!isVerticalSymmetric) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            if (matrix[i][j] != matrix[i][m - j - 1]) {
                isHorizontalSymmetric = false;
                break;
            }
        }
        if (!isHorizontalSymmetric) {
            break;
        }
    }

    if (isVerticalSymmetric || isHorizontalSymmetric) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}