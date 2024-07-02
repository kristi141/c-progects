/*Условие:
Дан взвешенный неориентированный граф с n вершинами. 
Необходимо найти и построить минимальное остовное дерево, используя алгоритм 
Прима.
Минимальное остовное дерево (минимальный остов) - поддерево данного графа, 
которое бы соединяло все его вершины, и при этом обладало наименьшим 
возможным весом (т.е. суммой весов рёбер). Любой остов обязательно будет 
содержать n-1 ребро.
Поддерево — это набор рёбер, соединяющих все вершины, причём из любой 
вершины можно добраться до любой другой ровно одним простым путём.

Входные данные:
В первой строке входного файла дано значение n – количество вершин графа 
(1<=n<=100).
Далее дана матрица смежности данного графа.

Выходные данные:
В первой строке входного файла должно быть выведено единственное значение – 
длина минимального остовного дерева.
Начиная со следующей строки необходимо вывести матрицу смежности минимального 
остова.*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int findMinEdge(const vector<int>& edge, const vector<bool>& 
minimumSpanningTreeAdjacencyMatrixSet, int numberOfGraphVertices) {
    int minEdge = INF;
    int minIndex = -1;

    for (int vertex = 0; vertex < numberOfGraphVertices; ++vertex) {
        if (!minimumSpanningTreeAdjacencyMatrixSet[vertex] && edge[vertex] < minEdge) {
            minEdge = edge[vertex];
            minIndex = vertex;
        }
    }

    return minIndex;
}

void printMinimumSpanningTreeAdjacencyMatrix(const vector<vector<int>>& 
minimumSpanningTreeAdjacencyMatrix, int numberOfGraphVertices) {
    for (int i = 0; i < numberOfGraphVertices; ++i) {
        for (int j = 0; j < numberOfGraphVertices; ++j) {
            cout << minimumSpanningTreeAdjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void primMinimumSpanningTreeAdjacencyMatrix(const vector<vector<int>>& graph, 
int numberOfGraphVertices) {
    vector<int> parent(numberOfGraphVertices, -1);
    vector<int> edge(numberOfGraphVertices, INF);
    vector<bool> minimumSpanningTreeAdjacencyMatrixSet(numberOfGraphVertices, false);
    vector<vector<int>> minimumSpanningTreeAdjacencyMatrix(numberOfGraphVertices, 
    vector<int>(numberOfGraphVertices, 0));

    edge[0] = 0;

    for (int count = 0; count < numberOfGraphVertices - 1; ++count) {
        int point = findMinEdge(edge, minimumSpanningTreeAdjacencyMatrixSet,
        numberOfGraphVertices);
        minimumSpanningTreeAdjacencyMatrixSet[point] = true;

        for (int vertex = 0; vertex < numberOfGraphVertices; ++vertex) {
            if (graph[point][vertex] && 
            !minimumSpanningTreeAdjacencyMatrixSet[vertex] &&
            graph[point][vertex] < edge[vertex]) {
                parent[vertex] = point;
                edge[vertex] = graph[point][vertex];
            }
        }
    }

    for (int i = 1; i < numberOfGraphVertices; ++i) {
        minimumSpanningTreeAdjacencyMatrix[i][parent[i]] =
        minimumSpanningTreeAdjacencyMatrix[parent[i]][i] = edge[i];
    }

    int weight = 0;
    for (int i = 0; i < numberOfGraphVertices; ++i) {
        weight += edge[i];
    }

    cout << weight << endl;
    printMinimumSpanningTreeAdjacencyMatrix(minimumSpanningTreeAdjacencyMatrix, 
    numberOfGraphVertices);
}

int main() {
    int numberOfGraphVertices;
    cin >> numberOfGraphVertices;

    vector<vector<int>> graph(numberOfGraphVertices, 
    vector<int>(numberOfGraphVertices));

    for (int i = 0; i < numberOfGraphVertices; ++i) {
        for (int j = 0; j < numberOfGraphVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    primMinimumSpanningTreeAdjacencyMatrix(graph, numberOfGraphVertices);

    return 0;
}