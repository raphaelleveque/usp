#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    map<char, Trie> triemap;
    int counter = 0;
    int end = 0;

    void add(string &s, int i = 0) {
        counter++;
        if (i < (int)s.size()) {
            triemap[s[i]].add(s, i + 1);
        } else
            end++;
    }

    void remove(string &s, int i = 0) {
        counter--;
        if (i < (int)s.size()) {
            triemap[s[i]].remove(s, i + 1);
        } else
            end--;
    }

    int search(string &s, int i = 0) {
        if (i == (int)s.size())
            return counter;
        if (triemap.count(s[i]))
            return triemap[s[i]].search(s, i + 1);
        return 0;
    }
};
int main() {
    Trie root;
    int quantidade;
    cin >> quantidade;
    for (int i = 0; i < quantidade; i++) {
        int value;
        string x;
        cin >> value >> x;
        switch (value) {
        case 1:
            root.add(x);
            break;
        case 2:
            root.remove(x);
            break;
        case 3:
            cout << root.search(x) << endl;
            break;
        }
    }
    return 0;
}