#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// Define the precedence of operators
unordered_map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'%', 2},
    {'^', 3}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return precedence.find(c) != precedence.end();
}

// Function to convert infix expression to postfix notation
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";
    int i = 0; // Initialize i to keep track of the current position in the string

    while (i < infix.size()) {
        char c = infix[i];
        // Ignore spaces
        if (c == ' ') {
            i++;
            continue;
        }

        if (isalpha(c)) {
            // Function names are alphabetic characters
            string functionName = "";
            while (isalpha(c)) {
                functionName += c;
                i++; // Increment i to move to the next character
                if (i < infix.size()) {
                    c = infix[i];
                } else {
                    break;
                }
            }
            postfix += functionName;
        }
        else if (c == '(') {
            operators.push(c);
            i++;
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop(); // Pop the '('
            }
            i++;
        }
        else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' && precedence[c] <= precedence[operators.top()]) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
            i++;
        }
        else {
            // Numeric values
            postfix += c;
            i++;
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}