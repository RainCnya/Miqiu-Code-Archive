#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const ll inf = 1e18;

int a[maxn];
ll s[maxn];
ll l, r;
int n;

ll calc( int i, int j )
{
    if( i + j > n ) return -inf;
    ll s1 = s[i], s2 = s[n] - s[n - j];
    return min( l * ( i - j ), r * ( i - j ) ) - ( s1 - s2 );
}

void solve( )
{
    cin >> n >> l >> r;
    for( int i = 1; i <= n; ++ i )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; ++ i )
        s[i] = s[i-1] + a[i];

    ll ans = -inf;
    for( int i = 0; i <= n; ++ i )
    {
        int j = n - i;
        ans = max( ans, calc( i , j ) ); 
        if( j >= 1 )
            ans = max( ans, calc( i, j - 1 ) );
    }
    cout << ans << '\n';
}

int main()
{	
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}