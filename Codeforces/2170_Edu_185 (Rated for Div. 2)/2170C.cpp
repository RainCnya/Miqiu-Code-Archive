#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

ll qs[maxn];
ll rs[maxn];
int n;
ll k;

bool check( int mid )
{
    if( mid == 0 ) return 1;
    for( int i = 1; i <= mid; ++ i )
    {
        ll cq = qs[i];
        ll cr = rs[mid - i + 1];
        if( cq * ( cr + 1 ) + cr > k ) return 0;
    }
    return 1;
}

void solve( )
{
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i ) cin >> qs[i];
    for( int i = 1; i <= n; ++ i ) cin >> rs[i];

    sort( qs + 1, qs + n + 1 );
    sort( rs + 1, rs + n + 1 );

    int l = 0, r = n;
    int ans = 0;
    while( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if( check( mid ) ) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
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
