#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

struct Edge {
    int to, nxt, w;
} e[maxn << 1];

int head[maxn], tot = 1;

int n, k;

int dis[maxn];
int pre[maxn];
int pre_edge[maxn];

int dp[maxn];
int diam2;

void add( int u, int v, int w )
{
    e[++ tot] = { v, head[u], 1 };
    head[u] = tot;
    e[++ tot] = { u, head[v], 1 };
    head[v] = tot;
}

int bfs( int start )
{
    memset( dis, -1, sizeof( dis ) );

    queue< int > q;
    q.push( start );

    dis[start] = 0;
    pre[start] = 0;

    int far_node = start;
    int max_d = 0;

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );

        if( dis[u] > max_d )
        {
            max_d = dis[u];
            far_node = u;
        }

        for( int i = head[u]; i; i = e[i].nxt )
        {
            int v = e[i].to;
            if( dis[v] == -1 )
            {
                dis[v] = dis[u] + e[i].w;
                pre[v] = u;
                pre_edge[v] = i;
                q.push( v );
            }
        } 
    }
    return far_node;
}

void dfs_dp( int u, int fa )
{
    int max1 = 0, max2 = 0;

    for( int i = head[u]; i; i = e[i].nxt )
    {
        int v = e[i].to;
        if( v == fa ) continue;

        dfs_dp( v, u );

        int val = dp[v] + e[i].w;
        
        if( val > max1 ) 
        {
            max2 = max1;
            max1 = val;
        }
        else if( val > max2 )
        {
            max2 = val;
        }
    }
    diam2 = max( diam2, max1 + max2 );
    dp[u] = max1;
}

void solve( )
{
    int S1 = bfs( 1 );
    int S2 = bfs( S1 );
    int L1 = dis[S2];

    if( k == 1 )
    {
        cout << 2 * ( n - 1 ) - L1 + 1 << '\n';
        return;
    }

    int cur = S2;
    while( cur != S1 )
    {
        int edge_idx = pre_edge[cur];
        e[edge_idx].w = -1;
        e[edge_idx ^ 1].w = -1;
        cur = pre[cur];
    }

    dfs_dp( 1, 0 );
    int L2 = diam2;

    cout << 2 * n - L1 - L2 << '\n';
}

int main( )
{
    cin >> n >> k;

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        add( u, v, 1 );
    }

    solve( );
    return 0;
}