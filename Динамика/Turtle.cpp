/*RU
Условие:
В левом верхнем углу прямоугольной поляны размером n*m находится черепашка. 
На каждой клетке поля разлито некоторое количество кислоты. Черепашка может 
перемещаться только вправо или вниз, при этом маршрут черепашки заканчивается 
в правом нижнем углу таблицы. Каждый миллилитр кислоты приносит черепашке 
некоторое количество урона.  
Необходимо найти наименьшее возможное значение урона, которое получит 
черепашка после прогулки по поляне.
На данном изображении указан маршрут Черепашки. Минимальный урон, который 
она получит – 7. 

Входные данные:
В первой строке записаны два натуральных числа: n, m (1<=n, m<=1000) - 
размеры поляны.  
Каждая из следующих n строк содержит m чисел, разделённых пробелами - 
описание поляны с указанием для каждой клетки содержания кислоты на ней 
(в миллилитрах).

Выходные данные:
В первой строке входного файла должно быть выведено единственное значение – 
наименьшую возможную стоимость маршрута черепашки.

ENG
Condition:
There is a turtle in the upper left corner of a rectangular clearing of size 
n*m. A certain amount of acid is spilled on each square of the field. The 
turtle can move only to the right or down, and the turtle's route ends
in the lower right corner of the table. Every milliliter of acid brings a 
turtle some amount of damage.
It is necessary to find the smallest possible value of damage that will be 
received turtle after a walk in the clearing.
This image shows the Turtle's route. The minimum damage that
she will get - 7.

Input data:
The first line contains two natural numbers: n, m (1<=n, m<=1000)-
dimensions of the clearing.
Each of the next n lines contains m numbers separated by spaces -
description of the clearing indicating for each cell the acid content on it
(in milliliters).

Output:
The first line of the input file should contain a single value -
the lowest possible cost for the turtle's route.*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long amountAcid[1000][1000];
    long long column, line;
    cin >> column >> line;

    for (long long i = 0; i < column; ++i) {
        for (long long j = 0; j < line; ++j) {
            cin >> amountAcid[i][j];
        }
    }

    for (long long i = 1; i < line; ++i) {
        amountAcid[0][i] += amountAcid[0][i - 1];
    }

    for (long long i = 1; i < column; ++i) {
        amountAcid[i][0] += amountAcid[i - 1][0];

        for (long long j = 1; j < line; ++j) {
            amountAcid[i][j] += min(amountAcid[i - 1][j], amountAcid[i][j - 1]);
        }
    }

    cout << amountAcid[column - 1][line - 1] << endl;
    vector<char> path;
    path.reserve(column + line - 2);

    return 0;
}