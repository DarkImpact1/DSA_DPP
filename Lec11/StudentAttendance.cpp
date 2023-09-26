#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of a linked list
void insertNode(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to delete all occurrences of a specific value from the linked list
void deleteValue(Node*& head, int value) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr) {
        if (curr->data == value) {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {
    Node* head = new Node();
    head->next = nullptr;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        insertNode(head, data);
    }

    std::cout << "Original List: ";
    displayList(head);

    int value;
    std::cin >> value;

    deleteValue(head, value);

    std::cout << "List after deleting all occurrences of " << value << ": ";
    displayList(head);

    // Free memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
