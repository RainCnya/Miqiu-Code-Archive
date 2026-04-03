#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;


void solve( )
{
    int Q; cin >> Q;
    multiset< int > s;
    while( Q -- )
    {
        int opt, h;
        cin >> opt >> h;
        if( opt == 1 ) s.insert( h );
        else while( !s.empty( ) && *s.begin( ) <= h ) s.erase( s.begin( ) );
        cout << s.size( ) << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}