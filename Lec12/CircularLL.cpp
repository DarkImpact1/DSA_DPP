#include <iostream>

using namespace std;

// Define a struct for a circular linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to create a new node with the given data
Node* createNode(int data) {
    return new Node(data);
}

// Function to insert a node at the end of the circular linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        newNode->next = newNode; // Circular list with one node
        return newNode;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;

    return head;
}

// Function to delete a node at a given position in the circular linked list
Node* deleteAtPosition(Node* head, int position) {
    if (!head) {
        cout << "List is empty." << endl;
        return nullptr;
    }

    if (position <= 0) {
        cout << "Invalid position." << endl;
        return head;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while (count < position) {
        prev = current;
        current = current->next;
        count++;

        if (current == head) {
            cout << "Invalid position." << endl;
            return head;
        }
    }

    if (prev) {
        prev->next = current->next;
    } else {
        // Deleting the head node
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
    }

    delete current;
    return head;
}

// Function to display the contents of the circular linked list
void displayList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << "|" << current->data << "| --> ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* header = nullptr;

    // Insert elements at the end of the circular linked list
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        header = insertEnd(header, data);

        cout << "Contents of the CLL:" << endl;
        displayList(header);
    }

    int position;
    cin >> position;

    // Delete a node at the given position
    cout << "After deleting at position " << position << ":" << endl;
    header = deleteAtPosition(header, position);

    // Display the modified circular linked list
    displayList(header);

    // Free memory (optional, not shown in the sample outputs)
    Node* current = header;
    if (current) {
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != header);
    }

    return 0;
}

