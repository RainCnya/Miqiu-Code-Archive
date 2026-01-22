#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int fa[maxn];
int cnt[maxn];

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    else return fa[x] = find( fa[x] );
}

void solve( )
{
    int n;
    cin >> n;

    map< int, int > mp;

    for( int i = 1; i <= 2 * n; ++ i )
    {
        fa[i] = i;
        cnt[i] = 0;
    }

    int idx = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int a, b;
        cin >> a >> b;
        if( mp.find( a ) == mp.end() ) mp[a] = ++ idx;
        if( mp.find( b ) == mp.end() ) mp[b] = ++ idx;

        int u = mp[a], v = mp[b];
        int ru = find( u ), rv = find( v );

        if( ru != rv )
        {
            fa[ru] = rv;
            cnt[rv] += cnt[ru] + 1;
        }
        else
        {
            cnt[rv] += 1;
        }
    }

    int ans = 0;
    for( int i = 1; i <= idx; ++ i )
    {
        if( fa[i] == i ) ans = max( ans, cnt[i] );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}