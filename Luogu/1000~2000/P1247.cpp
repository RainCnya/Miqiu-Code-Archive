#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    int s = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        s ^= a[i];
    }
    
    if( s == 0 )
    {
        cout << "lose" << '\n';
    }
    else
    {
        for( int i = 1; i <= n; ++ i )
        {
            if( ( a[i] ^ s ) > a[i] ) continue;
            cout << ( a[i] - ( a[i] ^ s ) ) << " " << i << '\n';
            a[i] ^= s;
            break;
        }
        for( int i = 1; i <= n; ++ i )
        {
            cout << a[i];
            if( i != n ) cout << " ";
        }
    }
}

int main( )
{
    int _t = 1;
    //cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
