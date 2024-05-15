#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(const string& data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const string& data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cerr << "Stack is empty!" << endl;
            return "";
        }
        Node* temp = top;
        string poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

void printLinesReverse(const string& fileName) {
    Stack stack;
    ifstream file(fileName);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stack.push(line);
        }
        file.close();

        while (!stack.isEmpty()) {
            string poppedLine = stack.pop();
            stringstream ss(poppedLine);
            string name, id, email;
            getline(ss, name, ',');
            getline(ss, id, ',');
            getline(ss, email);
            cout << id << ", " << name << ", " << email << endl;
        }
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
}

int main() {
    string fileName;
    cout << "Enter the input file name: ";
    cin >> fileName;
    printLinesReverse(fileName);
    return 0;
}
