#include <bits/stdc++.h>
using namespace std;

void dfs(int height, int maxHeight, int data, int hamming, list<int> s) {
    if (height > maxHeight) {
       return;
    }
    s.push_back(data);
    dfs(height + 1, maxHeight, 0, hamming, s);
    dfs(height + 1, maxHeight, 1, hamming, s);
    if (height == maxHeight && count(s.begin(), s.end(), 1) == hamming) {
        for (auto i : s) {
            cout << i;
        }
        cout << endl;
    }
    s.pop_back();
}

int main() {
    list<int> s;
    int tests;
    cin >> tests;

    while (tests--) {
        int maxHeight, hamming;
        cin >> maxHeight >> hamming;
        dfs(1, maxHeight, 0, hamming, s);
        dfs(1, maxHeight, 1, hamming, s);
        if (tests != 0) cout << endl;
    }

}