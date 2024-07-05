/*RU
Условие:
Дана матрица. Найдите её наименьший элемент.

Входные данные:
На вход даётся два натуральных числа n и m (n ≤ 1000, m ≤ 100).
 Далее в n строках даётся по m целых чисел – элементы матрицы.

Выходные данные:
Выведите наименьший элемент матрицы.

Входные данные:
1)
3 3
1 2 3
4 5 6
7 8 9

2)
1 1
-1

Выходные данные:
1)1

2)-1

ENG
Condition:
Given a matrix. Find its smallest element.

Input data:
The input is given two natural numbers n and m (n ≤ 1000, m ≤ 100).
 Next, n lines contain m integers each - the elements of the matrix.

Output:
Print the smallest element of the matrix.

Input data:
1)
3 3
1 2 3
4 5 6
7 8 9

2)
1 1
-1

Output:
1)1

2)-1                                         */

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