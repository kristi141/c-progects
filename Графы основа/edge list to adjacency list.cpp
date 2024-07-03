/*RU
Условие:
Некоторый граф задан списком ребер, выведите его представление в виде списка 
смежности. 

Входные данные:
На вход программы поступают числа n (1<=n<=100) – количество вершин в графе 
и m (1<=m<=n(n-1)/2) – количество ребер.  
Затем следует m пар чисел. Данные числа обозначают номера вершин, между 
которыми существует ребро.

Выходные данные:
Необходимо вывести список смежности заданного графа в формате: «i: a b c», 
где «i» – номер вершины, а «a b c» -номера смежных вершин через пробел. 
Номера вершин и смежных вершин должны идти в порядке возрастания

ENG
Condition:
Some graph is given a list of edges, output its representation as a list
adjacency.

Input data:
The program input receives numbers n (1<=n<=100) – the number of vertices in 
the graph and m (1<=m<=n(n-1)/2) – number of edges.
Then follows m pairs of numbers. These numbers indicate the numbers of 
vertices, between with which the edge exists.

Output:
It is necessary to display a list of adjacencies of a given graph in the 
format: “i: a b c”, where “i” is the number of the vertex, and “a b c” are 
the numbers of adjacent vertices separated by a space.
The numbers of vertices and adjacent vertices must be in ascending order*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        sort(adjacencyList[i].begin(), adjacencyList[i].end());
        
        for (int j : adjacencyList[i]){
          cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}