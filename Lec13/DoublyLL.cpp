// You are using GCC
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert an element at the end of the linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert an element at a specific position in the linked list
void insertAtPosition(Node*& head, int newData, int position) {
    if (position <= 1 || head == nullptr) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int newData;
        cin >> newData;
        insertAtEnd(head, newData);
    }

    int data, position;
    cin >> data >> position;

    // Print the linked list after inserting at the end
    cout << "List after inserting at the end: ";
    printList(head);
    // Insert the element at the specified position
    insertAtPosition(head, data, position);


    // Print the linked list after inserting at the specified position
    cout << "List after inserting at position " << position << ": ";
    printList(head);

    // Clean up the allocated memory (not shown in the code)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
