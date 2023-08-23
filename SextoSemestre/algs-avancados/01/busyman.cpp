#include <bits/stdc++.h>
using namespace std;
#define iPair pair<int, int>

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        // <end, start>
        vector<iPair> activities(n);
        for (int i = 0; i < n; i++) {
            cin >> activities[i].second >> activities[i].first;
        }
        sort(activities.begin(), activities.end());
        int count = 1, end = activities[0].first;
        for (int i = 1; i < n; i++) {
            if (activities[i].second >= end) {
                count++;
                end = activities[i].first;
            }
        }
        cout << count << endl;
    }
    
}