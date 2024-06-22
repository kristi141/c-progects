/*Условие:
Дано число.
Необходимо вывести название дня недели на английском языке, 
соответствующее данному числу.

Входные данные:
На вход даётся натуральное число, не превосходящее по модулю 7.

Выходные данные:
В выходной файл должно быть выведено соответствующее название дня недели.*/

#include<iostream>
using namespace std;

int main(){
	int day;

	cin >> day;

	switch (day) {
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	case 7:
		cout << "Sunday";
		break;
	default:
		cout << "There is no such day of the week!";
	}
}