#include <iostream>
#include <stack>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string expression) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        else if (isOperator(ch)) {
            while (!s.empty() &&
                   s.top() != '(' &&
                   priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    cout << "Postfix expression: "
         << infixToPostfix(expression);

    return 0;
}