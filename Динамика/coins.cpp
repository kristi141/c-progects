/*RU
Условие:
Даны n различных номиналов монет, каждый номинал имеет своё достоинство. 
Необходимо указать минимальное количество монет для получения 
заданной суммы s. Для получения суммы s можно брать БЕСКОНЕЧНОЕ количество 
монет ЛЮБОГО номинала

Входные данные:
На вход дается количество номиналов монет (0<=n<=100000), затем значение s, 
а затем достоинство каждого номинала. 

Выходные данные:
В выходной файл должно быть выведено единственное значение – 
минимальное количество монет, если же собрать необходимую сумму невозможно, 
то следует вывести -1. 

ENG
Condition:
Given n different denominations of coins, each denomination has its own denomination.
You must specify the minimum number of coins to receive
given amount s. To obtain the sum s you can take an INFINITE amount
coins of ANY denomination

Input data:
The input is the number of coin denominations (0<=n<=100000), then the value s,
and then the denomination of each denomination.

Output:
The output file should contain a single value -
minimum number of coins, but if it is impossible to collect the required amount,
then you should output -1.*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int minCoins(int sum, vector<int>& denominations) {
    vector<int> dp(sum + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < denominations.size(); j++) {
            if (denominations[j] <= i && dp[i - denominations[j]] != numeric_limits<int>::max()) {
                dp[i] = min(dp[i], dp[i - denominations[j]] + 1);
            }
        }
    }

    return (dp[sum] == numeric_limits<int>::max()) ? -1 : dp[sum];
}

int main() {
    int numberOfCoinDenominations, sum;
    cin >> numberOfCoinDenominations >> sum;

    vector<int> denominations(numberOfCoinDenominations);
    for (int i = 0; i < numberOfCoinDenominations; i++) {
        cin >> denominations[i];
    }

    int result = minCoins(sum, denominations);
    cout << result << endl;

    return 0;
}