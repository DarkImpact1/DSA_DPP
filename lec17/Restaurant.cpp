/*You are assigned to develop a program that manages customer orders in a restaurant
 using a queue data structure. The restaurant can handle a limited number of orders at a time, and the order
 will be stored in an array-based queue.

Your task is to implement the Queue data structure and the associated functions, which will provide the necessary operations to manage the queue of customer orders using an array. 
The main functionalities of the queue include:
Enqueue: Adding a customer order to the end of the queue.
Get Front: Retrieve the details of the first customer order in the queue.
Get Rear: Retrieve the details of the last customer order in the queue.*/

#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> data;
    int front;
    int rear;
    int capacity;

public:
    Queue(int capacity) {
        data.resize(capacity);
        front = -1;
        rear = -1;
        this->capacity = capacity;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return data[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return data[rear];
    }
};

int main() {
    int capacity;
    cin >> capacity;

    Queue queue(capacity);

    for (int i = 0; i < capacity; i++) {
        int order;
        cin >> order;
        queue.enqueue(order);
    }

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Rear element: " << queue.getRear() << endl;

    return 0;
}