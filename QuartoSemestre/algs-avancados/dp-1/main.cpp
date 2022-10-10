#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mountains(n+1);
    mountains[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> mountains[i];
        mountains[i] += mountains[i-1];
    }
    
}