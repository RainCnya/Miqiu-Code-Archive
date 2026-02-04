#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    ll a, b;
    cin >> a >> b;
    if( a == b ) 
    {
        cout << "0" << '\n';
        return;
    }
    else if( a < b )
    {
        int diff = b - a;
        if( diff % 2 == 1 ) cout << 1 << '\n';
        else 
        {
            if( diff/2 % 2 == 1 ) cout << 2 << '\n';
            else cout << 3 << '\n';
        }
    }
    else
    {
        int diff = a - b;
        if( diff % 2 == 0 ) cout << "1" << '\n';
        else cout << "2" << '\n';
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}