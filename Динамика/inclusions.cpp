/*RU
Условие:
Даны множество натуральных чисел, состоящее из n элементов, и целое значение s.
Необходимо найти непустое подмножество, сумма которого равна s. 

Входные данные:
На вход дается количество элементов множества (1<=n<=100000), затем 
значение s, а затем само множество. 

Выходные данные:
В выходной файл должно быть выведено единственное слово: «Yes», 
если такое подмножество существует, и «No», если его не существует.

Входные данные:
1)
4 56 
56 4 39 21 

2)
7 1000000000 
21 84 25 55 80 38 12 

Выходные данные:
1) Yes
2) No

ENG
Condition:
Given a set of natural numbers consisting of n elements and an integer value s.
You need to find a non-empty subset whose sum is equal to s.

Input data:
The input is given the number of elements of the set (1<=n<=100000), then
the value of s, and then the set itself.

Output:
The output file should contain a single word: “Yes”
if such a subset exists, and "No" if it does not exist.

Input data:
1)
4 56 
56 4 39 21 

2)
7 1000000000 
21 84 25 55 80 38 12 

Output:
1) Yes
2) No                                 */

#include <iostream>
using namespace std;

int main() {
	int numberOfSetElements;
	int integerValue;
	int sum = 0, set;
	
	cin >> numberOfSetElements >> integerValue;
	int* elemens = new int[numberOfSetElements];

	for (int i = 0; i < numberOfSetElements; i++) {
		cin >> set;
		elemens[i] = set;
		sum += set;
	}

	if (sum < integerValue) {
		cout << "No";

		return 0;
	}

	int* meaning = new int[integerValue + 1] {0};
	meaning[0] = 1;

	for (int i = 0; i < numberOfSetElements; i++) {

		for (int j = integerValue; j >= elemens[i]; j--) {

			if (meaning[j - elemens[i]] == 1)meaning[j] = 1;
		}
	}

	for (int i = integerValue; i >= 0; i--) {

		if (meaning[i] == 1) {
			if (i == integerValue){
			  	cout << "Yes ";
			}
			else{
			 		cout << "No";
			}

			return 0;
		}
	}
}