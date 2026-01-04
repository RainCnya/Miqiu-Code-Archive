#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int N = 1e6 + 50;

ll a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    ll ans = -1;
    for( ll x = 2; x; ++ x )
    {
        bool ok = 0;
        for( int i = 1; i <= n; ++ i )
        {
            if( __gcd( a[i], x ) == 1 ) ok = 1;
        }
        if( ok ) 
        {
            ans = x;
            break;
        }
    }
    cout << ans << '\n';
}

int main( )
{
    // sieve( N );
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve();
    }
    return 0;
}