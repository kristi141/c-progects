/*RU
Условие:
Дан список чисел и некоторое значение x.
Необходимо вставить данный элемент x на k-ое место в данном списке.
В решении необходимо использовать связные списки.

Входные данные:
Во входном файле дан список чисел, затем идет вставляемый элемент и номер, 
куда его нужно вставить.

Выходные данные:
В выходной файл должен быть выведен список чисел.

Входные данные:
7 9 1 2 3 10 3

Выходные данные:
7 9 10 1 2 3

EN
Condition:
Given a list of numbers and some value x.
It is necessary to insert this element x into the k-th place in this list.
The solution must use linked lists.

Input data:
The input file is given a list of numbers, then comes the element to be 
inserted and the number, where should it be inserted.

Output:
The output file should contain a list of numbers.

Input data:
7 9 1 2 3 10 3

Output:
7 9 10 1 2 3                                         */

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

    int Size;

    List() : first(nullptr), last(nullptr), Size(0) {}

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

        Size++;
    }

    void Insert(int number, int value) {
        if (number == 1) {
            if (first != nullptr) {
                Node* newCurrent = new Node(value, nullptr, first);

                first->prev = newCurrent;
                first = newCurrent;
            }
            else {
                first = new Node(value);
                last = first;
            }
        }
        else if (number == Size + 1) {
            Node* newCurrent = new Node(value, last, nullptr);

            last->next = newCurrent;
            last = newCurrent;
        }
        else {
            int count = 1;
            Node* current = first;

            while (count < number) {
                current = current->next;
                count++;
            }

            Node* newCurrent = new Node(value, current->prev, current);

            current->prev->next = newCurrent;
            current->prev = newCurrent;
        }

        Size++;
    }

    void print() {
        if (empty()) return;
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

    list.Insert(temp[temp.size() - 1], temp[temp.size() - 2]);
    list.print();

    return 0;
}