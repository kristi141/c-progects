/*RU
Условие:
Дан символ. Необходимо вывести его номер в ASCII
ASCII таблица – таблица, в которой некоторым распространённым печатным 
и непечатным символам сопоставлены числовые коды.

Входные данные:
На вход даётся один символ.

Выходные данные:
Необходимо вывести единственное число – номер символа в ASCII.

ENG
Condition:
Given the symbol. It is necessary to display its number in ASCII
ASCII table - a table in which some common printed characters
and non-printable characters are assigned numeric codes.

Input data:
One character is given per input.

Output:
It is necessary to output a single number - the character number in ASCII.*/

#include <iostream>
using namespace std;

int main() {
	char a ;
	cin >> a;

	int b = (int)a;
	cout << b;	
}