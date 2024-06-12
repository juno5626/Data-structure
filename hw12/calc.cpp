#include "calc.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
#include <stdexcept>

int Calculator::getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

float Calculator::applyOperation(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': if (b != 0) return a / b;
                  else throw std::invalid_argument("Error: Division by zero");
        default: throw std::invalid_argument("Invalid operator");
    }
}

float Calculator::calculateExpression(const std::string& expression) {
    std::stack<float> operands;
    std::stack<char> operators;
    std::istringstream iss(expression);
    char token;

    while (iss >> token) {
        if (isdigit(token) || token == '.') {
            iss.putback(token);
            float operand;
            iss >> operand;
            operands.push(operand);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                float operand2 = operands.top();
                operands.pop();
                float operand1 = operands.top();
                operands.pop();
                operands.push(applyOperation(operand1, operand2, op));
            }
            operators.pop(); // Remove '('
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                char op = operators.top();
                operators.pop();
                float operand2 = operands.top();
                operands.pop();
                float operand1 = operands.top();
                operands.pop();
                operands.push(applyOperation(operand1, operand2, op));
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        float operand2 = operands.top();
        operands.pop();
        float operand1 = operands.top();
        operands.pop();
        operands.push(applyOperation(operand1, operand2, op));
    }

    return operands.top();
}

float Calculator::evaluate() {
    return calculateExpression(expression);
}
