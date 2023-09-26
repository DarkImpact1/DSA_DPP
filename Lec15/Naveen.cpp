#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return -1;  // Return a sentinel value indicating an error.
        }

        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    void deleteEven() {
        Node* current = top;
        Node* prev = nullptr;

        while (current) {
            if (current->data % 2 == 0) {
                if (prev) {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                } else {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                    top = current;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    void printStack() {
        Node* current = top;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    int n;cin>>n;
    if(n>=1 || n<=12){
    for(int i=0; i<n;i++)
    {
        int item;
        cin>>item;
        if(item>=1 || item <=100){
        stack.push(item);}
    }
    }

    // std::cout << "Original Stack:" << std::endl;
    stack.printStack();

    stack.deleteEven();

    // std::cout << "Stack after deleting even numbers:" << std::endl;
    stack.printStack();

    return 0;
}
