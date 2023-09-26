// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int score;
    Node* next;
    Node* prev;
};

void insertAtFront(Node*& head, int newScore) {
    Node* newNode = new Node;
    newNode->score = newScore;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->score << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int newScore;

    while (cin >> newScore) {
        insertAtFront(head, newScore);

        cout << "Node Inserted" << endl;

        printList(head);
    }


    return 0;
}
