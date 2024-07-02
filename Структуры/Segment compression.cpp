/*Условие:
На Новом проспекте для разгрузки было решено пустить два новых автобусных 
маршрута на разных участках проспекта. Все остановки на проспекте 
пронумерованы подряд натуральными числами. Известны начальные и конечные 
остановки каждого из автобусов. Определите количество остановок, на которых 
можно пересесть с одного автобуса на другой.  

Входные данные:
На вход даны четыре натуральных числа — номера начальных и конечных 
остановок сначала первого, потом второго автобуса. Числа не превосходят 109. 

Выходные данные:
В выходной файл должно быть выведено единственное значение - искомое 
количество остановок. */

#include <iostream>
using namespace std;

struct busStop {
	long long start;
	long long finish;
};

int main() {
	busStop busStops[2];

	for (int i = 0; i < 2; i++) {
		cin >> busStops[i].start >> busStops[i].finish;

		if (busStops[i].start > busStops[i].finish) {
			long long temp = busStops[i].start;
			busStops[i].start = busStops[i].finish;
			busStops[i].finish = temp;
		}
	}
		if (busStops[1].finish == busStops[0].start || busStops[1].start == busStops[0].finish) {
			cout << 1;
		}
		else if (busStops[1].finish < busStops[0].start || busStops[0].finish < busStops[1].start) {
			cout << 0;
		}
		else {
		  cout << min(busStops[1].finish , busStops[0].finish) - max(busStops[0].start , busStops[1].start) +1;
		}

		return 0;
	}