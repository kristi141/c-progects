/*RU
Условие:
Некоторый граф задан матрицей смежности, выведите его представление в виде 
списка ребер. 

Входные данные:
В первой строке входного файла дано число n (1<=n<=100) – количество вершин в 
графе. В каждой из следующих n строк даны  n чисел, каждое из которых равно 0 
или 1, - матрица смежности заданного графа (1 – означает наличие ребра, 
а 0 – его отсутствие).

Выходные данные:
Необходимо вывести список ребер заданного графа.

ENG
Condition:
A certain graph is given by an adjacency matrix; print its representation in 
the form list of edges.

Input data:
The first line of the input file contains the number n (1<=n<=100) – the 
number of vertices in graph. Each of the next n lines contains n numbers, 
each of which is 0 or 1,- adjacency matrix of a given graph (1 means the 
presence of an edge, and 0 – its absence).

Output:
It is necessary to display a list of edges of a given graph.*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int value;
            cin >> value;
            
            if(value > 0)
            {
               cout << i  << " " << j << endl;
            }
        }
    }

    return 0;
}