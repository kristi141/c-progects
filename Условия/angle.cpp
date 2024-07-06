/*RU
Условие:
Необходимо по заданному времени (часы и минуты в двенадцатичасовом формате) 
найти угол между часовой и минутной стрелкой на аналоговых часах 
с двенадцатичасовым циферблатом.
Примечание: часовая стрелка двигается раз в час.

Входные данные:
На вход даются два числа: часы H и минуты M (1 ≤ H ≤ 12, 0 ≤ M ≤ 59).

Выходные данные:
В выходной файл необходимо вывести единственное значение – 
угол между часовой и минутной стрелкой, выраженный в градусах.

Входные данные:
1)
6 0

2)
12 0

Выходные данные:
1) 180
2) 0

ENG
Condition:
Required at a given time (hours and minutes in twelve-hour format)
find the angle between the hour and minute hands on an analog clock
with a twelve-hour dial.
Note: The hour hand moves once every hour.

Input data:
Two numbers are given as input: hours H and minutes M (1 ≤ H ≤ 12, 0 ≤ M ≤ 59).

Output:
The only value you need to output to the output file is:
the angle between the hour and minute hands, expressed in degrees.

Input data:
1)
6 0

2)
12 0

Output:
1) 180
2) 0                                           */

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double H, M;

	cin >> H;
	cin >> M;

	double m, h, a;

	m = 6 * M;
	h = 30 * H;
	a = abs(h - m);

	if (a > 180) {
		a = 360 - a;
	}
	cout << a;

	return 0;
}