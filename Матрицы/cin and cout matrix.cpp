/*Условие:
Введите и выведите матрицу.

Входные данные:
В первой строке записаны натуральные числа n и m (1 ≤ n,m≤103 ) – 
количество строк и столбцов матрицы.
В следующих n строках записано по m чисел – значения ячеек 
матрицы (1 ≤matrixi,j ≤109).

Выходные данные:
Выведите n строк по m чисел – значения матрицы.*/

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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}