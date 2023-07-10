#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computePrefixArray(const string& pattern) {
    int m = pattern.length();
    vector<int> prefixArray(m, 0);
    int len = 0;

    for (int i = 1; i < m; ++i) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = prefixArray[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
        }
        prefixArray[i] = len;
    }

    return prefixArray;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    vector<int> prefixArray = computePrefixArray(pattern);

    int count = 0;
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefixArray[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            count++;
            j = prefixArray[j - 1];
        }
    }

    cout << count << endl;

    return 0;
}
