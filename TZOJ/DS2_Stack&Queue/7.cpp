#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    string str;
    while( getline( cin, str ) )
    {
        if( str.empty( ) ) continue;
        
        stringstream ss( str );
        vector< string > v;

        string s;
        while( ss >> s ) v.push_back( s );

        stack< double > st;

        for( int i = 0; i < v.size( ); ++ i )
        {
            string t = v[i];
            if( t == "*" || t == "+" || t == "-" || t == "/" )
            {
                double a = st.top( ); st.pop( );
                double b = st.top( ); st.pop( );
                if( t == "*" ) st.push( b * a );
                else if( t == "+" ) st.push( b + a );
                else if( t == "-" ) st.push( b - a );
                else if( t == "/" ) st.push( b / a );
            }
            else 
            {
                st.push( stod( t ) );
            }
        }
        if( !st.empty( ) ) cout << fixed << setprecision( 2 ) << st.top( ) << '\n';

    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}