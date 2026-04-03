#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

int p[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> p[i];

    if( n == 1 ) 
    {
        cout << 1 << '\n';
        return;
    }

    for( int i = 1; i <= n; ++ i ) cout << 2 << ' ';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}