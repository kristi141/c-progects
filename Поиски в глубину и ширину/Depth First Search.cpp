/*Условие:
Дан неориентированный невзвешенный граф.
Необходимо найти вершины, лежащие в одной компоненте связности с данной 
вершиной (считая эту вершину).
В решении необходимо применить алгоритм поиска в глубину.

Входные данные:
Во входном файле записано значение N (1<=N<=100) – количество вершин 
данного графа.
В следующей строке входного файла дан номер вершины, для которой необходимо 
найти все вершины, лежащие с данной в одном компоненте связности.
Далее дана матрица смежности данного графа, в которой 0 означает отсутствие 
ребра между вершинами, а 1 – его наличие.

Выходные данные:
Выведите получившийся компонент связности*/

#include <iostream>
#include <vector>
using namespace std;

void depthFirstSearch(vector<vector<int>>& graph, int vertex, 
vector<bool>& visited, vector<int>& component) {
  
    visited[vertex] = true;
    component.push_back(vertex);

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            depthFirstSearch(graph, neighbor, visited, component);
        }
    }
}

int main() {
    int n,startVertex;
    cin >> n >> startVertex;
    
    startVertex--;

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> component;

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

    depthFirstSearch(graph, startVertex, visited, component);

    for (int vertex : component) {
        cout << vertex + 1 << " ";
    }

    return 0;
}