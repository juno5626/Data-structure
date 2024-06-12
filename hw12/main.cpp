#include <iostream>
#include <string>
#include "calc.h"

int main() {
    std::string expression;
    std::cout << "Enter the expression: ";
    std::getline(std::cin, expression);
    Calculator calculator(expression);
    try {
        float result = calculator.evaluate();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
