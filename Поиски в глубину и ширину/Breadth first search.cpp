/*RU
Условие:
Дан неориентированный граф.
Необходимо найти минимальный путь между двумя вершинами.
В решении необходимо применить алгоритм поиска в ширину.

Входные данные:
Во входном файле  дано значение: N (1<=N<=100) – количество вершин графа.
Далее дана матрица смежности данного графа, в которой 0 означает отсутствие 
ребра между вершинами, а 1 – его наличие.
Далее задаются номера двух вершин – начальной и конечной.

Выходные данные:
Необходимо вывести сначала длину кратчайшего пути (количество ребер, которые 
нужно пройти), а потом сам путь.
Если путь имеет длину 0, то его выводить не нужно, достаточно вывести длину.
Необходимо вывести путь (номера всех вершин в правильном порядке). 
Если пути нет, нужно вывести -1.

ENG
Condition:
Given an undirected graph.
It is necessary to find the minimum path between two vertices.
The solution requires applying a breadth-first search algorithm.

Input data:
The input file contains the following value: N (1<=N<=100) – the number of 
graph vertices. The following is the adjacency matrix of this graph, in 
which 0 means the absence edges between vertices, and 1 – its presence.
Next, the numbers of two vertices are specified - the initial and final ones.

Output:
You must first display the length of the shortest path (the number of edges that
need to go through), and then the path itself.
If the path has length 0, then there is no need to print it, it is enough 
to print the length. It is necessary to print the path (the numbers of all 
vertices in the correct order).
If there is no path, you need to print -1.*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> breadthFirstSearch(vector<vector<int>>& graph, 
int startVertex, int endVertex) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(startVertex);

    visited[startVertex] = true;
    distance[startVertex] = 0;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (vertex == endVertex) {
            break;
        }

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                distance[neighbor] = distance[vertex] + 1;
                parent[neighbor] = vertex;
            }
        }
    }

    if (distance[endVertex] == -1) {
        return vector<int>();
    }

    vector<int> path;
    int currentVertex = endVertex;

    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = parent[currentVertex];
    }

    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int edge;
            cin >> edge;

            if (edge == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    startVertex--;
    endVertex--;

    vector<int> path = breadthFirstSearch(graph, startVertex, endVertex);

    if (path[0] == -1) { 
     cout << -1 << endl; 
    } else { 
     if (path.size() - 1 == 0) { 
        cout << 0 << endl; 
    } else { 
        cout << path.size() - 1 << endl; 
         for (int i = 0; i < path.size(); ++i) { 
            cout << path[i] + 1 << " "; 
           } 
        cout << endl; 
    } 
}
        cout << endl;
    
    return 0;
}