#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(const string& input) {
    stack<char> charStack;
    string reversedString;

    for (char c : input) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

int main() {
    string input;
    getline(cin, input);

    string reversed = reverseString(input);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
