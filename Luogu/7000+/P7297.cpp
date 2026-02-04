#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;
const int maxk = 50 + 5;
const ll inf = 1e18;

struct Edge { int v; ll w; };
string s[maxk];
ll dist[maxn][maxk];
bool vis[maxn][maxk];
int b[maxn];
int n, k;

struct State {
    int u, k; ll d;
    bool operator < ( const State &oth ) const { return d > oth.d; }
};

void dijkstra( )
{
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= k; ++ j )
        {
            dist[i][j] = inf;
            vis[i][j] = 0;
        }
    }

    priority_queue< State > pq;

    for( int j = 1; j <= k; ++ j )
    {
        if( s[ b[1] ][j - 1] == '1' )
        {
            dist[1][j] = 0;
            pq.push({ 1, j, 0 });
        }
    }


    while( !pq.empty( ) )
    {
        auto [u, ck, d] = pq.top( );
        pq.pop( );

        if( vis[u][ck] ) continue;
        vis[u][ck] = 1;

        if( u + 1 <= n && dist[u+1][ck] > d + 1 )
        {
            dist[u+1][ck] = d + 1;
            pq.push({ u+1, ck, dist[u+1][ck] });
        }
        if( u - 1 >= 1 && dist[u-1][ck] > d + 1 )
        {
            dist[u-1][ck] = d + 1;
            pq.push({ u-1, ck, dist[u-1][ck] });
        }

        if( b[u] == ck )
        {
            for( int nk = 1; nk <= k; ++ nk )
            {
                if( s[ b[u] ][nk - 1] == '1' && dist[u][nk] > d )
                {
                    dist[u][nk] = d;
                    pq.push({ u, nk, dist[u][nk] });
                }
            }
        }
    }
}

void solve( )
{
    cin >> n >> k;

    for( int i = 1; i <= n; ++ i ) cin >> b[i];
    for( int i = 1; i <= k; ++ i ) cin >> s[i];

    dijkstra( );

    if( dist[n][b[n]] == inf )
    {
        cout << "-1\n";
        return;
    }
    cout << dist[n][b[n]] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}