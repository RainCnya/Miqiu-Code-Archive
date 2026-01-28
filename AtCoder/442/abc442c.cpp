#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 50;

int n, m;
int cnt[maxn];

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        cnt[u] ++;
        cnt[v] ++;
    }

    for( int i = 1; i <= n; ++ i )
    {
        ll remain = n - 1 - cnt[i];
        if( remain < 3 ) cout << 0 << " ";
        else cout << remain * ( remain - 1 ) * ( remain - 2 ) / 6 << " ";
    }

    return 0;
}