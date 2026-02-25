#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;

struct Edge { int to, id; };

vector< Edge > adj[maxn];
bool used[maxn];
int cur[maxn];
int cnt[maxn], a[maxn], b[maxn];
int n;

vector< int > ans;

void dfs( int u )
{
    for( int &i = cur[u]; i < adj[u].size( ); ++ i )
    {
        auto [to, id] = adj[u][i ++];
        if( used[id] ) continue;
        used[id] = 1;
        if( u == b[id] ) ans.push_back( id );
        dfs( to );
    }
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        adj[i].clear( );
        cnt[i] = 0;
        used[i] = 0;
        cur[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        cnt[ a[i] ] ++;
    }
    for( int i = 1; i <= n; ++ i )
    {
        cin >> b[i];
        cnt[ b[i] ] ++;
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( cnt[i] % 2 != 0 )
        {
            cout << -1 << '\n';
            return ;
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        adj[ a[i] ].push_back({ b[i], i });
        adj[ b[i] ].push_back({ a[i], i });
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( cur[i] < adj[i].size( ) ) dfs( i );
    }

    cout << ans.size( ) << '\n';
    for( auto i : ans ) cout << i << ' ';
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}