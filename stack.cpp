#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    int* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == maxSize - 1);
    }
    
    void push(int value) {
        if (!isFull()) {
            stackArray[++top] = value;
        } 
    }
    
    void pop() {
        if (!isEmpty()) {
            top--;}
    }
    
    int peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
    }
};

int main() {
    Stack stack(5);

    if (stack.isEmpty()) {
        cout << "Is empty?: " << stack.isEmpty() << endl;

        stack.push(10);
        stack.push(20);
        stack.push(30);
    }

    cout << "Is full?: " << stack.isFull() << endl;

    stack.push(40);
    stack.push(50);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after popping: " << stack.peek() << endl;

    return 0;
}
