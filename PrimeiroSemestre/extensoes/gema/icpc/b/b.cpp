#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define DBG(x) cout << "[" << #x << "]: " << x << '\n'
#define all(x) x.begin(), x.end()
#define mset(a, b) memset(a, b, sizeof(a))

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MXN = 1e5 + 5;

void subString(string a, int n)
{
    vector<char> tmp;
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            int j = i + len - 1;           
            for (int k = i; k <= j; k++)
                tmp.push_back(str[k]);
             
            for(int x : tmp)
                cout << x;
                
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int strASize, nmrStrs;
    cin >> strASize >> nmrStrs;

    string a;
    cin >> a;

    subString(a, a.size());

    

}