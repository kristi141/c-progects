/*Условие:
Дан неориентированный невзвешенный граф.
Необходимо посчитать количество его компонентов связности и вывести их.

Входные данные:
Во входном файле записано значение N (1<=N<=100) – количество вершин  
данного графа.
Далее дана матрица смежности данного графа, в которой 0 означает отсутствие 
ребра между вершинами, а 1 – его наличие.

Выходные данные:
В первой строке выходного файла выведите количество компонентов связности.
Далее в каждой новой строке в порядке возрастания наименьшей вершины в 
компоненте связности выведите размер компонента связности, а затем и сам 
компонент связности.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100]; 
bool used[100] = {}; 

void depthFirstSearch(int vertex, vector<int>& component, int N)
{
    used[vertex] = true;
    component.push_back(vertex);
    for (int i = 0; i < N; i++)
    {
        if (!used[i] && graph[vertex][i]) {
            depthFirstSearch(i, component, N);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> components(N);

    for (int i = 0; i < N; i++) {
        graph[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) { 
            vector<int> component;

            depthFirstSearch(i, component, N);
            components.push_back(component);
        }
    }

    components.erase(remove_if(components.begin(), components.end(), 
    [](const vector<int>& v){ return v.empty(); }), components.end());

    for (auto &component : components) {
        sort(component.begin(), component.end());
    }

    sort(components.begin(), components.end(),
        [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front();
        });

    cout << components.size() << endl;
    for (auto &component : components) {
        cout << component.size() << " ";
        for (int vertex : component) {
            cout << vertex + 1 << " "; 
        }
        cout << endl;
    }

    return 0;
}