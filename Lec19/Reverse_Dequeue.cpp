#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> myDeque;

    for (int i = 0; i < N; i++) {
        int element;
        cin >> element;
        myDeque.push_back(element);
    }

    for (int i = 0; i < N / 2; i++) {
        int temp = myDeque[i];
        myDeque[i] = myDeque[N - i - 1];
        myDeque[N - i - 1] = temp;
    }

    for (int i = 0; i < N; i++) {
        cout << myDeque[i];
        if (i < N - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}
