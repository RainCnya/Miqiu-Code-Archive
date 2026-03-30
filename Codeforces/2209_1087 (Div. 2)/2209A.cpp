#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

ll a[maxn];
ll n, k, c;

void solve( )
{
    cin >> n >> c >> k;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    sort( a + 1, a + n + 1 );
    for( int i = 1; i <= n; ++ i )
    {
        if( c >= a[i] )
        {
            ll diff = min( k, c - a[i] );
            a[i] += diff;
            k -= diff;
            c += a[i];
        }
        else break;
    }
    cout << c << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}