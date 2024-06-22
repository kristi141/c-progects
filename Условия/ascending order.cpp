/*Условие:
Даны три числа.
Необходимо вывести их в порядке возрастания.

Входные данные:
На вход даются три различных натуральных числа, не превышающих по модулю 10^6.

Выходные данные:
В выходной файл должны быть выведены эти числа, 
расположенные в порядке возрастания.*/

#include <iostream>
using namespace std;

int main() {
	int e;
	int p;
	int l;

	cin >> e;
	cin >> p;
	cin >> l;

    if (e < p && e < l){
        cout << e << " ";
        if (p < l)
            cout << p << " " << l;
        else
            cout << l << " " << p;
    }
    else if (p < e && p < l){
        cout << p << " ";
        if (e < l)
            cout << e << " " << l;
        else
            cout << l << " " << e;
    }
    else{ 
        cout << l << " ";
        if (p < e)
            cout << p << " " << e;
        else
            cout << e << " " << p;
    }
}