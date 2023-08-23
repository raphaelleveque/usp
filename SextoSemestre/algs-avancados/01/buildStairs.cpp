#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    for (int i = n - 1; i > 0 ; --i) {
        if (vec[i] < vec[i-1])
            vec[i-1]--;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (vec[i + 1] < vec[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}