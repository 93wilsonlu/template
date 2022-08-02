#include <algorithm>
#include <iostream>
using namespace std;

#define N 200001

int f[N];

void getNext(const string& substr, vector<int>& next) {
    next.clear();
    next.resize(substr.size());
    int j = -1;
    next[0] = -1;
    for (int i = 1; i < substr.size(); ++i) {
        while (j > -1 && substr[j + 1] != substr[i])
            j = next[j];
        if (substr[j + 1] == substr[i])
            ++j;
        next[i] = j;
    }
}

void kmp(const string& str, const string& substr, vector<int>& next) {
    int cnt = 0;
    getNext(substr, next);
    int j = -1;
    for (int i = 0; i < str.size(); ++i) {
        while (j > -1 && substr[j + 1] != str[i])
            j = next[j];
        if (substr[j + 1] == str[i])
            ++j;
        if (j == substr.size() - 1) {
            cout << "find in position" << i << endl;
            ++cnt;
            j = next[j];
        }
    }
    if (cnt == 0)
        cout << "not find" << endl;
}