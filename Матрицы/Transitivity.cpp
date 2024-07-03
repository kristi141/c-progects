/*RU
Условие:
Дана бинарная матрица. Проверьте её на транзитивность.
Матрица транзитивна для любых a,b,c (a != b != c) в матрице М, если для
 M[a][b] = 1 и M[b][c] = 1 выполняется условие, что M[a][c] = 1.

Входные данные:
На вход даётся натуральное число n – размер матрицы (n ≤ 1000). 
Далее в n строках даётся по m целых чисел – элементы матрицы.

Выходные данные:
Выведите единицу, если матрица транзитивна, и ноль, если нет.

ENG
Condition:
Given a binary matrix. Check it for transitivity.
The matrix is ​​transitive for any a,b,c (a != b != c) in the matrix M if for
 M[a][b] = 1 and M[b][c] = 1 the condition that M[a][c] = 1 is satisfied.

Input data:
The input is a natural number n – the size of the matrix (n ≤ 1000).
Next, n lines contain m integers each - the elements of the matrix.

Output:
Print one if the matrix is ​​transitive, and zero if not.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isTransitive = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) { 
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] == 1 && matrix[i][k] != 1) { 
                        isTransitive = false;
                        break;
                    }
                }
                if (!isTransitive) {
                    break;
                }
            }
        }
        if (!isTransitive) {
            break;
        }
    }

    if (isTransitive) {
        cout << "1";
    } else {
        cout << "0";
    }

    return 0;
}