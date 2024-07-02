/*Условие:
Дано число – размер квадратной матрицы. Обойдите матрицу по диагонали и 
заполните последовательными натуральными числами.

Входные данные:
На вход даётся натуральное число n – размер матрицы (n ≤ 100).

Выходные данные:
Выведите матрицу заполнив её начиная с левого верхнего угла, параллельно 
побочной диагонали числами с 1 по n*n.*/

#include <iostream>
using namespace std;

void transposeMatrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int matrix[100][100];
    int num = 1;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i < n && j < n) {
                matrix[i][j] = num++;
            }
        }
    }

    for (int k = 1; k < n; k++) {
        for (int i = k; i < n; i++) {
            int j = n - (i - k) - 1;
            if (i < n && j < n) {
                matrix[i][j] = num++;
            }
        }
    }

    transposeMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

