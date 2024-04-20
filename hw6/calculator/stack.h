#ifndef  __STACK_H__
#define  __STACK_H__

#include <iostream>
#include <stdlib.h> 
#include <stdexcept> 

#define STACK_SIZE 100
using namespace std;


template <class T>
class Stack {
private:
    T stack[STACK_SIZE];
    int top;
public:
    Stack() : top(-1) {} 
    void push(T value) {
        if (top < STACK_SIZE - 1) {
            stack[++top] = value;
        } else {
            throw runtime_error("Error: Stack overflow");
        }
    }
    T pop() {
        if (top > -1) {
            return stack[top--];
        } else {
            throw runtime_error("Error: Stack underflow");
        }
    }
    bool isEmpty() {
        return top == -1;
    }
    T read_top() {
        if (top > -1) {
            return stack[top];
        } else {
            throw runtime_error("Error: Stack is empty");
        }
    }
};

#endif
