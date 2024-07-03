/*RU
Условие:
Дана матрица. Необходимо начиная с левой верхней ячейки обойти её внутрь 
спиралью по часовой стрелке и вывести числа, находящиеся в этих ячейках.

Входные данные:
Первая строка содержит два числа N и M – размер матрицы (1 ≤ N, M ≤ 104).
Далее в N строках содержится по M чисел – ячейки матрицы.

Выходные данные:
В выходной файл необходимо вывести через пробел числа, которые встречаются 
в результате обхода матрицы внутрь по часовой стрелке.

ENG
Condition:
Given a matrix. It is necessary, starting from the upper left cell, to go 
around it inward spiral clockwise and print the numbers in these cells.

Input data:
The first line contains two numbers N and M – the size of the matrix 
(1 ≤ N, M ≤ 104).
Next, N lines contain M numbers each - matrix cells.

Output:
The output file must contain the numbers that appear, separated by spaces.
as a result of traversing the matrix inward clockwise.*/

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

    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            cout << matrix[top][j] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    return 0;
}
