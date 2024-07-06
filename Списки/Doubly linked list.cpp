/*RU
Условие:
Дана последовательность цифр.
Необходимо составить двусвязный список из данной последовательности и 
вывести его на экран.
В решении необходимо использовать двусвязные списки.

Входные данные:
На вход дается последовательность цифр.

Выходные данные:
В выходной файл должен быть выведен двусвязный список чисел

Входные данные:
18 6 0 58 7 9 1 2 3

Выходные данные:
18 6 0 58 7 9 1 2 3

ENG
Condition:
A sequence of numbers is given.
You need to create a doubly linked list from this sequence and
display it on the screen.
The solution must use doubly linked lists.

Input data:
The input is a sequence of numbers.

Output:
The output file should contain a doubly linked list of numbers

Input data:
18 6 0 58 7 9 1 2 3

Output:
18 6 0 58 7 9 1 2 3                              */

#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
    node* prev;
    node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

struct List {
    node* first;
    node* last;
    List() : first(nullptr), last(nullptr) {}

    bool empty() {
        return first == nullptr;
    }

    void pushBack(int value) {
        node* p = new node(value);

        if (empty()) {
            first = p;
            last = p;
            return;
        }

        p->prev = last;
        last->next = p;
        last = p;
    }

    void print() {
        if (empty()) return;
        node* p = first;

        while (p) {
            cout << p->value << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main() {
    List list;
    int n;

    while (cin >> n) {
        list.pushBack(n);
    }

    list.print();

    return 0;
}