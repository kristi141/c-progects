/*Условие:
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
то выведите «-». */

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