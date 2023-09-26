#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertNode(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node* rearrangeLinkedList(Node* head) {
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    // Separate even and odd integers into two linked lists
    while (head) {
        if (head->data % 2 == 0) { // Even integer
            if (!evenHead) {
                evenHead = evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } else { // Odd integer
            if (!oddHead) {
                oddHead = oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    // Combine even and odd linked lists
    if (evenTail) {
        evenTail->next = oddHead;
    }
    if (oddTail) {
        oddTail->next = nullptr;
    }

    return evenHead ? evenHead : oddHead;
}

void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        head = insertNode(head, data);
    }

    head = rearrangeLinkedList(head);

    printLinkedList(head);

    return 0;
}
