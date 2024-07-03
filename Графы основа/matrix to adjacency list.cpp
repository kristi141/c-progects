/*RU
Условие:
Некоторый граф задан матрицей смежности, выведите его представление в виде 
списка смежности.

Входные данные:
В первой строке входного файла дано число n (1<=n<=100) – количество вершин 
в графе. В каждой из следующих n строк даны  n чисел, каждое из которых равно 
0 или 1, - матрица смежности заданного графа (1 – означает наличие ребра, 
а 0 – его отсутствие).

Выходные данные:
Необходимо вывести список смежности заданного графа в формате: «i: a b c», 
где «i» – номер вершины, а «a b c» -номера смежных вершин через пробел

ENG
Condition:
A certain graph is given by an adjacency matrix; print its representation in 
the form adjacency list.

Input data:
The first line of the input file contains the number n (1<=n<=100) – the 
number of vertices in the graph. Each of the next n lines contains n numbers, 
each of which is equal to 0 or 1 is the adjacency matrix of a given graph 
(1 means the presence of an edge, and 0 – its absence).

Output:
It is necessary to display a list of adjacencies of a given graph in the 
format: “i: a b c”, where “i” is the number of the vertex, and “a b c” are 
the numbers of adjacent vertices separated by a space*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i <= n; i++)
        graph[i] = vector<int>();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int value;
            cin >> value;
            if (value == 1)
                graph[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (int j = 0; j < graph[i].size(); j++)
            cout << " " << graph[i][j];
        cout << endl;
    }

    return 0;
}