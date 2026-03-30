#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int get( string opt )
{
    if( opt == "+" || opt == "-" ) return 1;
    if( opt == "*" || opt == "/" ) return 2;
    return 0;
}

double calc( double a, double b, string opt )
{
    if( opt == "+" ) return a + b;
    if( opt == "-" ) return a - b;
    if( opt == "*" ) return a * b;
    if( opt == "/" ) return a / b;
    return 0;
}

void solve( )
{
    string str;
    while( getline( cin, str ) ) 
    {
        if( str.length( ) == 1 && str[0] == '0' ) break;
        stringstream ss( str );
        string cur;
        stack< double > nums;
        stack< string > ops;
        while( ss >> cur )
        {
            if( isdigit( cur[0] ) ) nums.push( stod( cur ) );
            else {
                while( !ops.empty( ) && get( ops.top( ) ) >= get( cur ) )
                {
                    double b = nums.top( ); nums.pop( );
                    double a = nums.top( ); nums.pop( );
                    nums.push( calc( a, b, ops.top( ) ) );
                    ops.pop( );
                }
                ops.push( cur );
            }
        }
        while( !ops.empty( ) )
        {
            double b = nums.top( ); nums.pop( );
            double a = nums.top( ); nums.pop( );
            nums.push( calc( a, b, ops.top( ) ) );
            ops.pop( );
        }
        cout << fixed << setprecision( 2 ) << nums.top( ) << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}