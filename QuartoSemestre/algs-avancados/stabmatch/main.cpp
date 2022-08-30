#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;

    int marriages, tmp;
    while (tests--) {
        cin >> marriages;
        vector<vector<int>> wom_pref(marriages, vector<int>(marriages));
        for (int i = 0; i < marriages; i++) {
            cin >> tmp;
            for (int j = 0; j < marriages; j++) {
                cin >> tmp;
                wom_pref[i][j] = tmp - 1;
            }
        }

        vector<vector<int>> men_pref(marriages, vector<int>(marriages));
        for (int i = 0; i < marriages; i++) {
            cin >> tmp;
            for (int j = 0; j < marriages; j++) {
                cin >> tmp;
                men_pref[i][j] = tmp - 1;
            }
        }

        // [man] = woman
        map<int, int> wom_in_couple;
        map<int, int> man_in_couple;


        queue<int> q;
        for (int i = 0; i < marriages; i++)
            q.push(i);

        vector<int> positions(marriages, 0);
        while (!q.empty()) {
            int curr_m = q.front();
            if (man_in_couple.find(curr_m) == man_in_couple.end() && wom_in_couple.find(men_pref[curr_m][positions[curr_m]]) == wom_in_couple.end()) {

                man_in_couple[curr_m] = men_pref[curr_m][positions[curr_m]];
                wom_in_couple[men_pref[curr_m][positions[curr_m]]] = curr_m;
                positions[curr_m]++;
                q.pop();

            } else {
                int wished_wom = men_pref[curr_m][positions[curr_m]];
                auto previous_choice = find(wom_pref[wished_wom].begin(), wom_pref[wished_wom].end(), wom_in_couple[wished_wom]);
                auto possible_next_choice = find(wom_pref[wished_wom].begin(), wom_pref[wished_wom].end(), curr_m);

                if (possible_next_choice < previous_choice) {
                    man_in_couple.erase(wom_in_couple[wished_wom]);
                    wom_in_couple.erase(wished_wom);
                    man_in_couple[curr_m] = wished_wom;
                    wom_in_couple[wished_wom] = curr_m;
                    q.pop();
                    q.push(*previous_choice);

                } else {
                    q.pop();
                    q.push(*possible_next_choice);
                }
                positions[curr_m]++;
            }
        }


        for (auto m : man_in_couple) {
            cout << m.first + 1 << " " << m.second + 1 << endl;
        }
    }
}