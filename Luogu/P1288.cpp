#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    int l = INT_MAX, r = -1;
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] != 0 ) continue;
        l = min( l, i );
        r = max( r, i );
    }

    l = l - 1;
    r = n - r;

    // cout << l << " " << r << '\n';

    if( l & 1 || r & 1 ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main( )
{
    int _t = 1;
    //cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
