#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e3 + 5;
const ll inf = 1e18;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
ll dist[maxn];
int cnt[maxn];
bool inq[maxn];
int a, b, c, n, m;

bool spfa( )
{
    queue< int > q;
    for( int i = 1; i <= n; ++ i )
    {
        dist[i] = 0;
        q.push( i ), inq[i] = true;
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( ), inq[u] = false;

        for( auto& [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if( cnt[v] >= n ) return true;
                if( !inq[v] ) q.push( v ), inq[v] = true;
            }
        }
    }
    return false;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for( int i = 1; i <= m; ++ i ) 
    {
        int opt;
        cin >> opt >> a >> b;
        if( opt == 1 )
        {
            cin >> c;
            adj[a].push_back({ b, -c });
        }
        else if( opt == 2 )
        {
            cin >> c;
            adj[b].push_back({ a, c });
        }
        else
        {
            adj[a].push_back({ b, 0 });
            adj[b].push_back({ a, 0 });
        }
    }

    if( spfa( ) ) cout << "No" << '\n';
    else cout << "Yes" << '\n';

    return 0;
}