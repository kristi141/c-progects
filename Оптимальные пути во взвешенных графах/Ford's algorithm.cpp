/*RU
Условие:
Дан ориентированный граф, в котором могут быть кратные ребра и петли. 
Каждое ребро имеет вес, выражающийся целым числом (возможно, отрицательным). 
Гарантируется, что циклы отрицательного веса отсутствуют. 
Необходимо найти длины кратчайших путей от вершины номер 1 до всех остальных. 
В решении необходимо использовать алгоритм Беллмана-Форда. 

Входные данные:
Программа получает сначала число N (1<=N<=100) – количество вершин графа и 
число M (0<=M<=10000) – количество ребер.  
В следующих строках идет M троек чисел, описывающих ребра: начало ребра, 
конец ребра и вес (вес – целое число от -100 до 100).

Выходные данные:
Программа должна вывести N чисел – расстояния от вершины номер 1 до всех 
вершин графа.  
Если пути до соответствующей вершины не существует, вместо длины пути 
выведите – «No».

Входные данные:
6 4
1 2 10
2 3 10
1 3 100
4 5 -10

Выходные данные:
0 10 20 No No No

ENG
Condition:
Given a directed graph that can have multiple edges and loops.
Each edge has a weight that is an integer (possibly negative).
It is guaranteed that there are no negative weight cycles.
It is necessary to find the lengths of the shortest paths from vertex number 
1 to all the others.
The solution must use the Bellman-Ford algorithm.

Input data:
The program first receives the number N (1<=N<=100) – the number of vertices 
of the graph and numberM(0<=M<=10000) – number of edges.
The following lines contain M triplets of numbers describing the edges: the 
beginning of the edge, edge end and weight 
(weight is an integer from -100 to 100).

Output:
The program should output N numbers – the distances from vertex number 1 to all
vertices of the graph.
If there is no path to the corresponding vertex, instead of the path length
output – “No”.

Input data:
6 4
1 2 10
2 3 10
1 3 100
4 5 -10

Output:
0 10 20 No No No                                       */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; 

struct edge { 
    int beginningOfGraphEdge, endOfGraphEdge, graphEdgeWeight;
};

vector<edge> edges;
int d[102]; 

int main() {
    int numberOfGraphVertices, numberOfGraphEdges;
    cin >> numberOfGraphVertices >> numberOfGraphEdges;

    for (int i = 1; i <= numberOfGraphVertices; i++) {
        d[i] = INF;
    }

    for (int i = 0; i < numberOfGraphEdges; i++) {
        int beginningOfGraphEdge, endOfGraphEdge, graphEdgeWeight; 
        cin >> beginningOfGraphEdge>> endOfGraphEdge >> graphEdgeWeight;
        edges.push_back({beginningOfGraphEdge, endOfGraphEdge, graphEdgeWeight}); 
    }

    d[1] = 0; 

    for (int i = 1; i < numberOfGraphVertices; i++) { 
        for (const auto& e : edges) { 
            if (d[e.beginningOfGraphEdge] < INF && d[e.beginningOfGraphEdge] + 
            e.graphEdgeWeight < d[e.endOfGraphEdge]) {
                d[e.endOfGraphEdge] = d[e.beginningOfGraphEdge] +
                e.graphEdgeWeight;
            }
        }
    }


    for (int i = 1; i <= numberOfGraphVertices; i++) {
        if (d[i] == INF) {
            cout << "No" << " ";
        } else {
            cout << d[i] << " ";
        }
    }

    return 0;
}