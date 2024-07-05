/*RU
Условие:
Дана матрица. Транспонируйте и выведите её.
Транспонирование матрицы – замена строк столбцами.

Входные данные:
На вход даётся два натуральных числа n и m (n ≤ 1000, m ≤ 100). 
Далее в n строках даётся по m целых чисел – элементы матрицы.

Выходные данные:
Транспонируйте матрицу, а затем выведите её.

Входные данные:
1)
3 3
1 2 3
4 5 6
7 8 9

2)
2 3
1 2 3
4 5 6

Выходные данные:
1)
1 4 7
2 5 8
3 6 9

2)
1 4
2 5
3 6

ENG
Condition:
Given a matrix. Transpose and output it.
Transposing a matrix is ​​replacing rows with columns.

Input data:
The input is given two natural numbers n and m (n ≤ 1000, m ≤ 100).
Next, n lines contain m integers each - the elements of the matrix.

Output:
Transpose the matrix and then output it.

Input data:
1)
3 3
1 2 3
4 5 6
7 8 9

2)
2 3
1 2 3
4 5 6

Output:
1)
1 4 7
2 5 8
3 6 9

2)
1 4
2 5
3 6                                                 */

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