/*You've been assigned the challenge of developing a queue data structure using
a linked list.The program should allow users to interact with the queue by 
enqueuing positive integers and subsequently dequeuing and displaying elements.*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int item = front->data;
        Node* temp = front;

        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
        }

        delete temp;
        return item;
    }

    void displayDequeuedElements() {
        cout << "Dequeued elements: ";
        while (front != nullptr) {
            cout << dequeue() << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    int item;
    while (true) {
        cin >> item;
        if (item == -1) {
            break;
        }
        queue.enqueue(item);
    }

    queue.displayDequeuedElements();

    return 0;
}