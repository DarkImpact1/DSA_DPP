/*Raja is working on a programming project that involves evaluating postfix 
expressions. He needs a tool that can help him efficiently compute the results
 of such expressions.You are an experienced programmer, so Raja asks for your 
help in creating a postfix expression evaluator.Write a program to help Raja 
evaluate postfix expressions and get the desired results.*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char c : postfix) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else if (isOperator(c)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            if (c == '+') {
                result = operand1 + operand2;
            } else if (c == '-') {
                result = operand1 - operand2;
            } else if (c == '*') {
                result = operand1 * operand2;
            } else {
                result = operand1 / operand2;
            }

            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string postfix;
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);

    cout << result << endl;

    return 0;
}