/*RU
Условие:
Дано натуральное число n.
Необходимо вывести его по цифрам в прямом и обратном порядке.

Входные данные:
В первой строке входного файла дано натуральное число n (1≤ n≤10^9).

Выходные данные:
В первой строке выходного файла необходимо вывести через пробел цифры 
числа n в прямом порядке.
Во второй строке выходного файла необходимо вывести через пробел цифры 
числа n в обратном порядке.

ENG
Condition:
Given a natural number n.
It is necessary to display it numerically in forward and reverse order.

Input data:
The first line of the input file contains a natural number n (1≤ n≤10^9).

Output:
In the first line of the output file you need to print the numbers separated 
by spaces numbers n in direct order.
In the second line of the output file you need to print the numbers separated 
by spaces numbers n in reverse order.*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int r;
    int b = 0;
    int a;
    int c = n;
    int zero = 0;
    int d;

    while (c > 0) {
        a = c % 10;
        b = b * 10 + a;
        c /= 10;
    }

    
    while (n % 10 == 0) {
        zero++;
        n /= 10;
    }

    while (b > 0) {
        int d = b % 10;
        cout << d << " ";
        b /= 10;
    }

    for (int i = 0; i < zero; i++) {
        cout << 0 << " ";
    }
    cout << endl;

    for (int i = 0; i < zero; i++) {
        cout << 0 << " ";
    }

    while (n > 0) {
        r = n % 10;
        cout << r << " ";
        n = n / 10;
    }
    return 0;
}