#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

int n;

bool check( string s1, string s2 )
{
    size_t p1 = 0, p2 = 0;
    while( p1 < s1.size( ) && s1[p1] == '0' ) ++ p1;
    while( p2 < s2.size( ) && s2[p2] == '0' ) ++ p2;
    string t1 = s1.substr( p1 );
    string t2 = s2.substr( p2 );
    if( t1.size( ) != t2.size( ) ) return t1.size( ) > t2.size( );
    return t1 > t2;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        string s1, s2;
        cin >> s1 >> s2;

        s1.erase( 0, 2 );
        s2.erase( 0, 2 );

        if( check( s1, s2 ) ) cout << "0." << s1 << ' ';
        else cout << "0." << s2 << ' ';

        cout << "0." << max( s1, s2 ) << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}