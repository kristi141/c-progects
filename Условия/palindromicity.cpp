/*RU
Условие:
Дано четырёхзначное число.
Необходимо определить является ли оно палиндромом.
Примечание: палиндром - это такое число, которое одинаково читается
слева направо и справа налево. Например, 14541 или 2332. 

Входные данные:
На вход даётся натуральное четырёхзначное число.

Выходные данные:
В выходной файл должна быть выведена единица,
если число является палиндромом, и ноль, если нет.

ENG
Condition:
A four-digit number is given.
It is necessary to determine whether it is a palindrome.
Note: a palindrome is a number that reads the same
from left to right and from right to left. For example, 14541 or 2332.

Input data:
The input is a natural four-digit number.

Output:
One should be output to the output file,
if the number is a palindrome, and zero if not.*/

 #include <iostream>
using namespace std;
int Polindrome(int num){	
	int n = num;
	int rev = 0;

	while (n){
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
		cout << 1;
	}
	else {
		cout << 0;
	}
}