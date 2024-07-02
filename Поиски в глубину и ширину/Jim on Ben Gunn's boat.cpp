/*Условие:
Шхуна "Испаньола" оказалась в руках пиратов. Джим хочет захватить шхуну и 
отвести ее в укромную бухту.  Он без разрешения покидает форт, отыскивает 
принадлежащую Бену Ганну лодку и отправляется на "Испаньолу".  Джим знает, 
что на шхуне остались только два пирата, которые наверняка уже успели 
воспользоваться запасами рома, подраться и, как Джим почти уверен, уже не в 
состоянии оказать сопротивление.
Все это, конечно, замечательно, но до шхуны надо еще суметь доплыть на 
маленькой самодельной лодочке Бена Ганна. Бухта, где в одном углу стоит 
"Иcпаньола", а в противоположном углу спрятана лодка Бена Ганна, в изобилии 
содержит скалы и рифы. Поэтому проплыть бухту из конца в конец на утлой 
лодочке - задача очень сложная. К счастью, Бен Ганн снабдил Джима картой 
бухты. На клочке бумаги Бен Ганн нарисовал квадрат - план бухты. План Бен 
расчертил на маленькие квадратики, в каждом из которых он записал целое 
число, представляющее описание возможных направлений передвижения из этой 
клетки. Бумага, на которой нарисован план бухты, маленькая, поэтому описание 
направлений передвижения в каждой клетке представлено в компактной форме. 
Бен обозначил:
1 - направление вверх
2 - направление вниз
4 - направление вправо
8 - направление влево
Тогда число, описывающее клетку плана бухты, есть сумма чисел тех направлений, 
в которых можно безопасно плыть из этой клетки. Например, число 6 - клетка, 
из которой можно идти вниз и вправо, но нельзя в остальных направлениях. 
Бухта окружена береговой линией с трех сторон, а с четвертой стороны проходит 
сильное течение, которое унесет утлую лодочку в открытое море. Поэтому Джим 
не может выйти за пределы бухты и должен строго следовать плану Бена Ганна.
Джим изучает план и пытается определить, можно ли доплыть из той точки, где 
он находится, до той точки, где находится шхуна. На плане - это маршрут из 
левого верхнего угла в правый нижний. Помогите Джиму решить эту задачу.

Входные данные:
Входной файл в первой строке содержит единственное целое число N - размер 
стороны квадрата нарисованного Беном Ганном плана (2<=N<=1000).
Далее в файле содержатся N строк по N целых чисел, разделенных пробелами - 
описание клеток плана.

Выходные данные:
В выходной файл должно быть выведено слово "Yes", если пройти из левого 
верхнего угла в правый нижний можно, и "No" в противном случае.*/

#include <iostream>
#include <vector>
using namespace std;

struct Stack {
private:
    int* stackArr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        stackArr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] stackArr;
    }

    void push(int item) {
        if (top == capacity - 1) {
            return;
        }

        stackArr[++top] = item;
    }

    int pop() {
        if (top == -1) {
            return -1;
        }

        return stackArr[top--];
    }

    bool emptyCheck() const {
        return top == -1;
    }

    int valueReturn() const {
        if (top == -1) {
            return -1;
        }

        return stackArr[top];
    }
};

int cellCoordinates(int i, int j, int squareSideSize) {
    return i * squareSideSize + j;
}

void depthFirstSearch(int start, const vector<vector<int>>& graph, vector<bool>& visitedVertex, Stack& st) {
    st.push(start);

    while (!st.emptyCheck()) {
        int current = st.pop();

        if (visitedVertex[current]) {
            continue;
        }

        visitedVertex[current] = true;

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];

            if (!visitedVertex[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

bool pathExists(int squareSideSize, const vector<int>& st, const vector<vector<int>>& graph) {
    vector<bool> visitedVertex(squareSideSize * squareSideSize, false);
    Stack stack(squareSideSize * squareSideSize);

    depthFirstSearch(0, graph, visitedVertex, stack);

    return visitedVertex[squareSideSize * squareSideSize - 1];
}

int main() {
    int squareSideSize;
    cin >> squareSideSize;

    vector<int> st(squareSideSize * squareSideSize);
    vector<vector<int>> graph(squareSideSize * squareSideSize);

    for (int i = 0; i < squareSideSize; i++) {
        for (int j = 0; j < squareSideSize; j++) {
            int mapCells;
            cin >> mapCells;
            st[cellCoordinates(i, j, squareSideSize)] = mapCells;

            int index = cellCoordinates(i, j, squareSideSize);

            if ((mapCells & 8) && j > 0) 
            {
                graph[index].push_back(cellCoordinates(i, j - 1, squareSideSize));
            }
            if ((mapCells & 4) && j < squareSideSize - 1)
            {
                graph[index].push_back(cellCoordinates(i, j + 1, squareSideSize));
            }            
            if ((mapCells & 2) && i < squareSideSize - 1) 
            {
                graph[index].push_back(cellCoordinates(i + 1, j, squareSideSize));
            }
            if ((mapCells & 1) && i > 0) 
            {
                graph[index].push_back(cellCoordinates(i - 1, j, squareSideSize));
            }            

        }
    }

    if (pathExists(squareSideSize, st, graph)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}