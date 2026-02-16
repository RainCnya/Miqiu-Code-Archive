#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 15 + 5;

struct Edge { int u, v; };

int cache[maxn];
int dp[maxn];
int rnk[maxn];
int n, m;

int ask( ll k )
{
    cout << "? " << k << endl;
    int len = 0;
    cin >> len;
    if( len == -1 ) return -1;
    for( int i = 0; i < len; i ++ ) cin >> cache[i];
    return len;
}

void solve( )
{
    cin >> n >> m;

    ll l = 1, r = 1e6, sum = 0;    
    while( l <= r )
    {
        ll mid = ( l + r ) >> 1;
        int len = ask( mid );
        if( len != -1 ) sum = mid, l = mid + 1;
        else r = mid - 1;
    }

    rnk[n + 1] = sum + 1;
    for( int u = 1; u <= n; ++ u )
    {
        ll l = 1, r = sum, res = sum + 1;
        while( l <= r )
        {
            ll mid = ( l + r ) >> 1;
            int len = ask( mid );
            if( len != -1 && cache[0] >= u ) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        rnk[u] = res;
    }

    for( int u = 1; u <= n; ++ u ) dp[u] = rnk[u + 1] - rnk[u];

    vector< Edge > ans;
    for( int u = 1; u <= n; ++ u )
    {
        ll cur = rnk[u] + 1;
        while( cur < rnk[u + 1] )
        {
            int len = ask( cur );
            int v = cache[1];
            ans.push_back({ u, v });
            cur += dp[v];
        }
    }
    
    cout << "! " << ans.size( ) << " " << endl;
    for( auto &[u, v] : ans ) cout << u << " " << v << endl;
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}