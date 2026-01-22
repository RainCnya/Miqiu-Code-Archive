#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int inf = 1e9;

int ans[maxn];
int d[3][maxn];
int n, k, q;

void solve( )
{
    memset( ans, 0, sizeof( ans ) );
    memset( d, 0, sizeof( d ) );

    cin >> n >> k >> q;
    for( int i = 1; i <= q; ++ i )
    {
        int c, l, r;
        cin >> c >> l >> r;
        d[c][l] ++;
        d[c][r+1] --;
    }

    int s1 = 0, s2 = 0;
    int cur = 0;

    for( int i = 1; i <= n; ++ i )
    {
        s1 += d[1][i];
        s2 += d[2][i];

        if( s1 && s2 ) ans[i] = inf;
        if( s1 && !s2 ) ans[i] = k;
        if( !s1 ) ans[i] = cur, cur = ( cur + 1 ) % k;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << ans[i] << " "; 
    }
    cout << '\n';
}

int main()
{	
    int t;
    cin >> t;
    while( t -- )
    {
        solve( );
    }    
    return 0;
}