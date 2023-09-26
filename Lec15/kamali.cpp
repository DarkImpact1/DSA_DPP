#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void sortStack(stack<int>& inputStack) {
    stack<int> sortedStack;

    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();

        while (!sortedStack.empty() && sortedStack.top() > temp) {
            inputStack.push(sortedStack.top());
            sortedStack.pop();
        }

        sortedStack.push(temp);
    }

    while (!sortedStack.empty()) {
        inputStack.push(sortedStack.top());
        sortedStack.pop();
    }
}
int top=-1;
int Stack[100];

int main() {
    int n;
    cin >> n;

    stack<int> inputStack;
    vector<int> originalOrder;

    if (n == 0) {
        cout << "Stack is empty" << endl;
    } else if (n > 10) {
        cout << "Stack is full" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            int element;
            cin >> element;
            inputStack.push(element);
            top++;
            Stack[i]=element;
        }
        cout << "Original stack: ";
        for (int i = 0; i <=top; i++) {
            cout << Stack[i] << " ";
        }
        cout << endl;
    
        sortStack(inputStack);
    
        cout << "Sorted stack: ";
        while (!inputStack.empty()) {
            cout << inputStack.top() << " ";
            inputStack.pop();
        }
        cout << endl;
    }

    return 0;
}
