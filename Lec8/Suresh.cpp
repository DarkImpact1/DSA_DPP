#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
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

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    int numElements;
    cin >> numElements;

    Node* head = nullptr;

    for (int i = 0; i < numElements; ++i) {
        int element;
        cin >> element;
        insertNode(head, element);
    }

    displayList(head);

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
