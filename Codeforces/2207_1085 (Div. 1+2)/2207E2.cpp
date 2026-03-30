#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    a[0] = n;

    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i <= n; ++ i ) 
    {
        if( a[i] > n || a[i] < n - i || a[i] > a[i-1] ) 
        {
            cout << 0 << '\n';
            return ;
        }
    }

    ll ans = 1;
    for( int i = 2; i <= n; ++ i )
    {
        if( a[i] == a[i-1] ) ans = ( ans * ( a[i] - ( n - i ) ) ) % mod;
        else ans = ( ans * i ) % mod;
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}