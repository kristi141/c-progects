/*Условие:
Даны множество натуральных чисел, состоящее из n элементов, и целое значение s.
Необходимо найти непустое подмножество, сумма которого равна s. 

Входные данные:
На вход дается количество элементов множества (1<=n<=100000), затем 
значение s, а затем само множество. 

Выходные данные:
В выходной файл должно быть выведено единственное слово: «Yes», 
если такое подмножество существует, и «No», если его не существует.*/

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