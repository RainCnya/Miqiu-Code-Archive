#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e6 + 50;

bool notPrime[maxn];
ll primes[maxn];
int cnt;
bool vis[maxn];
ll l, r;


void sieve( int N )
{
    notPrime[0] = notPrime[1] = 1;
    for( int i = 2; i <= N; ++ i )
    {
        if( !notPrime[i] ) primes[++ cnt] = i;
        for( int j = 1; j <= cnt && i * primes[j] <= N; ++ j )
        {
            int next = i * primes[j];
            notPrime[next] = 1;
            if( i % primes[j] == 0 ) break;
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve( 500000 );

    cin >> l >> r;

    for( int i = 1; i <= cnt && primes[i] * primes[i] <= r; ++ i )
    {
        ll p = primes[i];
        ll start = max( (l-1) / p + 1, 2ll );
        for( ll j = start; j * p <= r; ++ j )
        {
            vis[j * p - l] = 1;
        }
    }

    if( l == 1 ) vis[0] = 1;

    int ans = 0;
    for( ll i = l; i <= r; ++ i )
    {
        if( !vis[i - l] ) ans ++;
    }
    cout << ans << endl;
    
    return 0;
}