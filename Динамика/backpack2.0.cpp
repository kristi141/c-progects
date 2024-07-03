/*RU
Условие:
Грабитель, проникший в банк, обнаружил в сейфе n золотых слитков, массами 
w1, w2, ..., wk килограмм и ценностью p1, p2, ..., pk соответственно. 
При этом грабитель может унести слитки массой не более W килограмм. 
Определите набор слитков, который должен взять грабитель, чтобы унести 
как можно больше золота. 

Входные данные:
В первой строке входного файла содержатся два значения: n (1<=n<=1000) – 
количество слитков и W – наибольшая масса, которую может унести грабитель. 

Далее следует две строки: 
В первой строке содержится n чисел - ценности слитков.
Во второй строке содержится n чисел - веса слитков.

Выходные данные:
В выходной файл должно быть выведено единственное значение – наибольшая 
стоимость всех слитков, которые должен вынести грабитель

ENG
Condition:
A robber who broke into a bank found masses of gold bars in the safe.
w1,w2, ...,wk kilogram and value p1,p2, ...,pk, respectively.
In this case, the robber can take away ingots weighing no more than W kilograms.
Determine the set of ingots that the robber must take to carry away
as much gold as possible.

Input data:
The first line of the input file contains two values: n (1<=n<=1000) –
the number of ingots and W - the largest mass that the robber can carry away.

Next are two lines:
The first line contains n numbers - the value of the bullion.
The second line contains n numbers - the weight of the ingots.

Output:
A single value should be output to the output file - the largest
the value of all the bullion that the robber must carry out*/

#include <iostream> 
using namespace std;

int searchIngotMass(int W, int w[], int value[], int index, int** dp) {
	if (index < 0) {
		return 0;
	}

	if (dp[index][W] != -1) {
		return dp[index][W];
	}

	if (w[index] > W) {
		dp[index][W] = searchIngotMass(W, w, value, index - 1, dp);
		return dp[index][W];
	}
	else {
		dp[index][W] = max(value[index] + searchIngotMass(W - w[index], w, value, index - 1, dp),
			searchIngotMass(W, w, value, index - 1, dp));
		return dp[index][W];
	}
}

int Ingot(int W, int w[], int value[], int n) {
	int** dp;
	dp = new int* [n];

	for (int i = 0; i < n; i++) {
		dp[i] = new int[W + 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < W + 1; j++) {
			dp[i][j] = -1;
		}
	}

	return searchIngotMass(W, w, value, n - 1, dp);
}

int main() {
	int n, W;
	cin >> n >> W;

	int price[n];
	int weight[n];

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	cout << Ingot(W, weight, price, n);
	return 0;
}