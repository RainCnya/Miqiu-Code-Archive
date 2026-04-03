#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int fa[maxn], dist[maxn];
ll cnt0[maxn], cnt1[maxn];
int n, q;

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    int rt = find( fa[x] );
    dist[x] = ( dist[x] + dist[fa[x]] ) % 2;
    return fa[x] = rt;
}

void solve( )
{
    cin >> n >> q;
    for( int i = 1; i <= n; ++ i )
    {
        fa[i] = i;
        dist[i] = 0;
        cnt0[i] = 1;
        cnt1[i] = 0;
    }

    bool flag = 1;
    ll ans = 0;

    while( q -- )
    {
        int u, v; cin >> u >> v;

        if( !flag ) { cout << -1 << '\n'; continue; }

        int ru = find( u ), rv = find( v );
        if( ru != rv )
        {
            ans -= min( cnt0[ru], cnt1[ru] );
            ans -= min( cnt0[rv], cnt1[rv] );
            
            ll diff = ( dist[u] + dist[v] + 1 ) % 2;
            fa[ru] = rv;
            dist[ru] = diff;

            if( diff == 0 ) cnt0[rv] += cnt0[ru], cnt1[rv] += cnt1[ru];
            else cnt0[rv] += cnt1[ru], cnt1[rv] += cnt0[ru];
            
            ans += min( cnt0[rv], cnt1[rv] );
        }
        else 
        {
            if( dist[u] == dist[v] ) flag = 0;
        }
        
        if( !flag ) cout << -1 << '\n';
        else cout << ans << '\n';
    }

}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}