/*Write a program to implement a priority queue using an array-based approach. 
The priority queue should support the following operations:
Enqueue: Insert an element into the priority queue with a specified priority.
Dequeue: Remove the element with the highest priority from the priority queue.
isEmpty: Check if the priority queue is empty.
isFull: Check if the priority queue is full.
printPriorityQueue: Print the elements of the priority queue in the order of their priorities.*/


#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    struct Element {
        int value;
        int priority;
    };

    Element arr[MAX_SIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void enqueue(int value, int priority) {
        if (size >= MAX_SIZE) {
            cout << "Priority Queue is full. Cannot enqueue." << endl;
            return;
        }

        Element newElement;
        newElement.value = value;
        newElement.priority = priority;

        int i = size - 1;
        while (i >= 0 && arr[i].priority > priority) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = newElement;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty. Cannot dequeue." << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    void printPriorityQueue() {
        for (int i = 0; i < size; i++) {
            cout << arr[i].value << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int value, priority;
        cin >> value >> priority;
        pq.enqueue(value, priority);
    }

    cout << "Priority Queue: ";
    pq.printPriorityQueue();

    pq.dequeue();

    cout << "Priority Queue: ";
    pq.printPriorityQueue();

    return 0;
}
