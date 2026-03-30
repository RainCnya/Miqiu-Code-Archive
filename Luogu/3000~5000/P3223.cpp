#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2000 + 5;

struct BigInt {
    vector< ll > digits;
    const ll BASE = 100000000;

    BigInt( ll v = 0 ) 
    {
        if( v == 0 ) digits.push_back( 0 );
        while( v > 0 ) {
            digits.push_back( v % BASE );
            v /= BASE;
        }
    }

    void mul( ll v )
    {
        if( v == 0 ) { digits.clear( ); digits.push_back( 0 ); return; }
        ll carry = 0;
        for( size_t i = 0; i < digits.size( ) || carry; ++ i ) {
            if( i == digits.size( ) ) digits.push_back( 0 );
            ll cur = digits[i] * 1ll * v + carry;
            digits[i] = cur % BASE;
            carry = cur / BASE;
        }
    }

    void print( ) 
    {
        if( digits.empty( ) ) return;
        printf( "%lld", digits.back( ) );
        for( int i = ( int )digits.size( ) - 2; i >= 0; -- i )
            printf( "%08lld", digits[i] );
        printf( "\n" );
    }
};

ll n, m;

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    cin >> n >> m;

    BigInt ans( n * n + 3ll * n + 2ll * m );

    for( int i = 1; i <= n + 1; ++ i )
        ans.mul( i );

    for( int i = n + 3 - m + 1; i <= n + 2; ++ i )
        ans.mul( i );

    ans.print( );
    return 0;
}