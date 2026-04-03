#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;

bool vis[maxn];
int n;

void solve( )
{
    cin >> n;
    
    for( int i = 1; i <= n; ++ i )
    {
        vis[i] = false;
    }
    
    for( int i = 1; i <= n; ++ i )
    {
        int x; cin >> x;
        if( x > n ) continue;
        vis[x] = true;
    }
    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( vis[i] ) ++ ans;
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