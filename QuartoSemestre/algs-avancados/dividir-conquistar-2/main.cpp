#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // <how many times, duration of the song>
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (i > 0) {
            arr[i].first = arr[i - 1].first + (arr[i].first * arr[i].second);
        } else {
            arr[i].first *= arr[i].second;
        }
        arr[i].second = i + 1;
    }
    
    vector<pair<int, int>> moments(m);
    for (int i = 0; i < m; i++) {
        cin >> moments[i].first;
        moments[i].second = i;
    }
    
    sort(moments.begin(), moments.end());
    vector<int> ans(m);
    vector<pair<int, int>>::iterator it = arr.begin();
    for (auto mom : moments) {
        while (it->first < mom.first)
            it++;
        ans[mom.second] = it->second;
    }
    for (auto a : ans)
        cout << a << endl;

    return 0;
}