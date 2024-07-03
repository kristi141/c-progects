/*RU
Условие:
Дан неориентированный граф.
Необходимо найти оптимальный путь по числу переходов между двумя вершинами.

Входные данные:
Во входном файле дано значение: N (1<=N<=100) – количество вершин графа.
Далее дана матрица смежности данного графа, в которой 0 означает отсутствие 
ребра между вершинами, а 1 – его наличие.
Далее задаются номера двух вершин – начальной и конечной.

Выходные данные:
Необходимо вывести оптимальный путь по числу переходов  (количество 
переходов, которое необходимо сделать), а затем сам путь.
Необходимо вывести путь (номера всех вершин в правильном порядке). Если пути 
нет, нужно вывести -1.

ENG
Condition:
Given an undirected graph.
It is necessary to find the optimal path based on the number of transitions 
between two vertices.

Input data:
The input file contains the following value: N (1<=N<=100) – the number of 
graph vertices.
The following is the adjacency matrix of this graph, in which 0 means the absence
edges between vertices, and 1 – its presence.
Next, the numbers of two vertices are specified - the initial and final ones.

Output:
It is necessary to derive the optimal path based on the number of transitions 
(number transitions that need to be made), and then the path itself.
It is necessary to print the path (the numbers of all vertices in the correct 
order). If the path no, you need to output -1.*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> breadthfirstsearch(vector<vector<int>>& graph, int startvertex, int endvertex) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(startvertex);

    visited[startvertex] = true;
    distance[startvertex] = 0;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (vertex == endvertex) {
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

    if (distance[endvertex] == -1) {
        return vector<int>();
    }

    vector<int> path;
    int currentvertex = endvertex;

    while (currentvertex != -1) {
        path.push_back(currentvertex);
        currentvertex = parent[currentvertex];
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

    int startvertex, endvertex;
    cin >> startvertex >> endvertex;

    startvertex--;
    endvertex--;

    vector<int> path = breadthfirstsearch(graph, startvertex, endvertex);

    if (path.empty()) { 
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