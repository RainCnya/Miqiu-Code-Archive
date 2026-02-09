#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 200 + 50;
const int maxm = 5e4 + 50;

struct Edge { 
    int u, v; 
    ll g, s;
    bool operator < ( const Edge &oth ) const { return g < oth.g; }
} edges[maxm];

int fa[maxn];
ll G, S;
int n, m;

int find( int x ) { return fa[x] == x ? x : fa[x] = find( fa[x] ); }

void solve( )
{
    cin >> n >> m;
    cin >> G >> S;

    for( int i = 1; i <= m; ++ i )
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].g >> edges[i].s;
    }

    sort( edges + 1, edges + m + 1 );
    ll ans = -1;

    vector< Edge > cur;
    for( int i = 1; i <= m; ++ i )
    {
        Edge now = edges[i];        

        auto it = cur.begin( );
        while( it != cur.end( ) && it -> s <= now.s ) it ++;
        cur.insert( it, now );

        for( int j = 1; j <= n; ++ j ) fa[j] = j;

        ll max_s = 0;
        int cnt = 0;
        
        vector< Edge > nxt;
        for( auto &e : cur )
        {
            int fu = find( e.u ), fv = find( e.v );
            if( fu != fv ) 
            {
                fa[fu] = fv;
                nxt.push_back( e );
                max_s = max( max_s, e.s );
                cnt ++;
            }
        }
        
        cur = nxt;
        if( cnt == n - 1 )
        {
            ll res = now.g * G + max_s * S;
            if( ans == - 1 || res < ans ) ans = res;
        }
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}