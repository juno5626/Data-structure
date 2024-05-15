
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    string value;
    Node* left;
    Node* right;
    
    Node(int k, string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* addRecursive(Node* current, int key, const string& value) {
        if (current == nullptr) {
            return new Node(key, value);
        }
        
        if (key < current->key) {
            current->left = addRecursive(current->left, key, value);
        } else if (key > current->key) {
            current->right = addRecursive(current->right, key, value);
        } else {
            cout << key << " is already in the tree" << endl;
        }
        
        return current;
    }
    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    Node* deleteRecursive(Node* current, int key) {
        if (current == nullptr) {
            cout << key << " is not in the tree" << endl;
            return nullptr;
        }
        
        if (key < current->key) {
            current->left = deleteRecursive(current->left, key);
        } else if (key > current->key) {
            current->right = deleteRecursive(current->right, key);
        } else {
            // Node to delete found
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            } else if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            } else {
                Node* minRight = findMin(current->right);
                current->key = minRight->key;
                current->value = minRight->value;
                current->right = deleteRecursive(current->right, minRight->key);
            }
        }
        return current;
    }
    
    void printInOrder(Node* node) {
        if (node != nullptr) {
            printInOrder(node->left);
            cout << "(" << node->key << ", " << node->value << ") ";
            printInOrder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void add(int key, const string& value) {
        root = addRecursive(root, key, value);
    }
    
    void remove(int key) {
        root = deleteRecursive(root, key);
    }
    
    void print() {
        printInOrder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    char command;
    int key;
    string value;

    while (true) {
        cin >> command;
        if (command == 'q') {
            break;
        }
        
        if (command == 'a') {
            cin >> key >> value;
            bst.add(key, value);
        } else if (command == 'd') {
            cin >> key;
            bst.remove(key);
        } else if (command == 'p') {
            bst.print();
        }
    }

    return 0;
}
