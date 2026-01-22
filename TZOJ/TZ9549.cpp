#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 50;

vector<int> adj[maxn];

int stk[maxn];
int dp[maxn];
int a[maxn];
int n;

int find( int val, int len )
{
    int l = 0, r = len - 1;
    int res = len;
    while( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if( a[stk[mid]] >= val ) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}

void dfs( int u, int fa, int len ) 
{
    int pos = find( a[u], len );
    dp[u] = dp[ stk[pos - 1] ] + 1;

    int tmp = stk[pos];
    stk[pos] = u;

    for( int v : adj[u] ) 
    {
        if( v == fa ) continue;
        dfs( v, u, pos + 1 );
    }
    
    stk[pos] = tmp;
}

int main( ) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i < n; ++ i ) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    a[0] = 0;
    dp[0] = -1;
    stk[0] = 0;
    dfs( 1, 0, 1 );

    for( int i = 1; i <= n; ++ i )
    {
        cout << dp[i] << " ";
    }
    return 0;
}