#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        string line;
        getline(cin, line);
        if (line == "0") {
            break;
        }
        map<string, int> project_to_count;
        while (line != "1") {
            string project_name = line;
            while (getline(cin, line)) {
                if (line[0] == '1') {
                    break;
                }
                project_to_count[project_name]++;
            }
        }
        vector<pair<string, int>> count_to_project;
        for (auto& p : project_to_count) {
            count_to_project.push_back({p.first, p.second});
        }
        sort(count_to_project.begin(), count_to_project.end(), [](auto& a, auto& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        for (auto& p : count_to_project) {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
