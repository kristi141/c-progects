/*Условие:
Дан список чисел и некоторое значение x.
Необходимо удалить элемент, с данным значением x, из данного списка. 
В решении необходимо использовать связные списки.

Входные данные:
Во входном файле дан список чисел, а затем элемент, который нужно удалить 
из списка.

Выходные данные:
В выходной файл должен быть выведен список чисел.*/

#include <iostream>
#include <iomanip>
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

	void Insert(int num, int index) {
		Node* currentNode = new Node(num);

		if (index == 1) {
			currentNode->next = first;
			first = currentNode;

			return;
		}
		else {
			Node* before = first;

			for (int i = 0; i < index - 2; i++)
				before = before->next;

			currentNode->next = before->next;
			before->next = currentNode;
		}
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

	int removeLast() {
		if (empty()) {
			return 0;
		}

		Node* p = first;

		while (p->next != last) {
			p = p->next;
		}

		int t = last->value;
		p->next = nullptr;

		delete last;
		last = p;

		return t;
	}

	void remove(int num) {
		if (empty()) {
			return;
		}

		if (first->value == num) {
			Node* p = first;
			first = p->next;

			delete p;
		}
		else if (last->value == num) {
			Node* p = first;

			while (p->next != last) {
				p = p->next;
			}

			int k = last->value;
			p->next = nullptr;

			delete last;
			last = p;
		}
		else {
			Node* previous = first;
			Node* succeeding = first->next;

			while (succeeding && succeeding->value != num) {
				succeeding = succeeding->next;
				previous = previous->next;
			}

			previous->next = succeeding->next;

			delete succeeding;
		}
	}
};

int main() {
	List list;
	int n;

	while (cin >> n) {
		list.pushBack(n);
	}

	int value = list.removeLast();
	list.remove(value);

	list.print();

	return 0;
}