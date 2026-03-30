#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

ll s, m;

void solve( )
{
    cin >> s >> m;

    vector< int > bits;
    for( int i = 0; i <= 63; ++ i )
    {
        if( ( m >> i ) & 1 ) bits.push_back( i );
    }

    if( s % ( 1ll << bits[0] ) != 0 )
    {
        cout << -1 << '\n';
        return;
    }

    ll ans = 0, sum = 0;
    for( int i = 0; i < bits.size( ); ++ i )
    {
        sum += ( 1ll << bits[i] );
        
        ll rem = s;
        if( i + 1 < bits.size( ) ) rem = s % ( 1ll << bits[i + 1] );
        
        ll need = ( rem + sum - 1 ) / sum;
        ans = max( ans, need );
    }
    cout << ans << '\n';
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