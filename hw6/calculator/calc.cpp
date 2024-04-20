#include <iostream>
#include <sstream>
#include "calc.h"



int Calculator::getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // 괄호는 우선순위에 포함하지 않음
}

float Calculator::calculateExpression(const string& expression) {
    Stack<float> operands; // 피연산자 스택
    Stack<char> operators; // 연산자 스택

    stringstream ss(expression); // stringstream을 사용하여 문자열 파싱

    char token;
    while (ss >> token) {
        if (isdigit(token) || (token == '-' && isdigit(ss.peek()))) {
            // 숫자인 경우
            ss.putback(token); // 현재 문자를 다시 버퍼에 넣고
            float operand;
            ss >> operand; // float로 파싱
            operands.push(operand);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.isEmpty() && operators.read_top() != '(') {
                char op = operators.pop();
                float operand2 = operands.pop();
                float operand1 = operands.pop();
                switch (op) {
                    case '+':
                        operands.push(operand1 + operand2);
                        break;
                    case '-':
                        operands.push(operand1 - operand2);
                        break;
                    case '*':
                        operands.push(operand1 * operand2);
                        break;
                    case '/':
                        if (operand2 != 0) {
                            operands.push(operand1 / operand2);
                        } else {
                            cerr << "Error: Division by zero" << endl;
                            exit(1);
                        }
                        break;
                    default:
                        cerr << "Error: Invalid operator" << endl;
                        exit(1);
                }
            }
            if (!operators.isEmpty() && operators.read_top() == '(') {
                operators.pop(); // '(' 제거
            } else {
                cerr << "Error: Invalid infix expression" << endl;
                exit(1);
            }
        } else {
            // 연산자인 경우
            while (!operators.isEmpty() && getPrecedence(operators.read_top()) >= getPrecedence(token)) {
                char op = operators.pop();
                float operand2 = operands.pop();
                float operand1 = operands.pop();
                switch (op) {
                    case '+':
                        operands.push(operand1 + operand2);
                        break;
                    case '-':
                        operands.push(operand1 - operand2);
                        break;
                    case '*':
                        operands.push(operand1 * operand2);
                        break;
                    case '/':
                        if (operand2 != 0) {
                            operands.push(operand1 / operand2);
                        } else {
                            cerr << "Error: Division by zero" << endl;
                            exit(1);
                        }
                        break;
                    default:
                        cerr << "Error: Invalid operator" << endl;
                        exit(1);
                }
            }
            operators.push(token);
        }
    }

    while (!operators.isEmpty()) {
        char op = operators.pop();
        float operand2 = operands.pop();
        float operand1 = operands.pop();
        switch (op) {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0) {
                    operands.push(operand1 / operand2);
                } else {
                    cerr << "Error: Division by zero" << endl;
                    exit(1);
                }
                break;
            default:
                cerr << "Error: Invalid operator" << endl;
                exit(1);
        }
    }

    if (!operands.isEmpty()) {
        return operands.pop();
    } else {
        cerr << "Error: Empty stack" << endl;
        exit(1);
    }
}

float Calculator::evaluate() {
    return calculateExpression(infix); // 중위 표기식을 계산
}
