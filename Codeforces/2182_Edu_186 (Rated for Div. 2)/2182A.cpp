#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool has_2026 = ( s.find( "2026" ) != string::npos );   
    bool has_2025 = ( s.find( "2025" ) != string::npos );

    if( has_2026 || !has_2025 ) cout << 0 << '\n';
    else cout << 1 << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
