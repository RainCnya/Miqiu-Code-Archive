#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 250 + 5;

char a[maxn][maxn];
int n, m;

int geti( char c )
{
    if( c == 'B' ) return 0;
    if( c == 'J' ) return 1;
    if( c == 'H' ) return 2;
    if( c == 'Y' ) return 3;
    if( c == 'N' ) return 4;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= m; ++ j )
            cin >> a[i][j];

    ll ans = 0;
    for( int r1 = 1; r1 <= n; ++ r1 )
    {
        for( int r2 = r1 + 1; r2 <= n; ++ r2 )
        {
            int cnt[6] = {0};
            for( int c = 1; c <= m; ++ c )
            {
                if( a[r1][c] == a[r2][c] ) cnt[geti( a[r1][c] )] ++;
            }

            for( int i = 0; i < 5; ++ i )
            {
                if( cnt[i] >= 2 ) ans += cnt[i] * ( cnt[i] - 1 ) / 2;
            }
        }
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