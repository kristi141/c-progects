/*RU
Условие:
Грабитель, проникший в банк, обнаружил в сейфе n золотых слитков, 
массами w1, w2, ..., wk килограмм. При этом грабитель может унести не все 
слитки, т.к. его рюкзак может  выдержать массу не более W килограмм. 
Определите набор слитков, который должен взять грабитель, чтобы унести 
как можно больше золота. 

Входные данные:
В первой строке входного файла содержатся два значения: n (1<=n<=1000) – 
количество слитков и W – наибольшая масса, которую может унести грабитель. 
В следующей строке содержатся массы слитков (w1, w2, ..., wk). 

Выходные данные:
В выходной файл должно быть выведено единственное значение – 
наибольшая стоимость всех слитков, которые должен вынести грабитель

ENG
Condition:
A robber who broke into a bank found gold bars in the safe.
masses w1, w2, ..., wk kilogram. However, the robber may not take everything.
ingots, because his backpack can support a mass of no more than W kilograms.
Determine the set of ingots that the robber must take to carry away
as much gold as possible.

Input data:
The first line of the input file contains two values: n (1<=n<=1000) –
the number of ingots and W - the largest mass that the robber can carry away.
The next line contains the masses of the ingots (w1,w2, ...,wk).

Output:
The output file should contain a single value -
the greatest value of all the bullion that the robber must carry out*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + weights[i - 1]);
            }

        }

    }

    cout << dp[n][W] << endl;
    return 0;
}