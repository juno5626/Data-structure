#ifndef __CALC_H__
#define __CALC_H__

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class Calculator {
private:
    string str_EX; // 중위 표기식을 저장할 변수

    float calculateExpression(const string& expression); // 표현식을 계산하는 함수
    int getPrecedence(char op); // 연산자 우선순위를 반환하는 함수

public:
    Calculator(string str) {
        str_EX = str;
    }
    float evaluate();
};

#endif
