#include <bits/stdc++.h>
using namespace std;

int main() {
    int chambers, specimens;
    int set = 1;
    while (cin >> chambers >> specimens) {

        vector<int> masses(specimens);
        for (int i = 0; i < specimens; i++) {
            cin >> masses[i];
        }
        double average = accumulate(masses.begin(), masses.end(), 0);
        average /= chambers;

        double imbalance = 0;
        sort(masses.begin(), masses.end());

        cout << "Set #" << set << endl;
        int odd = specimens % 2;
        int i = 0;
        if (odd) {
            imbalance += abs(masses[specimens - 1] - average);
            cout << " " << i << ": " << masses[specimens - 1] << endl;
        }
        for (i = 0; i < chambers - odd; i++) {
            cout << " " << i + odd << ": "; 
            if (specimens < chambers && i < specimens - odd) {
                cout << masses[specimens - 1 - i - odd] << endl;
                imbalance += abs(masses[masses.size() - 1 - i - odd] - average);
            } else if (i >= specimens - odd) {
                cout << endl;
                imbalance += average;
            } else { 
                cout << masses[i] << " " << masses[masses.size() - 1 - i - odd] << endl;
                imbalance += abs((masses[i] + masses[masses.size() - 1 - i - odd]) - average);
            }
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << endl << endl;
        set++;
    }

    return 0;
}