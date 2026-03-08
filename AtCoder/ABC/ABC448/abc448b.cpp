#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

int a[maxn], b[maxn], c[maxn];
int cnt[maxn];
int n, m;

void solve( )
{
    cin >> n >> m;
    
    for( int j = 1; j <= m; ++ j ) cin >> c[j];
    for( int i = 1; i <= n; ++ i ) cin >> a[i] >> b[i];
    
    memset( cnt, 0, sizeof( cnt ) );
    for( int i = 1; i <= n; ++ i ) cnt[a[i]] += b[i];

    ll ans = 0;
    for( int j = 1; j <= m; ++ j ) ans += (ll)min( cnt[j], c[j] );
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}