// You are using GCC
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(const string& value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insertNode(const string& value, int position) {
        Node* newNode = new Node(value);

        if (position == 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList linkedList;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;
        linkedList.insertNode(value, i + 1);
    }

    string newValue;
    int position;
    cin >> newValue >> position;

    cout << "Current Linked List:" << endl;
    linkedList.printList();

    linkedList.insertNode(newValue, position);

    cout << "Updated Linked List:" << endl;
    linkedList.printList();

    return 0;
}
