/*Условие:
Дана строка, состоящая из различных видов скобок (круглых, квадратных, 
фигурных и треугольных). 
Необходимо проверить, является ли скобочное выражение правильным или нет.  
Последовательность считается правильной, если каждой открывающейся скобке 
соответствует закрывающаяся скобка такого же вида. 

Входные данные:
На вход даётся строка, содержащая последовательность скобок.  

Выходные данные:
Выведите 1, если скобочная последовательность является правильной, и 0 в 
противном случае.*/

#include <iostream>
#include <string>
using namespace std;

struct Stack {
private:
    char* stackArr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        stackArr = new char[size];
        top = -1;
    }

    ~Stack() {
        delete [] stackArr;
    }

    void push(char item) {
        if (top == capacity - 1) {
            return;
        }

        stackArr[++top] = item;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        }

        return stackArr[top--];
    }

    bool emptyCheck() {
        return top == -1;
    }

    char valueReturn() {
        if (top == -1) {
            return '\0';
        }

        return stackArr[top];
    }
};

int main() {
    string brackets;
    cin >> brackets;

    Stack stack(brackets.size());
    
    for (char ch : brackets) {
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}' || ch == '>') {
            if (stack.emptyCheck() || (ch == ')' && stack.valueReturn() != '(') 
                || (ch == ']' && stack.valueReturn() != '[') || (ch == '}' && stack.valueReturn() != '{') 
                || (ch == '>' && stack.valueReturn() != '<')) {
                cout << 0 << endl;
                return 0;
            } else {
                stack.pop();
            }
        }
    }

    if (stack.emptyCheck()) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}