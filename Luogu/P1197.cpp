#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 50;

vector< int > adj[maxn];
bool broken[maxn];
int ans[maxn];
int ks[maxn];
int fa[maxn];
int n, m, k;
int total;

void DsuInit( int _n )
{
    for( int i = 1; i <= _n; ++ i ) 
    {
        fa[i] = i;
    }
}

int find( int x )
{
    if( fa[x] == x ) return x;
    return fa[x] = find( fa[x] );
}

void merge( int x, int y )
{
    int rx = find( x ), ry = find( y );
    if( rx != ry )
    {
        fa[rx] = ry;
        total --;
    }
}

int main( )
{	
    cin >> n >> m;

    DsuInit( n );

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        u ++, v ++;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    cin >> k;
    for( int i = 1; i <= k; ++ i )
    {
        cin >> ks[i];
        ks[i] ++;
        broken[ ks[i] ] = 1;
    }

    total = n - k;
    for( int u = 1; u <= n; ++ u )
    {
        if( broken[u] ) continue;
        for( int v : adj[u] )
        {
            if( broken[v] ) continue;
            merge( u, v );
        }
    }

    ans[k + 1] = total;
    for( int i = k; i >= 1; -- i )
    {
        int u = ks[i];
        broken[u] = 0;
        total ++;
        for( int v : adj[u] )
        {
            if( broken[v] ) continue;
            merge( u, v );
        }
        ans[i] = total;
    }

    for( int i = 1; i <= k + 1; ++ i )
    {
        cout << ans[i] << '\n';
    }
    return 0;
}