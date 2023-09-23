/*In a grocery store, customers join a single queue to check out their items. 
The grocery store wants to implement a system to manage the checkout queue using 
a data structure. Each customer's arrival is recorded and added to the queue. The 
grocery store staff wants to display the queue in reverse order to check the 
customers' positions.Implement a program to manage a grocery store checkout queue 
using a linked list. The program should allow customers to join the queue, and 
the order of their arrival should be reversed, meaning the first customer to join 
becomes the last in line. The program should display the current state of the 
queue*/

#include <iostream>
#include <stack>

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
            newNode->next = front;
            front = newNode;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* current = front;
            cout << "Queue: ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Queue queue;

    for (int i = 0; i < n; i++) {
        int customerPosition;
        cin >> customerPosition;
        queue.enqueue(customerPosition);
    }

    queue.displayQueue();

    return 0;
}