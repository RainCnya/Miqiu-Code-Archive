#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    int n, t;
    cin >> n >> t;
    set< int > s;

    for( int i = 1; i <= n; ++ i )
    {
        int x; cin >> x;
        s.insert( x );
    }

    auto it = s.begin( );
    int ans = 1;
    int cur = *it;
    while( it != s.end( ) )
    {
        it ++;
        if( it == s.end( ) ) break;
        int nxt = *it;
        if( nxt - cur >= t ) 
        {
            ans += 1;
            cur = nxt;
        }
        // cout << cur << " " << nxt << '\n';
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}