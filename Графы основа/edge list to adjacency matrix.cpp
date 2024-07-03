/*RU
Условие:
Некоторый неориентрированный граф задан списком ребер, выведите его 
представление в виде матрицы смежности. 

Входные данные:
На вход программы поступают числа n (1<=n<=100) – количество вершин в графе 
и m (1<=m<=n(n-1)/2) – количество ребер.  
Затем следует m пар чисел. Данные числа обозначают номера вершин, между 
которыми существует ребро. 

Выходные данные:
Необходимо вывести матрицу смежности заданного графа.

Входные данные:
5 3 
1 3 
2 3 
2 5 

Выходные данные:
0 0 1 0 0 
0 0 1 0 1 
1 1 0 0 0 
0 0 0 0 0 
0 1 0 0 0 

ENG
Condition:
Some undirected graph is given a list of edges, print it
representation in the form of an adjacency matrix.

Input data:
The program input receives numbers n (1<=n<=100) – the number of vertices in 
the graph and m (1<=m<=n(n-1)/2) – number of edges.
Then follows m pairs of numbers. These numbers indicate the numbers of 
vertices, between with which the edge exists.

Output:
It is necessary to display the adjacency matrix of a given graph.

Input data:
5 3 
1 3 
2 3 
2 5 

Output:
0 0 1 0 0 
0 0 1 0 1 
1 1 0 0 0 
0 0 0 0 0 
0 1 0 0 0                   */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}