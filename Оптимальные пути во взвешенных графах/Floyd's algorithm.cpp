/*Условие:
Дан ориентированный взвешенный граф, рёбрам которого приписаны некоторые 
неотрицательные веса (длины).  
Необходимо найти длину кратчайшего пути из вершины s в вершину t, используя 
алгоритм Флойда.

Входные данные:
В первой строке заданы три значения: N - число вершин в графе (N<=50), номера 
вершин s и t.  
Далее идёт матрица смежности графа, то есть N строк, в каждой из которых 
записано N чисел. j-ое число в i-ой строке матрицы смежности задает длину 
ребра, ведущего из i-й вершину в j-ую. Длины могут принимать любые значения 
от 0 до 1000000, число -1 означает отсутствие соответствующего ребра. 

Выходные данные:
Необходимо вывести единственное значение - минимальную длину пути. Если пути 
не существует, выведите -1*/

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000001
using namespace std;

void algorithmFloydWarshall(vector<vector<int>>& matrix) {
    int numberOfVert = matrix.size();
    for(int k = 0; k < numberOfVert; k++) {
        for(int i = 0; i < numberOfVert; i++) {
            for(int j = 0; j < numberOfVert; j++) {
                if (matrix[i][k] < INF && matrix[k][j] < INF) {
                    matrix[i][j] = min(matrix[i][j], 
                    matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int weight : row) {
            if(weight == INF) {
                cout << "-1";
            } else {
                cout << weight << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int numberOfVerticesInTheGraph, vertexNumberedS, vertexNumberedT;
    cin >> numberOfVerticesInTheGraph >> vertexNumberedS >> vertexNumberedT;

    vector<vector<int>> matrix(numberOfVerticesInTheGraph, 
    vector<int>(numberOfVerticesInTheGraph, INF));

    for(int i = 0; i < numberOfVerticesInTheGraph; i++) {
        for(int j = 0; j < numberOfVerticesInTheGraph; j++) {
            int weight;
            cin >> weight;
            if(weight == -1 || i == j){
                matrix[i][j] = (i == j) ? 0 : INF;
            } else {
                matrix[i][j] = weight;
            }
        }
    }

    algorithmFloydWarshall(matrix);

    int shortestPath = matrix[vertexNumberedS - 1][vertexNumberedT - 1]; 
    cout << (shortestPath == INF ? -1 : shortestPath) << endl;

    return 0;
}