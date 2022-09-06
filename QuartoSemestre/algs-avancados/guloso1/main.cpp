#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, length;
    double wide;
    while (cin >> n >> length >> wide) {
        double pos, rad;
        wide = wide / 2;
        // {beg, end}
        vector<pair<double, double>> intervals;
        for (int i = 0; i < n; i++) {
            cin >> pos >> rad;
            if (rad > wide) {
                double distance = sqrt(pow(rad, 2) - pow(wide, 2));
                double beg = (pos - distance );
                double end = (pos + distance);
                intervals.push_back({beg, end});
            }
        }
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        double right = 0.0;
        int len = intervals.size();

        for (int i = 0; i < len; i++) {
            if (intervals[i].first > right) {
                break;
            }
            for (int j = i + 1; j < len; j++) {
                if (intervals[j].first > right) {
                    break;
                }
                if (intervals[j].second > intervals[i].second) {
                    i = j;
                }
            }
            ans++;
            right = intervals[i].second;
            if (right >= length)
                break;
        }
        if (right >= length)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}