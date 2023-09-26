#include <iostream>

using namespace std;

// Define the Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Define the Stack class using a linked list
class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    bool is_empty() {
        return size == 0;
    }

    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        size++;
    }

    int pop() {
        if (is_empty()) {
            return -1; // Stack underflow, handle it accordingly
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
};

// Function to convert decimal to binary using a stack
string decimal_to_binary(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    Stack stack;
    while (decimal > 0) {
        int remainder = decimal % 2;
        stack.push(remainder);
        decimal /= 2;
    }

    string binary = "";
    while (!stack.is_empty()) {
        binary += to_string(stack.pop());
    }

    return binary;
}

int main() {
    int decimal;
    cin >> decimal;
    string binary = decimal_to_binary(decimal);
    cout << "Binary representation: " << binary << endl;
    return 0;
}
