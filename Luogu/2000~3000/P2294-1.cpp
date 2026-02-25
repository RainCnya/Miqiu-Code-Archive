#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
ll dist[maxn];
int cnt[maxn];
bool vis[maxn];
int n, m;

bool spfa( )
{
    queue< int > q;
    for( int i = 0; i <= n; ++ i )
    {
        dist[i] = 0;
        cnt[i] = 0;
        vis[i] = true;
        q.push( i );
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );
        vis[u] = false;
        for( auto& [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if( cnt[v] >= n + 1 ) return true;

                if( !vis[v] )
                {
                    q.push( v );
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 0; i <= n; ++ i ) adj[i].clear( );
    for( int i = 1; i <= m; ++ i ) 
    {
        int s, t, v;
        cin >> s >> t >> v;
        adj[s-1].push_back({ t, v });
        adj[t].push_back({ s-1, -v });
    }

    if( spfa( ) ) cout << "false" << '\n';
    else cout << "true" << '\n';
    
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