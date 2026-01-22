#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 50;

int cnt[maxn];

void solve( )
{
    int n;
    cin >> n;
    memset( cnt, 0, sizeof( cnt ) );
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    int ans = 0;
    for( int i = 0; i <= n; ++ i )
    {
        if( cnt[i] == i ) continue;
        else if( cnt[i] < i ) ans += cnt[i];
        else ans += cnt[i] - i;
    }
    cout << ans << '\n';
}

int main( )
{	
    int t;
    cin >> t;
    while( t -- )
    {
        solve( );
    }    
    return 0;
}