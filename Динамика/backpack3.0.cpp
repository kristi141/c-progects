/*RU
Условие:
Грабитель, проникший в банк, обнаружил в сейфе n золотых слитков, массами 
w1, w2, ..., wk килограмм и ценностью p1, p2, ..., pk соответственно. 
При этом грабитель может унести слитки массой не более W килограмм. 
Определите набор слитков, который должен взять грабитель, чтобы унести как 
можно больше золота. 

Входные данные:
В первой строке входного файла содержатся два значения: n (1<=n<=500) – 
количество слитков и W – наибольшая масса, которую может унести грабитель. 
В следующих двух строках записаны два массива - ценность и вес слитков.

Выходные данные:
В выходной файл выведите через пробел номера слитков, которые грабитель 
должен взять

Входные данные:
1)
2 10 
100 80 
10 9 

2)
5 100 
1000 550 550 550 550
80 50 50 50 50

Выходные данные:
1) 1
2) 2 3

ENG
Condition:
A robber who broke into a bank found masses of gold bars in the safe.
w1,w2, ...,wk kilogram and value p1,p2, ...,pk, respectively.
In this case, the robber can take away ingots weighing no more than W kilograms.
Determine the set of ingots that the robber must take in order to carry off as
as much gold as possible.

Input data:
The first line of the input file contains two values: n (1<=n<=500) –
the number of ingots and W - the largest mass that the robber can carry away.
The next two lines contain two arrays - the value and weight of the bars.

Output:
In the output file, print the numbers of the ingots that the robber
must take

Input data:
1)
2 10 
100 80 
10 9 

2)
5 100 
1000 550 550 550 550
80 50 50 50 50

Output:
1) 1
2) 2 3               */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ingot {
    int weight;
    int value;
    int index;
};

bool cmp(const Ingot& a, const Ingot& b) {
    return a.value > b.value;
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<Ingot> ingots(n);
    for (int i = 0; i < n; i++) {
        cin >> ingots[i].value;
        ingots[i].index = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> ingots[i].weight;
    }

    sort(ingots.begin(), ingots.end(), cmp);

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    vector<vector<bool>> take(n + 1, vector<bool>(W + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (ingots[i - 1].weight > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                int takeValue = dp[i - 1][j - ingots[i - 1].weight] + ingots[i - 1].value;
                if (takeValue > dp[i - 1][j]) {
                    dp[i][j] = takeValue;
                    take[i][j] = true;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    vector<int> chosenIngots;
    int curWeight = W;
    for (int i = n; i > 0; i--) {
        if (take[i][curWeight]) {
            chosenIngots.push_back(ingots[i - 1].index);
            curWeight -= ingots[i - 1].weight;
        }
    }
    reverse(chosenIngots.begin(), chosenIngots.end());

    for (int i = 0; i < chosenIngots.size(); i++) {
        cout << chosenIngots[i] << " ";
    }
    cout << endl;

    return 0;
}