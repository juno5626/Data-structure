#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

void toUpperCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void removePunctuation(string &str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (ispunct(str[i])) {
            str[i] = ' ';
        }
    }
}

bool comparePairs(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

vector<pair<string, int> > getTopFiveFrequentWords(const unordered_map<string, int> &wordCount) {
    vector<pair<string, int> > wordList(wordCount.begin(), wordCount.end());

    sort(wordList.begin(), wordList.end(), comparePairs);

    vector<pair<string, int> > topFive;
    for (int i = 0; i < 5 && i < wordList.size(); ++i) {
        topFive.push_back(wordList[i]);
    }

    return topFive;
}

int main() {
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    ifstream file(fileName.c_str());
    if (!file.is_open()) {
        cerr << "Unable to open file " << fileName << endl;
        return 1;
    }

    unordered_map<string, int> wordCount;
    string line;
    while (getline(file, line)) {
        removePunctuation(line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            for (size_t i = 0; i < word.size(); ++i) {
                word[i] = tolower(word[i]);
            }
            wordCount[word]++;
        }
    }

    file.close();

    vector<pair<string, int> > topFiveWords = getTopFiveFrequentWords(wordCount);
    for (size_t i = 0; i < topFiveWords.size(); ++i) {
        string upperWord = topFiveWords[i].first;
        toUpperCase(upperWord);
        cout << upperWord << ": " << topFiveWords[i].second << endl;
    }

    return 0;
}
