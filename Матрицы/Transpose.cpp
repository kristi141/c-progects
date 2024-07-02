/*Условие:
Дана матрица. Транспонируйте и выведите её.
Транспонирование матрицы – замена строк столбцами.

Входные данные:
На вход даётся два натуральных числа n и m (n ≤ 1000, m ≤ 100). 
Далее в n строках даётся по m целых чисел – элементы матрицы.

Выходные данные:
Транспонируйте матрицу, а затем выведите её.*/

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

    int transposed[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}