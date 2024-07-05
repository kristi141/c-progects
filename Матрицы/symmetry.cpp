/*RU
Условие:
Дана целочисленная матрица. Проверьте, обладает ли она вертикальной или 
горизонтальной симметричностью.

Входные данные:
В первой строке записаны натуральные числа n и m (1 ≤ n,m≤103 ) – 
количество строк и столбцов матрицы.
В следующих n строках записано по m чисел – значения ячеек 
матрицы (1 ≤matrixi,j ≤109).

Выходные данные:
Выведите “Yes”, если матрица обладает вертикальной (a[i][j] = a[n-i][j]) или 
горизонтальной (a[i][j] = a[i][m-j]) симметричностью, иначе – выведите “No”.

Входные данные:
1)
3 3
2 3 4
1 1 1
2 3 4

2)
3 3
2 1 2
3 1 3
4 1 4

3)
3 3
1 2 3
4 5 6
7 8 9

Выходные данные:
1)Yes

2)Yes

3)No

ENG
Condition:
An integer matrix is ​​given. Check if it has vertical or
horizontal symmetry.

Input data:
The first line contains natural numbers n and m (1 ≤ n,m≤103 ) –
number of rows and columns of the matrix.
The next n lines contain m numbers - cell values
matrices (1 ≤matrixi,j ≤109).

Output:
Print “Yes” if the matrix is ​​vertical (a[i][j] = a[n-i][j]) or
horizontal (a[i][j] = a[i][m-j]) symmetry, otherwise print “No”.

Input data:
1)
3 3
2 3 4
1 1 1
2 3 4

2)
3 3
2 1 2
3 1 3
4 1 4

3)
3 3
1 2 3
4 5 6
7 8 9

Output:
1)Yes

2)Yes

3)No                      */

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