/*RU
Условие:
Дана матрица A, размером N * N, в каждой ячейке которой находится либо 0, 
либо 1. Назовём матрицу неориентированной, если значение в ячейке Ai, 
j равно значению в ячейке Aj, i. Если данное условие не выполняется, 
то будем считать матрицу ориентированной.
Вам необходимо написать программу, которая проверит данную матрицу 
на ориентированность.

Входные данные:
Первая строка входного файла содержит число N – количество строк и 
столбцов матрицы (1 ≤ N ≤ 1000).
Далее в N строках содержится по N чисел – значения ячеек матрицы.

Выходные данные:
В выходной файл необходимо вывести «YES» (без кавычек), если матрица 
является ориентированной, и «NO» (без кавычек) в противном случае.

ENG
Condition:
Given a matrix A of size N * N, each cell of which contains either 0,
or 1. Let's call the matrix unoriented if the value in the cell is Ai,
j is equal to the value in cell Aj, i. If this condition is not met,
then we will consider the matrix to be oriented.
You need to write a program that checks this matrix
on orientation.

Input data:
The first line of the input file contains the number N - the number of lines and
matrix columns (1 ≤ N ≤ 1000).
Next, N lines contain N numbers each - the values ​​of the matrix cells.

Output:
“YES” (without quotes) must be output to the output file if the matrix
is oriented, and "NO" (without quotes) otherwise.*/

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

    bool isOriented = true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (matrix[i][j] != matrix[j][i]) { 
                isOriented = false;
                break;
            }
        }
        if (!isOriented) {
            break;
        }
    }

    if (isOriented) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
