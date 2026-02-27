#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int mod = 998244353;

vector< int > adj[maxn];
int T[maxn], p[maxn], v[maxn];
ll mul[maxn], cnt[maxn];
int indeg[maxn], seq[maxn];
ll a[maxn];
int n, m, q;

ll calc( int u )
{
    if( mul[u] != -1 ) return mul[u];
    if( T[u] == 1 ) return mul[u] = 1;
    if( T[u] == 2 ) return mul[u] = v[u];
    ll res = 1;
    for( int v : adj[u] ) res = res * calc( v ) % mod;
    return mul[u] = res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    cin >> m;
    for( int i = 1; i <= m; ++ i )
    {
        mul[i] = -1;
        cin >> T[i];
        if( T[i] == 1 ) cin >> p[i] >> v[i];
        else if( T[i] == 2 ) cin >> v[i];
        else 
        {
            int count, child;
            cin >> count;
            for( int j = 1; j <= count; ++ j )
            {
                cin >> child;
                adj[i].push_back(child);
                indeg[child] ++;
            }
        }
    }

    for( int i = 1; i <= m; ++ i ) mul[i] = calc( i );

    cin >> q;
    for( int i = 1; i <= q; ++ i ) cin >> seq[i];

    ll prod = 1;
    for( int i = q; i >= 1; -- i ) 
    {
        int f = seq[i];
        cnt[f] = ( cnt[f] + prod ) % mod;
        prod = prod * mul[f] % mod;
    }
    
    queue< int > Q;
    for( int i = 1; i <= m; ++ i ) if( indeg[i] == 0 ) Q.push(i);

    while( !Q.empty( ) )
    {
        int u = Q.front( ); Q.pop( );
        if( T[u] != 3 ) continue;

        ll suf = cnt[u];

        for( int i = adj[u].size( ) - 1; i >= 0; -- i )
        {
            int v = adj[u][i];
            cnt[v] = ( cnt[v] + suf ) % mod;
            suf = suf * mul[v] % mod;
            if( --indeg[v] == 0 ) Q.push(v);
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        a[i] = a[i] * prod % mod;
    }
    
    for( int i = 1; i <= m; ++ i )
    {
        if( T[i] == 1 )
        {
            int idx = p[i];
            a[idx] = ( a[idx] + cnt[i] * v[i] ) % mod;
        }
    }

    for( int i = 1; i <= n; ++ i ) cout << a[i] << ' ';
    return 0;
}