#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;

set< ll > res;

ll a[maxn];
int n;

bool check( int x )
{
    vector< int > tmp;
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] < x ) tmp.push_back( a[i] );
    }

    if( tmp.size( ) % 2 == 1 ) return 0;

    int l = 0, r = tmp.size( ) - 1;
    while( l < r )
    {
        if( tmp[l] + tmp[r] != x ) return 0;
        l ++, r --;
    }

    res.insert( x );
    return 1;
}

void solve( )
{
    cin >> n;
    ll sum = 0;
    for( int i = 1; i <= n; ++ i ) cin >> a[i], sum += a[i];
    sort( a + 1, a + n + 1 );

    int minv = a[1], maxv = a[n];

    check( maxv );

    check( minv + maxv );

    for( int ans : res ) cout << ans << ' ';

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}