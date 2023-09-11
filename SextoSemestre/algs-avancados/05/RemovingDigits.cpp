#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    s = to_string(n);
    int i = 0;
    while (n && ++i) {
        if (s.size() == 1 || s[0] > s[1]) {
            n = n - (s[0] - '0');
        } else {
            n = n - (s[1] - '0');
        }
        s = to_string(n);
    }
    cout << i << endl;
}