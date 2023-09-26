#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;

    while (true) {
        int choice, data;
        cin >> data >> choice;

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        cout << "Node inserted" << endl;

        if (choice != 0) {
            break;
        }
    }

    cout << "Linked List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Node ended" << endl;

    return 0;
}
