/*RU
Условие:
Дана шахматная доска размером n*m.  На каждой клетке данной доски стоит число 
(числа могут быть как положительными, так и отрицательными). На данной доске 
стоит шахматный конь (в левой верхней клетке).  
Помогите коню добраться до правой нижней клетки данной доски и при этом 
собрать наибольшую сумму чисел. 
Конь может ходить только двумя способами: 
2 клетки вправо и 1 вниз (x+2, y+1); 
2 клетки вниз и 1 вправо (x+1, y+2). 

Входные данные:
В первой строке входного файла даны два значения:n,m (1<=n, m<=1000) – 
размерность поля.  
Далее во входном файле дано само поле. 
Левая верхняя клетка доски имеет координаты (1, 1), правая нижняя - (n, m). 

Выходные данные:
В выходной файл должно быть выведено единственное значение – наибольшая 
сумма, которую сможет собрать конь.  
Если конь не может добраться до правой нижней клетки доски, 
то выведите «-». 

Входные данные:
1)
3 3 
5 0 0 
0 1 2  
1 0 1 

2)
4 4 
5 2 1 0 
1 0 0 0 
2 1 3 0 
0 0 1 7 

Выходные данные:
1) -
2) 13

ENG
Condition:
Given a chessboard of size n*m. On each square of this board there is a number
(numbers can be either positive or negative). On this board
there is a chess knight (in the upper left square).
Help the knight get to the bottom right square of this board and at the same time
collect the largest sum of numbers.
A horse can only move in two ways:
2 cells to the right and 1 down (x+2, y+1);
2 cells down and 1 to the right (x+1, y+2).

Input data:
The first line of the input file contains two values: n,m (1<=n, m<=1000) –
field dimension.
Further in the input file the field itself is given.
The upper left cell of the board has coordinates (1, 1), the lower right - (n, m).

Output:
A single value should be output to the output file - the largest
the amount that the horse can collect.
If the knight cannot reach the bottom right square of the board,
then print "-".

Input data:
1)
3 3 
5 0 0 
0 1 2  
1 0 1 

2)
4 4 
5 2 1 0 
1 0 0 0 
2 1 3 0 
0 0 1 7 

Output:
1) -
2) 13                        */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int getMaxSum(int n, int m, vector<vector<int>>& board) {
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    vector<pair<int, int>> moves = { {2, 1}, {1, 2} };

    dp[0][0] = board[0][0];

    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (auto move : moves) {
            int nx = x + move.first;
            int ny = y + move.second;

            if (nx < n && ny < m) {
                if (dp[nx][ny] < dp[x][y] + board[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + board[nx][ny];
                    q.push({ nx, ny });
                }
            }
        }
    }

    if (dp[n - 1][m - 1] == INT_MIN) {
        return -1;
    }
    else {
        return dp[n - 1][m - 1]; 
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int result = getMaxSum(n, m, board);

    if (result == -1) {
        cout << "-";
    }
    else {
        cout << result << endl;
    }

    return 0;
}