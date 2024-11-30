#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw runtime_error("Division by zero");
            }
            return a / b;
    }
    return 0;
}

vector<string> infixToPostfix(const string& expression) {
    stack<char> operators;
    vector<string> output;
    string token;

    for (size_t i = 0; i < expression.length(); ++i) {
        char current = expression[i];

        if (isdigit(current)) {
            token.clear();
            while (i < expression.length() && isdigit(expression[i])) {
                token += expression[i++];
            }
            output.push_back(token);
            --i;
        } else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(current)) {
                output.push_back(string(1, operators.top()));
                operators.pop();
            }
            operators.push(current);
        }
    }


    while (!operators.empty()) {
        output.push_back(string(1, operators.top()));
        operators.pop();
    }

    return output;
}


int evaluatePostfix(const vector<string>& postfix) {
    stack<int> values;

    for (const string& token : postfix) {
        if (isdigit(token[0])) {
            values.push(stoi(token));
        } else {
            if (values.size() < 2) {
                throw runtime_error("Invalid expression");
            }
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            int result = applyOp(a, b, token[0]);
            values.push(result);
        }
    }

    if (values.size() != 1) {
        throw runtime_error("Invalid expression");
    }

    return values.top();
}

int main() {
    string expression;
    
    while (true) { 
        cout << "Enter an expression in infix notation: ";
        getline(cin, expression);

        expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

        try {
            vector<string> postfix = infixToPostfix(expression);
            int result = evaluatePostfix(postfix);
            cout << "Result: " << result << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
