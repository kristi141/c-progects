/*RU
Условие:
Дан список чисел и некоторые значения x и y из данного списка.
Необходимо поменять элементы x и y местами. 
В решении необходимо использовать связные списки.

Входные данные:
Во входном файле дан список чисел, а затем элементы, которые надо поменять 
местами.

Выходные данные:
В выходной файл должен быть выведен список чисел.

ENG
Condition:
Given a list of numbers and some x and y values ​​from the given list.
It is necessary to swap the elements x and y.
The solution must use linked lists.

Input data:
The input file contains a list of numbers, and then the elements that need 
to be changed in some places.

Output:
The output file should contain a list of numbers.*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;

    Node* next;
    Node* prev;

    Node(int value, Node* prev = nullptr, Node* next = nullptr) :
        value(value), prev(prev), next(next) {}
};

struct List {
    Node* first;
    Node* last;

    int size;

    List() : first(nullptr), last(nullptr), size(0) {}

    bool empty() {
        return first == nullptr;
    }

    void pushBack(int value) {
        Node* p = new Node(value);

        if (empty()) {
            first = p;
            last = p;
        }
        else {
            p->prev = last;
            last->next = p;
            last = p;
        }

        size++;
    }

    void Change(int firstElemForChange, int secondElemForChange) {
        if (firstElemForChange == secondElemForChange) {
            return;
        }

        Node* firstCurr = first;
        Node* secondCurr = first;
        Node* firstPrev = nullptr;
        Node* secondPrev = nullptr;

        while (firstCurr && firstCurr->value != firstElemForChange) {
            firstPrev = firstCurr;
            firstCurr = firstCurr->next;
        }

        while (secondCurr && secondCurr->value != secondElemForChange) {
            secondPrev = secondCurr;
            secondCurr = secondCurr->next;
        }

        if (!firstCurr || !secondCurr) {
            return;
        }

        if (firstPrev != nullptr) {
            firstPrev->next = secondCurr;
        }
        else {
            first = secondCurr;
        }

        if (secondPrev != nullptr) {
            secondPrev->next = firstCurr;
        }
        else {
            first = firstCurr;
        }

        Node* temp = firstCurr->next;

        firstCurr->next = secondCurr->next;
        secondCurr->next = temp;
    }

    void print() {
        if (empty()) {
            return;
        }

        Node* p = first;

        while (p) {
            cout << p->value << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main() {
    int n;
    List list;

    vector<int> temp;

    while (cin >> n) {
        temp.push_back(n);
    }

    for (int i = 0; i < temp.size() - 2; i++) {
        list.pushBack(temp[i]);
    }

    int firstElemForChange = temp[temp.size() - 2];
    int secondElemForChange = temp[temp.size() - 1];

    list.Change(firstElemForChange, secondElemForChange);

    list.print();

    return 0;
}