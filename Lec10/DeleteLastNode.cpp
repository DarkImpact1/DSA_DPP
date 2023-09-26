#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    string data;
    ListNode* next;

    ListNode(const string& val) : data(val), next(nullptr) {}
};

ListNode* createLinkedList(int n) {
    if (n <= 0) {
        return nullptr;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        string value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

ListNode* deleteLastNode(ListNode* head) {
    if (!head || !head->next) {
        return nullptr;
    }

    ListNode* current = head;
    while (current->next->next) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = createLinkedList(n);

    head = deleteLastNode(head);

    printLinkedList(head);

    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

