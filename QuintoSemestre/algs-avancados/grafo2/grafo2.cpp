#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
#define int long long

int link[100005], len[100005];
int find(int a){
    while(a!=link[a])
        a=link[a];
    return a;
}
void join(int a, int b){
    if (find(a)==find(b)) return;
    int x = find(a), y = find(b);
    if (len[x]>len[y]) swap(x,y);
    len[y]+=len[x];
    link[x] = y;
}
void solve(){
    int n,m; see(n,m);
    vector<tuple<int,int,int>> e;
    for(int i = 0; i < m; i++){
        int w,a,b; see(a,b,w);
        e.push_back({w,a,b});
    }
    sort(e.begin(), e.end());
    for(int i = 1; i < n+1; i++) {
        link[i]=i;
        len[i]=1;
    }
    int s=0;
    for (auto [w,a,b]:e){
        if (find(a)==find(b)) continue;
        s+=w;
        join(a,b);
    }
    int c=0;
    for(int i = 1; i < n+1; i++)
        if (link[i]==i) 
            c++;
    if (c==1)put(s);
    else put("IMPOSSIBLE");
}    
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    #endif
}