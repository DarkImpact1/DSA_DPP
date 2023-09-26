#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* insertNode(Node* head, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (!head) {
        return newNode;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true; // Empty or single-element list is a palindrome
    }

    Node* slow = head;
    Node* fast = head;
    Node* prevSlow = nullptr;

    while (fast && fast->next) {
        fast = fast->next->next;
        prevSlow = slow;
        slow = slow->next;
    }

    if (fast) {
        prevSlow = slow;
        slow = slow->next;
    }

    Node* secondHalf = reverseLinkedList(slow);

    Node* firstHalf = head;
    while (firstHalf && secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; // It's a palindrome
}

int main() {
    char input;
    Node* head = nullptr;

    while (cin >> input && input != '$') {
        head = insertNode(head, input);
    }

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome" << endl;
    } else {
        cout << "The linked list is not a palindrome" << endl;
    }

    return 0;
}
