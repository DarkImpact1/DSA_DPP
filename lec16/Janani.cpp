/*Janani is a dedicated math teacher who wants to simplify the process of solving 
complex mathematical expressions for her students.
She wishes to create a tool that can convert standard mathematical expressions
 written in infix notation into postfix notation. This tool will help her students
 better understand the order of operations and practice solving equations step-by
-step.*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' && precedence(c) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
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

    cout <<"Postfix expression: "<< postfix << endl;

    return 0;
}