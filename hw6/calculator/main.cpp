#include <iostream>
#include <string>
#include "calc.h"

using namespace std;


int main() {
    string str;

    cout << "Input infix expression: ";
    getline(cin, str); 
    Calculator calc(str);

    cout << "Result = " << calc.evaluate() << endl;

    return 0;
}
