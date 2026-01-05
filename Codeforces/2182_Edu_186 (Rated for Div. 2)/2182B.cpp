#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b;

ll calc( ll a, ll b, ll cur, int type )
{
    if( type == 1 )
    {
        if( a >= cur ) a -= cur;
        else return 0;
    }
    else
    {
        if( b >= cur ) b -= cur;
        else return 0;
    }

    return 1 + calc( a, b, cur * 2, type ^ 1 );
}

void solve( )
{
    cin >> a >> b;
    cout << max( calc( a, b, 1, 1 ), calc( a, b, 1, 0 ) ) << '\n';
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
