#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;

void solve( )
{
    cin >> n >> s;
    vector< char > st; 
    for( char c : s )
    {
        if( !st.empty( ) && st.back( ) == c ) st.pop_back( );
        else st.push_back( c );
    }
    if( st.empty( ) ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}