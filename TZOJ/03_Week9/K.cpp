#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[32];
int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    ll zeros = 0;

    for( int i = 1; i <= n; ++ i )
    {
        ll x;
        cin >> x;

        if( x == 0 ) 
        {
            zeros ++;
            continue;
        }

        for( int j = 31; j >= 0; -- j )
        {
            if( x >> j & 1 )
            {
                cnt[j] ++;
                break;
            }
        }
    }

    ll ans = 0;
    ll remain = n;
    
    for( int j = 31; j >= 0; -- j )
    {
        if( cnt[j] == 0 ) continue;
        remain -= cnt[j];
        ans += cnt[j] * remain;
    }

    if( zeros ) ans += ( zeros * ( zeros - 1 ) ) / 2;
    
    cout << ans << '\n';
    return 0;
}