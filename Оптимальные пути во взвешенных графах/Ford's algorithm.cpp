/*Условие:
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
выведите – «No».*/

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