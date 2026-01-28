#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve( )
{
    string s;
    cin >> s;

    size_t pos = s.find( "cjb" );
    while( pos != string::npos )
    {
        s.insert( pos + 3, "," );
        pos = s.find( "cjb", pos + 2 );
    }
    cout << s << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}