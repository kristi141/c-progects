/*RU
Условие:
Дано число n. Проверьте, является ли оно палиндромом.
Примечание: палиндром – строка, которая читается одинаково в любом 
направлении (слева направо или справа налево). 
Например, число 543345 является палиндромом.

Входные данные:
В первой строке входного файла дано натуральное число n (1 ≤ n≤10^9 ).

Выходные данные:
В выходной файл необходимо вывести “Yes”, если число является палиндромом, 
и “No” в противном случае.

ENG
Condition:
The number n is given. Check if it is a palindrome.
Note: a palindrome is a string that reads the same in any
direction (left to right or right to left).
For example, the number 543345 is a palindrome.

Input data:
The first line of the input file contains a natural number n (1 ≤ n≤10^9 ).

Output:
“Yes” must be output to the output file if the number is a palindrome,
and “No” otherwise.*/

#include <iostream>
using namespace std;
int Polindrome(int num) {
	int n = num;
	int rev = 0;

	while (n) {
		int r = n % 10;
		rev = rev * 10 + r;
		n = n / 10;
	}
	return (num == rev);
}
int main() {
	int n;
	cin >> n;
	if (Polindrome(n)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}