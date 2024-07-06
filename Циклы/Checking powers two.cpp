/*RU
Условие:
Дано число n. Необходимо проверить, является ли оно степенью двойки.

Входные данные:
В первой строке входного файла дано натуральное число n (1≤ n≤10^9).

Выходные данные:
В выходной файл необходимо вывести “Yes”, если число n можно представить 
в виде 2i , где i – целое неотрицательное число, иначе – выведите “No”

Входные данные:
1) 65536
2) 21

Выходные данные:
1) Yes
2) No

ENG
Condition:
The number n is given. You need to check whether it is a power of two.

Input data:
The first line of the input file contains a natural number n (1≤ n≤10^9).

Output:
“Yes” must be output to the output file if the number n can be represented
in the form 2i , where i is a non-negative integer, otherwise print “No”

Input data:
1) 65536
2) 21

Output:
1) Yes
2) No                                             */

#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;
	
	if ((n & (n - 1)) == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}