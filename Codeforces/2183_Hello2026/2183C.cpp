#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n, m, k;

void solve( )
{
    cin >> n >> m >> k;

    ll l = k - 1;
    ll r = n - k;

    if( l > r ) swap( l, r );

    ll a = 0, b = 0;
    while( 1 )
    {
        bool flag = 0;
        if( b < r && a + (b + 1) + max(a, b + 1) - 1 <= m ) 
            ++ b, flag = 1;
        if( a < l && (a + 1) + b + max(a + 1, b) - 1 <= m ) 
            ++ a, flag = 1;
        if( !flag ) break;
    }

    cout << a + b + 1 << '\n';
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