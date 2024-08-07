/*RU
Условие:
Дан взвешенный неориентированный граф с n вершинами. 
Необходимо найти и построить минимальное остовное дерево, используя алгоритм 
Краскала.
Минимальное остовное дерево (минимальный остов) - поддерево данного графа, 
которое бы соединяло все его вершины, и при этом обладало наименьшим возможным 
весом (т.е. суммой весов рёбер). Любой остов обязательно будет содержать 
n-1 ребро.
Поддерево — это набор рёбер, соединяющих все вершины, причём из любой вершины 
можно добраться до любой другой ровно одним простым путём.

Входные данные:
В первой строке входного файла даны два значения n – количество вершин графа 
(1<=n<=100), m – количество ребер данного графа (1<=m<=n*(n-1)).
Далее даны m строк, в каждой из которой записаны по три числа – список ребер 
данной матрицы (первые два числа – вершины, между которыми существует ребро, 
третье число – вес данного ребра).

Выходные данные:
В первой строке входного файла должно быть выведено единственное значение – 
длина минимального остовного дерева.
Начиная со следующей строки необходимо вывести матрицу смежности минимального 
остова.

Входные данные:
4 8
1 2 723
2 1 723
2 3 137
2 4 470
3 2 137
3 4 69
4 2 470
4 3 69

Выходные данные:
929
0 723 0 0
723 0 137 0
0 137 0 69
0 0 69 0

ENG
Condition:
Given a weighted undirected graph with n vertices.
It is necessary to find and build a minimum spanning tree using the algorithm
Painted.
Minimum spanning tree (minimum spanning tree) - a subtree of a given graph,
which would connect all its vertices, and at the same time have the smallest possible
weight (i.e. the sum of the weights of the edges). Any skeleton will necessarily contain
n-1 edge.
A subtree is a set of edges connecting all vertices, from any vertex
you can get to any other in exactly one simple way.

Input data:
The first line of the input file contains two values ​​n - the number of vertices of the graph
(1<=n<=100), m – number of edges of this graph (1<=m<=n*(n-1)).
Next are m lines, each of which contains three numbers - a list of edges
of this matrix (the first two numbers are the vertices between which there is an edge,
the third number is the weight of this edge).

Output:
The first line of the input file should contain a single value -
length of the minimum spanning tree.
Starting from the next line, you need to print the adjacency matrix of the minimum
skeleton

Input data:
4 8
1 2 723
2 1 723
2 3 137
2 4 470
3 2 137
3 4 69
4 2 470
4 3 69

Output:
929
0 723 0 0
723 0 137 0
0 137 0 69
0 0 69 0                              */

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int firstVertex; 
    int secondVertex;
    int weight;
};

bool compareEdges(const Edge& firstEdgeOfTree, const Edge& secondEdgeOfTree) {
    return firstEdgeOfTree.weight < secondEdgeOfTree.weight;
}

struct kruskalsAlgorithm {
private:
    int numberOfGraphVertices; 
    vector<Edge> edges; 
    vector<int> parent; 

public:
    kruskalsAlgorithm(int vertices) : numberOfGraphVertices(vertices) {
        parent.resize(numberOfGraphVertices);
        for (int i = 0; i < numberOfGraphVertices; ++i) {
            parent[i] = i; 
        }
    }

    void addEdge(int firstVertex, int secondVertex, int weight) {
        edges.push_back({ firstVertex, secondVertex, weight });
    }

    int find(int vertex) {
        if (parent[vertex] == vertex) {
            return vertex;
        }
        return parent[vertex] = find(parent[vertex]);
    }

    void unite(int firstVertex, int secondVertex) {
        int rootOfFirstVertex = find(firstVertex);
        int rootOfSecondVertex = find(secondVertex);
        parent[rootOfFirstVertex] = rootOfSecondVertex; 
    }

    void manualSort() {
        for (int i = 0; i < edges.size(); ++i) {
            for (int j = 0; j < edges.size() - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    swap(edges[j], edges[j + 1]);
                }
            }
        }
    }

    void kruskal() {
        manualSort(); 
        vector<Edge> result; 

        for (const Edge& edge : edges) {
            int rootU = find(edge.firstVertex);
            int rootV = find(edge.secondVertex);

            if (rootU != rootV) {
                result.push_back(edge);
                unite(edge.firstVertex, edge.secondVertex);
            }
        }

        int totalWeight = 0;
        for (const Edge& edge : result) {
            totalWeight += edge.weight;
        }

        cout << totalWeight << endl;
        vector<vector<int>> adjacencyMatrix(numberOfGraphVertices, vector<int>(numberOfGraphVertices, 0));
        for (const Edge& edge : result) {
            adjacencyMatrix[edge.firstVertex][edge.secondVertex] = edge.weight;
            adjacencyMatrix[edge.secondVertex][edge.firstVertex] = edge.weight;
        }

        for (int i = 0; i < numberOfGraphVertices; ++i) {
            for (int j = 0; j < numberOfGraphVertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numberOfGraphVertices, numberOfEdgesOfThisGraph;
    cin >> numberOfGraphVertices >> numberOfEdgesOfThisGraph;

    kruskalsAlgorithm kruskalsAlgorithm(numberOfGraphVertices);

    for (int i = 0; i < numberOfEdgesOfThisGraph; ++i) {
        int oneVertex, twoVertex, weight;
        cin >> oneVertex >> twoVertex >> weight;
        kruskalsAlgorithm.addEdge(oneVertex - 1, twoVertex - 1, weight); 
    }

    kruskalsAlgorithm.kruskal();

    return 0;
}