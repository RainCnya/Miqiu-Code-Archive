#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

bool vis[maxn];
ll a[maxn], k;
int n;

void solve( )
{
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1 );
    int m = unique( a + 1, a + n + 1 ) - (a + 1);

    for( int i = 1; i <= m; ++ i )
    {
        vis[i] = 0;
    }

    vector<int> b;
    for( int i = 1; i <= m; ++ i )
    {
        if( vis[i] ) continue;
        if( k / a[i] > m )
        {
            cout << -1 << '\n';
            return;
        }

        for( ll j = 1; j * a[i] <= k; ++ j )
        {
            ll val = j * a[i];
            int pos = lower_bound( a + 1, a + m + 1, val ) - a;
            
            if( pos > m || a[pos] != val )
            {
                cout << -1 << '\n';
                return ;
            }
            vis[pos] = 1;
        }
        b.push_back( a[i] );
    }

    cout << b.size( ) << '\n';
    for( auto x : b ) cout << x << ' ';
    cout << '\n';
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