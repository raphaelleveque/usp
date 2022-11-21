#include <bits/stdc++.h>
using namespace std;

long long mdc(long long a, long long b) {
    while (b) {
        a = a % b;
        long long tmp = a;
        a = b;
        b = tmp;
    }
    return a;
}

long long arr[1010];

int main() {
    while (cin >> arr[0]) {
        if (arr[0] == 0)
            break;
        int cur = 1;

        while (true) {
            cin >> arr[cur];
            if (arr[cur] == 0)
                break;
            else cur++;
        }

        long long g = 0; 
        for (int i = 1; i < cur; i++) {
            int dif = arr[i] - arr[i - 1]; 
            g = mdc(g, dif); 
        }

        if (g < 0)
            g = g * -1;
        cout << g << endl;
    }

    return 0;
}