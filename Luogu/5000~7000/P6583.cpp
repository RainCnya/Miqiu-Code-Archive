#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector< ll > s2, s5, s10;

ll calc( ll M )
{
    ll res = 0;
    if( M >= 1 ) res += M;
    ll c2 = upper_bound( s2.begin( ), s2.end( ), M ) - s2.begin( );
    res += c2 * ( M - M / 2 );
    ll c5 = upper_bound( s5.begin( ), s5.end( ), M ) - s5.begin( );
    res += c5 * ( M - M / 5 );
    ll c10 = upper_bound( s10.begin( ), s10.end( ), M ) - s10.begin( );
    res += c10 * ( M - M / 2 - M / 5 + M / 10 );
    
    return res;
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    ll n; 
    cin >> n;
    
    for( ll p2 = 1, a = 0; p2 <= n; p2 *= 2, a ++ )
    {
        for( ll p5 = 1, b = 0; p2 * p5 <= n; p5 *= 5, b ++ )
        {
            ll v = p2 * p5;
            if( a > 0 && b == 0 ) s2.push_back( v );
            else if( a == 0 && b > 0 ) s5.push_back( v );
            else if( a > 0 && b > 0 ) s10.push_back( v );
        }
    }
    sort( s2.begin( ), s2.end( ) );
    sort( s5.begin( ), s5.end( ) );
    sort( s10.begin( ), s10.end( ) );

    ll ans = 0;

    for( ll l = 1, r; l <= n; l = r + 1 )
    {
        r = n / ( n / l );
        ans += ( r - l + 1 ) * calc( n / l );
    }

    cout << ans << endl;
    return 0;
}