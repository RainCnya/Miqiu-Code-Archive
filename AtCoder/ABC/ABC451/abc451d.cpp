#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;
const int limit = 1e9;

void solve( )
{
    int n; cin >> n;
    vector< string > v;

    ll p = 1;
    while( p <= limit ) {
        v.push_back( to_string( p ) );
        p <<= 1;
    }

    set< ll > good;
    queue< string > q;

    for( string &s : v ) {
        good.insert( stoll( s ) );
        q.push( s );
    }

    while( !q.empty( ) ) {
        string cur = q.front( );
        q.pop( );

        for( string &suf : v ) 
        {
            string ns = cur + suf;
            if( ns.length( ) > 10 ) continue;
            ll nv = stoll( ns );
            if( nv > limit ) continue;
            if( good.find( nv ) == good.end( ) ) 
            {
                good.insert( nv );
                q.push( ns );
            }
        }
    }

    auto it = good.begin( );
    cout << *next( it, n - 1 ) << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}