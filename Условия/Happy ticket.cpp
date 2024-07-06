/*RU
Условие:
Дан номер билета.
Необходимо определить является ли он “счастливым”.
Примечание: “Счастливый” билет - билет у которого первые и 
последние три цифры дают одинаковую сумму.

Входные данные:
На вход даётся шестизначное натуральное число с лидирующими нулями.

Выходные данные:
В выходной файл должна быть выведена единица, если номер билета “счастливый”,
и ноль, если нет.

Входные данные:
1)
000001

2)
953269

Выходные данные:
1) 0
2) 1
 
ENG
Condition:
The ticket number is given.
It is necessary to determine whether he is “happy”.
Note: A “lucky” ticket is a ticket that has the first and
the last three digits give the same amount.

Input data:
The input is a six-digit natural number with leading zeros.

Output:
One should be output to the output file if the ticket number is “lucky”,
 and zero if not.*/

 #include<iostream>
using namespace std;

int main() {
    int num;

    cin >> num;

    int a1 = num / 100000;
    int a2 = num / 10000 % 10;
    int a3 = num / 1000 % 10;
    int a4 = num / 100 % 10;
    int a5 = num / 10 % 10;
    int a6 = num % 10;

    if (a1 + a2 + a3 == a4 + a5 + a6) 
        cout << 1;
    
    else 
        cout << 0;
    
    return 0;
}