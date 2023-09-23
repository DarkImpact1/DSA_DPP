/*You are developing a calculator application that supports evaluating arithmetic
 expressions in Reverse Polish Notation (RPN). As part of the testing process, 
you need to verify the correctness of your implementation. You decide to create
 a scenario where a user enters an RPN expression, and your application should 
correctly evaluate and display the result.*/

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int evaluateRPN(const string& rpnExpression) {
    stack<int> operands;

    istringstream iss(rpnExpression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            operands.push(stoi(token));
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            if (token == "+") {
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operands.push(operand1 * operand2);
            } else if (token == "/") {
                operands.push(operand1 / operand2);
            }
        }
    }

    return operands.top();
}

int main() {
    string rpnExpression;
    getline(cin, rpnExpression);

    int result = evaluateRPN(rpnExpression);

    cout << "The result is: " << result << endl;

    return 0;
}