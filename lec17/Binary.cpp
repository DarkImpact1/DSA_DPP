/*You are assigned to design and implement a program that generates and prints 
a binary sequence based on the user's input.
The program should utilize a queue data structure implemented using a linked list 
to efficiently generate and manage the binary sequence.*/

#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> binaryQueue;
    binaryQueue.push("1");

    for (int i = 0; i < n; i++) {
        string currentBinary = binaryQueue.front();
        binaryQueue.pop();

        cout << currentBinary << " ";

        binaryQueue.push(currentBinary + "0");
        binaryQueue.push(currentBinary + "1");
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    generateBinaryNumbers(n);

    return 0;
}