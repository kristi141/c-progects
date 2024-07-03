/*RU
Условие:
Даны n монет, у каждой из которых своё достоинство. 
Необходимо найти количество способов получения заданной суммы s. 
Каждую монету можно использовать несколько раз.

Входные данные:
На вход дается количество монет (1<=n<=100000), затем значение s, а затем 
достоинство каждой монеты. 

Выходные данные:
В первой строке выходного файла должно быть выведено единственное значение – 
количество способов получения заданной суммы. 
Так как количество способов может быть достаточно большим, выведите его по 
модулю 10^9 + 7

ENG
Condition:
You are given n coins, each of which has its own denomination.
It is necessary to find the number of ways to obtain a given amount s.
Each coin can be used several times.

Input data:
The input is given the number of coins (1<=n<=100000), then the value s, and then
denomination of each coin.

Output:
The first line of the output file should contain a single value -
number of ways to obtain a given amount.
Since the number of ways can be quite large, print it by
module 10^9 + 7*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countWays(int numberOfCoins, int sum, vector<int>& denominationOfEachCoin) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < numberOfCoins; i++) {
        int coin = denominationOfEachCoin[i];
        for (int j = coin; j <= sum; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }

    return dp[sum];
}

int main() {
    int numberOfCoins, sum;
    cin >> numberOfCoins >> sum;

    vector<int> denominationOfEachCoin(numberOfCoins);
    for (int i = 0; i < numberOfCoins; i++) {
        cin >> denominationOfEachCoin[i];
    }

    int ways = countWays(numberOfCoins, sum, denominationOfEachCoin);
    cout << ways << endl;

    return 0;
}