#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    string s;
    cin >> s;
    int len = s.length( );
    stack< int > st;
    for( int i = 0; i < len; ++ i )
    {
        if( s[i] == '(' ) st.push( i );
        else if( !st.empty( ) ) {
            cout << st.top( ) << " " << i << '\n';
            st.pop( );
        }
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}