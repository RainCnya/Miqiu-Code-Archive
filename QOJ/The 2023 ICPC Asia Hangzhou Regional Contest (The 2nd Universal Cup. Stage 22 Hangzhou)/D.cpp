#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    ll n;
    cin >> n;

    if( n == 2 )
    {
        cout << "1 -3 -3 1" << '\n';
        return ;
    }

    ll x = 2 * n - 3;

    cout << x << " " << 2 << " ";
    for( int i = 1; i <= n - 2; ++ i )
    {
        cout << -1 << " " << 2 << " ";
    }
    cout << -1 << " " << 1 << " " << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}