/*Условие:
Дано множество S натуральных чисел, состоящее из n элементов. 

Необходимо разделить множество S на два подмножества S1 и S2 так, что 
разница между суммой элементов подмножества S1 и суммой элементов 
подмножества S2 будет минимальна. 

Входные данные:
На вход дается количество элементов множества (1<=n<=105), а затем само 
множество. 

Выходные данные:
В выходной файл должно быть выведено единственное значение – 
минимальная разница между суммой элементов первого подмножества и 
суммой элементов второго подмножества.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int minimalDifferenceOfSet(vector<int>& numbers) {
    int numberOfSetElements = numbers.size();
    int totalSum = 0;
    for (int num : numbers) {
        totalSum += num;
    }

    vector<vector<bool>> dp(numberOfSetElements + 1, vector<bool>(totalSum + 1, false));

    for (int i = 0; i <= numberOfSetElements; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= numberOfSetElements; i++) {
        for (int j = 1; j <= totalSum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (numbers[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - numbers[i - 1]];
            }
        }
    }

    int minimalDifference = numeric_limits<int>::max();

    for (int j = totalSum / 2; j >= 0; j--) {
        if (dp[numberOfSetElements][j]) {
            minimalDifference = totalSum - 2 * j;
            break;
        }
    }

    return minimalDifference;
}

int main() {
    int numberOfSetElements;
    cin >> numberOfSetElements;

    vector<int> numbers(numberOfSetElements);
    for (int i = 0; i < numberOfSetElements; i++) {
        cin >> numbers[i];
    }

    int result = minimalDifferenceOfSet(numbers);
    cout << result << endl;

    return 0;
}