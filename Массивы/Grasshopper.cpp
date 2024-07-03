/*RU
Условие:
В одной из горных долин под ясным и чистым небом располагалось небольшое 
озеро. На водной глади озера в ряд плавали несколько кувшинок. На каждой 
кувшинке существовало некоторое количество волшебной травы. А на самой первой 
кувшинке сидел кузнечик. Как известно, кузнечики в той долине очень любят 
питаться волшебной травой. Но наш кузнечик может перемещаться вдоль кувшинок 
только в одну сторону. Кроме этого, он может перепрыгивать за раз либо через 
одну кувшинку, либо через две. Каждый раз, когда кузнечик оказывается на 
кувшинке, он забирает себе всю траву с неё. Цель кузнечика – собрать как 
можно больше травы. Вам известно, сколько кувшинок было на озере и сколько 
травы было на каждой кувшинке. Напишите программу, которая по этим данным 
выведет, какое максимальное количество волшебной травы может собрать 
кузнечик, добравшись до последней кувшинки.

Входные данные:
Первая строка входного файла содержит единственное число N – количество 
кувшинок (0 ≤ N ≤ 105).
Во второй строке находятся N чисел, где каждое число Ti равно количеству 
травы на i-той кувшинке (-109 ≤ Ti ≤ 109).

Выходные данные:
В выходной файл необходимо вывести суммарное количество травы, которое может 
собрать кузнечик, перепрыгивая через одну или через две кувшинки 
только вправо.

Входные данные:
1)
5
3 -3 6 1 5

2)
6
1 4 5 10 20 6

Выходные данные:
1) 14
2) 17

ENG
Condition:
In one of the mountain valleys under a clear and clear sky there was a small
lake. Several water lilies floated in a row on the water surface of the lake. 
On each There was a certain amount of magic herb in the water lily. And at 
the very first There was a grasshopper sitting on a water lily. As you know, 
grasshoppers in that valley are very fond of eat magic grass. But our 
grasshopper can move along the water lilies
only one way. In addition, he can jump over either
one water lily, or two. Every time a grasshopper finds itself on
water lily, he takes all the grass from it. The grasshopper's goal is to 
collect as much grass as possible. Do you know how many water lilies were on 
the lake and how many there was grass on every water lily. Write a program 
that, based on these data will display the maximum amount of magic grass 
that can be collected grasshopper reaching the last water lily.

Input data:
The first line of the input file contains a single number N - quantity
water lilies (0 ≤ N ≤ 105).
The second line contains N numbers, where each number Ti is equal to the number
grass on the i-th water lily (-109 ≤ Ti ≤ 109).

Output:
The output file must display the total amount of grass that can
collect a grasshopper by jumping over one or two water lilies
just to the right.

Input data:
1)
5
3 -3 6 1 5

2)
6
1 4 5 10 20 6

Output:
1) 14
2) 17                             */

#include <iostream>
#include <climits>
using namespace std;

long long trajectory(long long* grass, long long numberLilies)
{
	if (numberLilies == 1) {
		return grass[0];
	}
	else if (numberLilies == 2) {
		return 0;
	}
	else {
		grass[0] = grass[0];
		grass[1] = -INT_MAX;
		grass[2] = grass[0] + grass[2];

		for (int i = 3; i <= numberLilies; i++)
		{
			grass[i] += max(grass[i - 2], grass[i - 3]);
		}

		return grass[numberLilies - 1];
	}
}

int main()
{
	long long numberLilies;
	cin >> numberLilies;
	long long* grass = new long long[numberLilies];

	for (long long i = 0; i < numberLilies; i++) {
		cin >> grass[i];
	}

	cout << trajectory(grass, numberLilies) << endl;

	return 0;
}