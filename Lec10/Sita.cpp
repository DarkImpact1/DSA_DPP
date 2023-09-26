#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeDuplicates(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicateNode = current->next;
            current->next = current->next->next;
            delete duplicateNode;
        } else {
            current = current->next;
        }
    }
}

void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int size;

    cin >> size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        insertNode(&head, value);
    }

    cout << "Original Linked List: ";
    displayLinkedList(head);

    removeDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    displayLinkedList(head);

    deleteLinkedList(head);

    return 0;
}
