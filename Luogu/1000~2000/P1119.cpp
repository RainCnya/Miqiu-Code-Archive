#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 50;
const int maxm = 4e4 + 50;
const int inf = 1e9;

int ts[maxn];
int dist[maxn][maxn];
int n, m, q;

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            if( i == j ) dist[i][j] = 0;
            else dist[i][j] = inf; 
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> ts[i];
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        u ++, v ++;
        dist[u][v] = dist[v][u] = w;
    }

    int k = 1;
    cin >> q;
    while( q -- )
    {
        int x, y, t;
        cin >> x >> y >> t;
        x ++, y ++;
        while( k <= n && ts[k] <= t )
        {
            for( int i = 1; i <= n; ++ i )
            {
                for( int j = 1; j <= n; ++ j )
                {
                    if( dist[i][k] != inf && dist[k][j] != inf )
                    {
                        dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                    }
                }
            }
            k ++;
        }
        if( ts[x] > t || ts[y] > t || dist[x][y] == inf )
            cout << -1 << '\n';
        else
            cout << dist[x][y] << '\n'; 
    }
    return 0;
}