#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    vector<int> ti;
    for( int i = 1; i <= 13; ++ i )
    {
        int x;
        cin >> x;
        if( x != -1 ) ti.push_back( x );
    }

    sort( ti.begin( ) , ti.end( ) );
    
    ll anst = 0;
    ll ansn = 0;
    ll cur = 0;
    
    for( int x : ti )
    {
        cur += x;
        if( cur > 300 ) break;
        anst += cur;
        ansn ++;
    }
    cout << ansn << " " << anst << '\n';
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
