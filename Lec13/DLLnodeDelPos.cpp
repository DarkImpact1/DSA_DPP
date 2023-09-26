//Deleting node from specific position
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteNode(int position) {
        if (!head) {
            return;
        }

        Node* current = head;
        int count = 1;

        // Traverse the list in reverse order
        while (current->next) {
            current = current->next;
            count++;
        }
        // Find the node to be deleted in reversed indexing
        int reversedPosition = count - position + 1;
        count = 1;
        current = head;

        // Traverse the list again to delete the node at reversedPosition
        while (current && (count < reversedPosition)) {
            current = current->next;
            count++;
        }
        // cout<<current->data;
        if (current) {
            if (current == head && current == tail) {
                head = tail = nullptr;
            } else if (current == head) {
                head = head->next;
                head->prev = nullptr;
            } else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
        }
    }

    void display() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    cin >> n;

    DoublyLinkedList dll;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if(value>=0){
        dll.insert(value);}
    }

    int position;
    cin >> position;

    cout << "Doubly linked list before deletion:" << endl;
    dll.display();
    if (position < n){
    dll.deleteNode(position);}

    cout << "Doubly linked list after deletion:" << endl;
    dll.display();

    return 0;
}
