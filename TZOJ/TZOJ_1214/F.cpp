#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const int N = 1e6 + 50;
#define int long long
int n , k;

void solve(){
    cin >> n >> k;
    vector<vector<int>> e(n + 1);
    vector<int> siz(n + 1, 1);
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    auto dfs=[&](auto dfs,int u,int fa)->void{
        for(auto v: e[u]){
            if(v == fa) continue;
            dfs(dfs,v, u);
            siz[u] += siz[v];
        }
    };

    dfs(dfs, 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(siz[i] >= k) ans += n - siz[i];
        if(n - siz[i] >= k) ans += siz[i];
    }
    cout << n + ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _ = 1;
    cin >> _;
    while(_--){
        solve();
    }
}
