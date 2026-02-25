#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = __int128;

ull calc( ll a, ll b, ll c, ll n )
{
    ull ans = 0;
    if( a >= c )
    {
        ans += (ull)n * (n + 1) / 2 * ( a / c );
        a %= c;
    }
    if( b >= c )
    {
        ans += (ull)(n + 1) * ( b / c );
        b %= c;
    }
    ull m = ( a * n + b ) / c;
    if( m == 0 ) return ans;    
    return ans + m * n - calc( c, c - b - 1, a, m - 1 );
}

void solve( )
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if( a == 0 )
    {
        cout << min( n, b ) << '\n';
        return;
    }

    ull s1 = calc( a, b, m, n - 1 );
    ull s2 = calc( a - 1, b - 1, m, n - 1 );

    if( b == 0 ) s2 = calc( a - 1, m - 1, m, n - 1 ) - n;

    cout << n - (ll)(s1 - s2) << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}