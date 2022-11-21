#include <bits/stdc++.h>
using namespace std;

#define LEN 10000

bool ehdivisivel(vector<char> a, int len) {
    for (int i = len - 1; i >= 16; --i) {
        if (a[i]) {
            int k = i - 16;
            if (k < 0) return false;

            int bor = 0;
            int n = i;
            while (n >= k) {
                int t = (a[n] - bor - 1 + 2) % 2;
                bor = 1 - (a[n] - bor - 1 + 2) / 2;
                a[n--] = t;
            }
            while (n >= 0 && bor) {
                int t = (a[n] - bor + 2) % 2;
                bor = 1 - (a[n] - bor + 2) / 2;
                a[n--] = t;
            }
            if (bor) {
                return false;
            }
        }
    }
    for (int i = 0; i < 16; ++i) {
        if (a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<char> a(LEN);
    while (true) {
        fill(a.begin(), a.end(), 0);
        vector<char>::iterator p = a.begin();
        while ((*p = getchar()) != '#' && *p != EOF) {
            if (isdigit(*p)) {
                *p++ -= '0';
            }
            if (p - a.begin() > LEN) {
                perror("Falhou aqui");
                continue;
            }

        }
        if (*p == EOF) {
            return 0;
        }
        *p = 0;
        int len = p - a.begin();

        if (ehdivisivel(a, len)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}