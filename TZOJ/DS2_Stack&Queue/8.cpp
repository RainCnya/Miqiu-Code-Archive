#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int get( char op )
{
    if( op == '+' || op == '-' ) return 1;
    if( op == '*' || op == '/' ) return 2;
    return 0;
}

void solve( )
{
    string s;
    while( getline( cin, s ) ) 
    {
        if( s.empty( ) ) continue;
        vector< string > res;
        stack< char > ops;

        for( int i = 0; i < s.size( ); ++ i )
        {
            char c = s[i];
            if( isdigit( c ) ) {
                res.push_back( string( 1, c ) );
            } else if( c == '(' ) {
                ops.push( c );
            } else if( c == ')' ) {
                while( !ops.empty( ) && ops.top( ) != '(' ) {
                    res.push_back( string( 1, ops.top( ) ) );
                    ops.pop( );
                }
                if( !ops.empty( ) ) ops.pop( );
            } else {
                while( !ops.empty( ) && get( ops.top( ) ) >= get( c ) ) {
                    res.push_back( string( 1, ops.top( ) ) );
                    ops.pop( );
                }
                ops.push( c );
            }
        }
        while( !ops.empty( ) ) {
            res.push_back( string( 1, ops.top( ) ) );
            ops.pop( );
        }
        for( int i = 0; i < res.size( ); ++ i )
        {
            if( i ) cout << " ";
            cout << res[i];
        }
        cout << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}