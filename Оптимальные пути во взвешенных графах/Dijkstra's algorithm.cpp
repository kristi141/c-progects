/*RU
Условие:
Дан ориентированный взвешенный граф.  
Необходимо найти кратчайшее расстояние от одной заданной вершины до другой, 
используя алгоритм Дейкстры.

Входные данные:
В первой строке содержатся три числа: N, S и F (1 <=N <=100, 1<=S, F<=N), 
где N – количество вершин графа, S – начальная вершина, а F – конечная.  
В следующих N строках вводится по N чисел, не превосходящих 100, – 
матрица смежности графа, где -1 означает отсутствие ребра между вершинами, 
а любое неотрицательное число – наличие ребра данного веса. 

Выходные данные:
Необходимо вывести единственное значение - искомое расстояние или -1, если 
пути между указанными вершинами не существует.

ENG
Condition:
Given a directed weighted graph.
It is necessary to find the shortest distance from one given vertex to another,
using Dijkstra's algorithm.

Input data:
The first line contains three numbers: N, S and F (1 <=N <=100, 1<=S, F<=N),
where N is the number of vertices of the graph, S is the initial vertex, and 
F is the final vertex.
In the next N lines, enter N numbers not exceeding 100, –
adjacency matrix of the graph, where -1 means there is no edge between the vertices,
and any non-negative number means the presence of an edge of a given weight.

Output:
It is necessary to display a single value - the required distance or -1 if
there is no path between the specified vertices.*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int numberOfGraphVertices, initialVertex, terminalVertex;
    cin >> numberOfGraphVertices >> initialVertex >> terminalVertex;

    vector<vector<int>> graph(numberOfGraphVertices,
    vector<int>(numberOfGraphVertices)); 
    vector<int> distances(numberOfGraphVertices, INT_MAX ); 
    vector<bool> visitedVertices(numberOfGraphVertices, false); 

    initialVertex--; 
    terminalVertex--;

    for(int i = 0; i < numberOfGraphVertices; i++) {
        for(int j = 0; j < numberOfGraphVertices; j++) {
            int weight;
            cin >> weight;
            if(weight == -1) graph[i][j] = INT_MAX ; 
            else graph[i][j] = weight; 
        }
    }

    distances[initialVertex] = 0;

    for (int i = 0; i < numberOfGraphVertices; i++) {
        int minIndex = -1;
        for (int j = 0; j < numberOfGraphVertices; j++) {
            if (!visitedVertices[j] && (minIndex == -1 ||
            distances[j] < distances[minIndex])) {
                minIndex = j;
            }
        }
        if (distances[minIndex] == INT_MAX ){
          break;
        }  
        
        for (int j = 0; j < numberOfGraphVertices; j++) {
            if (graph[minIndex][j] != INT_MAX ) {
                int temp = distances[minIndex] + graph[minIndex][j];
                
                if (temp < distances[j]) {
                    distances[j] = temp;
                }
            }
        }

        visitedVertices[minIndex] = true; 
    }

    if (distances[terminalVertex] == INT_MAX ) cout << -1 << endl;
    else cout << distances[terminalVertex] << endl;

    return 0;
}