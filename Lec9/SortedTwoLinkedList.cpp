#include <iostream>
#include <set>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertNode(Node* head, int data) {
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

Node* mergeAndRemoveDuplicates(Node* list1, Node* list2) {
    set<int> uniqueElements;
    Node* mergedList = nullptr;

    while (list1 || list2) {
        if (list1 && !uniqueElements.count(list1->data)) {
            mergedList = insertNode(mergedList, list1->data);
            uniqueElements.insert(list1->data);
            list1 = list1->next;
        }
        else if (list2 && !uniqueElements.count(list2->data)) {
            mergedList = insertNode(mergedList, list2->data);
            uniqueElements.insert(list2->data);
            list2 = list2->next;
        }
        else {

            if (list1) list1 = list1->next;
            if (list2) list2 = list2->next;
        }
    }

    return mergedList;
}

Node* sortLinkedList(Node* head) {
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    head = sortLinkedList(head);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;

    Node* firstList = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        firstList = insertNode(firstList, data);
    }

    cin >> m;
    Node* secondList = nullptr;
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        secondList = insertNode(secondList, data);
    }

    Node* unionList = mergeAndRemoveDuplicates(firstList, secondList);

    cout << "First Linked List: ";
    printLinkedList(firstList);

    cout << "Second Linked List: ";
    printLinkedList(secondList);

    cout << "Union Linked List: ";
    printLinkedList(unionList);

    return 0;
}
