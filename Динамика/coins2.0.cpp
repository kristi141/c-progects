/*Условие:
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
модулю 10^9 + 7*/

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