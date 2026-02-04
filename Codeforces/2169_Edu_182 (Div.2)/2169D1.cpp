#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

ll x, y, k;

void solve( )
{
    cin >> x >> y >> k;
    
    bool ok = 1;

    for( int i = 1; i <= x; ++ i )
    {
        if( y == 1 )
        {
            ok = 0;
            break;
        }
        ll pre = k + ( k - 1 ) / ( y - 1 );

        if( pre > 1e12 )
        {
            ok = 0;
            break;
        }
        k = pre;
    }
    if( ok ) cout << k << '\n';
    else cout << -1 << '\n';
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