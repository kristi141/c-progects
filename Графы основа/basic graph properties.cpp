/*Условие:
Дан граф.
Необходимо проверить следующие свойства данного графа:
определенность: граф называется определенным, если  хотя бы у одного из его 
ребер задано направление;
взвешенность: граф называется взвешенным, если есть величина, характеризующая 
связь между его ребрами (в данной задаче граф будет обладать данным 
свойством, если хотя бы одно из его ребер обладает весом, отличающимся от 0 и 1);
транзитивность: граф называется транзитивным, если всегда из того, что 
вершины a и b соединены ребром и вершины b и c соединены ребром следует, 
что вершины a и c соединены ребром;
полнота: граф, в котором каждая пара различных вершин смежная.

Входные данные:
На вход программы поступает число n (1<=n<=100) – количество вершин в графе.
Затем поступает матрица смежности данного графа. 

Выходные данные:
В выходной файл должно быть выведено четыре значения (каждое значение должно 
быть выведено в новой строке): если граф обладает данным свойством выведите 1, 
в противном случае выведите -1.  

Первая строка – свойство определенности, вторая строка – свойство взвешенности, 
третья строка – свойство транзитивности, четвертая строка – свойство полноты.*/

#include <iostream> 
using namespace std; 
 
bool hasNonZeroElement(int** adjacencyMatrix, int vertices) 
{ 
    for (int i = 0; i < vertices; i++) 
    { 
        for (int j = 0; j < vertices; j++) 
        { 
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) 
               return true; 
        } 
    } 
    return false; 
} 
 
bool hasWeightedElement(int** adjacencyMatrix, int vertices) 
{ 
    for (int i = 0; i < vertices; i++) 
    { 
        for (int j = 0; j < vertices; j++) 
        { 
            if (adjacencyMatrix[i][j] != 1  && adjacencyMatrix[i][j] != 0) 
            { 
                return true; 
            } 
        } 
    } 
    return false; 
} 
 
 
bool transitive(int** adjacencyMatrix, int vertices) { 
    for (int i = 0; i < vertices; i++) 
    { 
        for (int j = 0; j < vertices; j++) 
        { 
            if (adjacencyMatrix[i][j] != 0) 
            { 
                for (int p = 0; p < vertices; p++) 
                { 
                    if (i != p && adjacencyMatrix[i][p] == 0 && adjacencyMatrix[j][p] != 0) 
                    { 
                        return false; 
                    } 
                } 
            } 
        } 
    } 
    return true; 
} 
 
bool complete(int** adjacencyMatrix, int vertices) 
{ 
    for (int i = 0; i < vertices; ++i) { 
        for (int j = 0; j < vertices; ++j) { 
            if (i != j && adjacencyMatrix[i][j] == 0) { 
                return false; 
            } 
        } 
    } 
    return true; 
} 
 
 
int main() 
{ 
    int n; 
    cin >> n; 

    int** adjacencyMatrix = new int*[n]; 
    for (int i = 0; i < n; i++) { 
        adjacencyMatrix[i] = new int[n]; 
        for (int j = 0; j < n; j++) { 
            cin >> adjacencyMatrix[i][j]; 
        } 
    } 

    bool definiteness = hasNonZeroElement(adjacencyMatrix, n);
    bool weighted = hasWeightedElement(adjacencyMatrix, n);
    bool transitivity = transitive(adjacencyMatrix, n);
    bool completeness = complete(adjacencyMatrix, n);

    cout << (definiteness ? 1 : -1) << endl;
    cout << (weighted ? 1 : -1) << endl;
    cout << (transitivity ? 1 : -1) << endl;
    cout << (completeness ? 1 : -1) << endl;

    return 0; 
}