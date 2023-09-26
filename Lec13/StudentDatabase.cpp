// You are using GCC
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;
};

void insertAtEnd(Node*& head, string newName) {
    Node* newNode = new Node;
    newNode->name = newName;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void splitLinkedList(Node* head, Node*& firstHalf, Node*& secondHalf) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    current = head;

    for (int i = 0; i < count / 2; i++) {
        current = current->next;
    }

    firstHalf = head;
    secondHalf = current->next;
    current->next = nullptr;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->name;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Consume newline character

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        string newName;
        getline(cin, newName);
        insertAtEnd(head, newName);
    }

    Node* firstHalf = nullptr;
    Node* secondHalf = nullptr;

    splitLinkedList(head, firstHalf, secondHalf);

    printList(firstHalf);

    printList(secondHalf);

    return 0;
}
