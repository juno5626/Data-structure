#include <iostream>
#define SIZE 20
using namespace std;

class Stack {
private:
    int top;
    char sta[SIZE]; 

public:
    Stack(){
        top = 0;
    }
    void push(char a) {
        sta[top++] = a;
    }

    char pop() {
        return sta[--top];
    }

    bool isEmpty() const {
        return top == 0;
    }

    void Print() const {
        if (isEmpty()) {
            cout << "Stack is empty" << std::endl;
            return;
        }

        cout << "Stack:";
        for (int i = 0; i < top; ++i) {
            cout << " " << sta[i];
        }
        cout << std::endl;
    }
};

int main() {
    Stack stack1;
    char temp;

    while(1){
        cout<<"Enter the character you want to push into the stack.(0:stop)"<<endl;
        cin>>temp;
        if(temp == '0'){
            break;
        }
        stack1.push(temp);
    }
    stack1.Print(); 

    return 0;
}