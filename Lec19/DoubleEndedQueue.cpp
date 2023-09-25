#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> myDeque;
    int element;

    while (true) {
        cin >> element;

        if (element == -1) {
            break;
        }

        myDeque.push_back(element);
    }

    if (myDeque.empty()) {
        cout << "Deque is empty." << endl;
    } else {
        int maxElement = myDeque.front();

        for (int num : myDeque) {
            if (num > maxElement) {
                maxElement = num;
            }
        }

        cout << maxElement << endl;
    }

    return 0;
}
