#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e7 + 5;

int phi[maxn], p[maxn], cnt;
ll sumphi[maxn];
int n;

void init_phi( int n )
{
    phi[1] = 1;
    for( int i = 2; i <= n; ++ i )
    {
        if( phi[i] == 0 ) p[++ cnt] = i, phi[i] = i - 1;

        for( int j = 1; j <= cnt && i * p[j] <= n; ++ j )
        {
            if( i % p[j] == 0 )
            {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            phi[i * p[j]] = phi[i] * ( p[j] - 1 );
        }
    }
    for( int i = 1; i <= n; ++ i ) sumphi[i] = sumphi[i - 1] + phi[i];
}

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    init_phi( n );

    ll ans = 0;
    for( int i = 1; i <= cnt; ++ i )
    {
        ans += sumphi[n / p[i]] * 2 - 1;
    }
    cout << ans << '\n';
    return 0;
}