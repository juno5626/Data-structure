#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Node {
public:
    string key;
    string data;
    Node* left;
    Node* right;

    Node(string key, string data) {
        this->key = key;
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    void insertRecursive(Node*& node, string key, string data) {
        if (node == nullptr) {
            node = new Node(key, data);
        } else if (key < node->key) {
            insertRecursive(node->left, key, data);
        } else if (key > node->key) {
            insertRecursive(node->right, key, data);
        } else {
            node->data = data;
        }
    }

    string searchRecursive(Node* node, string key) {
        if (node == nullptr) {
            return "";
        } else if (key == node->key) {
            return node->data;
        } else if (key < node->key) {
            return searchRecursive(node->left, key);
        } else {
            return searchRecursive(node->right, key);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(string key, string data) {
        insertRecursive(root, key, data);
    }

    string search(string key) {
        return searchRecursive(root, key);
    }
};

void reviseText(const string& text_file, const string& map_file) {
    BinarySearchTree bst;

    ifstream mapFileStream(map_file);
    if (mapFileStream.is_open()) {
        string line;
        while (getline(mapFileStream, line)) {
            stringstream ss(line);
            string source_word, target_word;
            getline(ss, source_word, ':');
            getline(ss, target_word);
            bst.insert(source_word, target_word);
        }
        mapFileStream.close();
    } else {
        cout << "Unable to open map file";
        return;
    }

    ifstream textFileStream(text_file);
    if (textFileStream.is_open()) {
        string line;
        while (getline(textFileStream, line)) {
            stringstream ss(line);
            string word;
            string revised_line = "";
            while (ss >> word) {
                string replacement = bst.search(word);
                if (!replacement.empty()) {
                    revised_line += replacement + " ";
                } else {
                    revised_line += word + " ";
                }
            }
            cout << revised_line << endl;
        }
        textFileStream.close();
    } else {
        cout << "Unable to open text file";
        return;
    }
}

int main() {
    string text_file, map_file;

    cout << "텍스트 파일 이름을 입력하세요: ";
    cin >> text_file;
    cout << "맵 파일 이름을 입력하세요: ";
    cin >> map_file;

    reviseText(text_file, map_file);

    return 0;
}
