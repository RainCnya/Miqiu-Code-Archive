#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 30 + 5;
const int maxm = maxn * maxn;

struct Edge { int u, v; } edges[maxm];

int cache[maxn];
ll dp[maxn];
int n, m;

int ask( ll k )
{
    cout << "? " << k << endl;
    int len = 0;
    cin >> len;
    if( len == 0 ) return 0;
    for( int i = 0; i < len; ++ i ) cin >> cache[i];
    return len;
}

ll dfs( int u, ll rnk )
{
    if( dp[u] != -1 ) return dp[u];
    ll cnt = 1;
    while( 1 )
    {
        int len = ask( rnk + cnt );
        if( len == 0 || cache[0] != u ) break;
        int v = cache[1];
        edges[m ++] = { u, v };
        cnt += dfs( v, rnk + cnt );
    }
    return dp[u] = cnt;
}

void solve( )
{
    cin >> n;
    memset( dp, -1, sizeof( dp ) );
    m = 0;
    ll rnk = 1;
    for( int i = 1; i <= n; ++ i )
    {
        if( dp[i] == -1 ) dfs( i, rnk );
        rnk += dp[i];
    }
    
    cout << "! " << m << endl;
    for( int i = 0; i < m; ++ i ) cout << edges[i].u << " " << edges[i].v << endl;
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}