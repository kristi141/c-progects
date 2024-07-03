/*RU
Условие:
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
суммой элементов второго подмножества.

Входные данные:
1)
8 
67 37 86 7 96 77 81 87 

2)
5 
10 20 15 5 25 

Выходные данные:
1) 0
2) 5

ENG
Condition:
Given a set S of natural numbers, consisting of n elements.

It is necessary to divide the set S into two subsets S1 and S2 so that
difference between the sum of elements of subset S1 and the sum of elements
subset S2 will be minimal.

Input data:
The input is given the number of elements of the set (1<=n<=105), and then
a bunch of.

Output:
The output file should contain a single value -
the minimum difference between the sum of the elements of the first subset and
the sum of the elements of the second subset.

Input data:
1)
8 
67 37 86 7 96 77 81 87 

2)
5 
10 20 15 5 25 

Output:
1) 0
2) 5                              */

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