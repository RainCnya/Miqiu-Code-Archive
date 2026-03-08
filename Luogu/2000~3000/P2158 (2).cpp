#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 4e4 + 5;
int phi[maxn], p[maxn], cnt;
int n;

void init_phi( ll n )
{
    phi[1] = 1;
    for( ll i = 2; i <= n; ++ i )
    {
        if( phi[i] == 0 ) p[++ cnt] = i, phi[i] = i - 1;
        for( ll j = 1; j <= cnt && i * p[j] <= n; ++ j )
        {
            if( i % p[j] == 0 )
            {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            else phi[i * p[j]] = phi[i] * ( p[j] - 1 );
        }
    }
}


int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    cin >> n;

    if( n == 1 ) { cout << 0 << '\n'; return 0; }

    init_phi( n );

    ll ans = 1;
    for( int i = 2; i <= n - 1; ++ i ) ans += phi[i];
    cout << ans * 2 + 1 << '\n';

    return 0;
}