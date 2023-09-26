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
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertNode(const string& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void appendNode(const string& value) {
        insertNode(value);
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    LinkedList linkedList;

    int num_of_strings;
    cin >> num_of_strings;

    for (int i = 0; i < num_of_strings; i++) {
        string value;
        cin >> value;
        linkedList.insertNode(value);
    }

    string new_string;
    cin >> new_string;
    linkedList.appendNode(new_string);

    cout << "Linked List Contents: ";
    linkedList.printList();
    cout << endl;

    return 0;
}
