#ifndef CALC_H
#define CALC_H

#include <string>

class Calculator {
private:
    std::string expression;

    int getPrecedence(char op);
    float applyOperation(float a, float b, char op);
    float calculateExpression(const std::string& expression);

public:
    Calculator(const std::string& exp) : expression(exp) {}

    float evaluate();
};

#endif // CALC_H
