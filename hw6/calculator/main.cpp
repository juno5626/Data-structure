#include <iostream>
#include <string>
#include "calc.h"

using namespace std;


int main() {
    string str;

    cout << "Input infix expression: ";
    getline(cin, str); // 중위 표기식을 읽음

    Calculator calc(str);

    cout << "Result = " << calc.evaluate() << endl;

    return 0;
}
