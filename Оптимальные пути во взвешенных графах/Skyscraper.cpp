/*Условие:
В богатом районе города P стоит n-этажный небоскреб. Все бы ничего, но лифты 
этого здания строили известные герои Равшан и Джамшут, именно поэтому они 
ездят очень странно. Грузчикам нужно перенести очень тяжелую скульптуру с 
одного этажа на другой. При подъеме статуи на определенный этаж из уст 
грузчиков вырываются не очень красивые слова. Жители этого дома - очень 
культурные люди, которые не привыкли к подобным выражениям. Помогите 
грузчикам перенести статую так, чтобы количество произнесенных некрасивых 
слов было наименьшим.

Входные данные:
В первой строке входного файла даны три значения: n – количество этажей в 
небоскребе (1<=n<=1000), m – количество лифтов в данном небоскрёбе 
(1<=m<=100) и с – количество слов, которые произносят грузчики, проходя 
один этаж по лестнице.
Во второй строке входного файла даны два значения: номер этажа, с которого 
нужно переместить статую, и номер этажа, на который нужно доставить статую.
В следующих m строках даны по три значения: номер этажа, с которого едет лифт, 
номер этажа, на который едет данный лифт, а также стоимость перемещения на 
данном лифте (количество слов, которые произнесут грузчики,пока будут ехать 
на лифте).
Известно, что лифт не останавливается между указанными этажами, а едет строго 
c этажа на этаж (лифты перемещается в обе стороны).

Выходные данные:
В выходной файл должно быть выведено единственное значение – наименьшее 
количество слов, которые произнесут грузчики*/

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int INT_MAX = pow(10, 9) + 7;

int minimalDistance(int numberOfFloorsInSkyscraper, int distance[],
bool isIncluded[]) {
    int minimum = INT_MAX;
    int minimalIndex;

    for (int v = 0; v < numberOfFloorsInSkyscraper; v++) {
        if (distance[v] <= minimum && isIncluded[v] == false) {
            minimum = distance[v];
            minimalIndex = v;
        }
    }

    return minimalIndex;
}

void algorithmOfDijkstra(int numberOfFloorsInSkyscraper, 
vector<vector<int>>& graph, int groundFloor, int finalFloor) {
    int distance[numberOfFloorsInSkyscraper];
    bool isIncluded[numberOfFloorsInSkyscraper];

    for (int i = 0; i < numberOfFloorsInSkyscraper; i++) {
        distance[i] = INT_MAX;
        isIncluded[i] = false;
    }

    distance[groundFloor] = 0;

    for (int count = 0; count < numberOfFloorsInSkyscraper - 1; count++) {
        int u = minimalDistance(numberOfFloorsInSkyscraper, distance, 
        isIncluded);

        isIncluded[u] = true;

        for (int v = 0; v < numberOfFloorsInSkyscraper; v++) {
            if (graph[u][v] && !isIncluded[v]
                && distance[u] + graph[u][v] < distance[v]
                && distance[u] != INT_MAX)
                distance[v] = distance[u] + graph[u][v];
        }
    }
    cout << distance[finalFloor] << endl;
}

void processSkyscraper(int numberOfFloorsInSkyscraper, int numberOfElevators,
int numberOfNotVeryBeautifulWords, int groundFloor, int finalFloor) {
    if (numberOfNotVeryBeautifulWords == 0) {
        cout << "0" << endl;
        return;
    }

    groundFloor -= 1;
    finalFloor -= 1;
    vector<vector<int>> adjacencyMatrix(numberOfFloorsInSkyscraper, 
    vector<int>(numberOfFloorsInSkyscraper, 0));

    for (int i = 0; i < numberOfElevators; i++) {
        int first, seconds, badWords;
        cin >> first >> seconds >> badWords;
        adjacencyMatrix[first - 1][seconds - 1] = badWords;
        adjacencyMatrix[seconds - 1][first - 1] = badWords;
    }

    for (int i = 0; i < numberOfFloorsInSkyscraper; i++) {
        for (int j = 0; j < numberOfFloorsInSkyscraper; j++) {
            if (i != j) {
                if (adjacencyMatrix[i][j] != 0) {
                    adjacencyMatrix[j][i] = min(abs(i - j) * 
                    numberOfNotVeryBeautifulWords, adjacencyMatrix[j][i]);
                    adjacencyMatrix[i][j] = min(abs(i - j) *
                    numberOfNotVeryBeautifulWords, adjacencyMatrix[i][j]);
                }
                else {
                    adjacencyMatrix[j][i] = numberOfNotVeryBeautifulWords * 
                    abs(i - j);
                    adjacencyMatrix[i][j] = numberOfNotVeryBeautifulWords * 
                    abs(i - j);
                }
            }
        }
    }

    algorithmOfDijkstra(numberOfFloorsInSkyscraper, adjacencyMatrix, 
    groundFloor, finalFloor);
}

int main() {
    int numberOfFloorsInSkyscraper, numberOfElevators, 
    numberOfNotVeryBeautifulWords;
    cin >> numberOfFloorsInSkyscraper >> numberOfElevators
    >> numberOfNotVeryBeautifulWords;

    int groundFloor, finalFloor;
    cin >> groundFloor >> finalFloor;

    processSkyscraper(numberOfFloorsInSkyscraper, numberOfElevators, 
    numberOfNotVeryBeautifulWords, groundFloor, finalFloor);

    return 0;
}