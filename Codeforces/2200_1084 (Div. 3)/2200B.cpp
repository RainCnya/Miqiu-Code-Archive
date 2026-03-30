#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 10 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    
    bool inc = 1;
    for( int i = 2; i <= n; ++ i )
    {
        if( a[i - 1] > a[i] ) inc = 0;
    }

    if( !inc ) cout << 1 << '\n';
    else cout << n << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}