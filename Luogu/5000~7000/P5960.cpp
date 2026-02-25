#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e3 + 50;
const ll inf = 1e18;

struct Edge { int v, w; };
vector< Edge > adj[maxn];

ll dist[maxn];
int cnt[maxn];
bool vis[maxn];
int n, m;

bool spfa_negative_cycle(  )
{
    queue< int > q;
    for( int i = 1; i <= n; ++ i )
    {
        dist[i] = 0;
        cnt[i] = 0;
        vis[i] = 1;
        q.push( i );
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );
        vis[u] = 0;

        for( auto& [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if( cnt[v] >= n ) return 1;
                
                if( !vis[v] )
                {
                    q.push( v );
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({ u, w });
    }

    if( spfa_negative_cycle( ) ) 
    {
        cout << "NO" << '\n';
        return ;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << dist[i] << ' ';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}