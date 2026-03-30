#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;
int cnt[maxn];

void solve( )
{
    int n, m;
    cin >> m >> n;

    int ans = 0;
    queue< int > q;

    for( int i = 1; i <= n; ++ i )
    {
        int x; cin >> x;
        if( cnt[x] ) continue;
        ans ++;

        if( q.size( ) >= m )
        {
            cnt[q.front( )] --;
            q.pop( );
        }
        q.push( x );
        cnt[x] ++;
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}