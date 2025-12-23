#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2000 + 5;

int a[maxn];
bool vis[maxn];

void solve( )
{
    int n;
    cin >> n;
    memset( vis, 0, sizeof( vis ) );

    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }
    for( int i = 1; i <= n; ++ i )
    {
        if( !vis[ a[i] ] )
        {
            cnt ++;
            vis[ a[i] ] = 1;
        }
    }
    int ans = cnt;
    while( !vis[ ans ] ) ans ++;

    cout << ans << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
