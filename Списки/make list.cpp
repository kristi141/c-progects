/*RU
Условие:
Дана последовательность чисел.
Необходимо составить список из данной последовательности и вывести его 
на экран.
В решении необходимо использовать связные списки.

Входные данные:
На вход дается последовательность чисел.

Выходные данные:
В выходной файл должен быть выведен список чисел.

ENG
Condition:
Given a sequence of numbers.
It is necessary to create a list from this sequence and display it
to the screen.
The solution must use linked lists.

Input data:
The input is a sequence of numbers.

Output:
The output file should contain a list of numbers.*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int value) : value(value), next(nullptr) {}
};

struct List {
    Node* first;
    Node* last;
    List() : first(nullptr), last(nullptr) {}

    bool empty() {
        return first == nullptr;
    }

    void pushBack(int value) {
        Node* p = new Node(value);
        
        if (empty()) {
            first = p;
            last = p;
            return;
        }
        
        last->next = p;
        last = p;
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
    List list;
    int n;

    while(cin >> n) {
        list.pushBack(n);
    }
    
    list.print();
    
    return 0;
}