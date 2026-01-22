#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e6 + 50;

bool notPrime[maxn];
int primes[maxn], cnt;
int sum[maxn];
int n, m;

void sieve( int N )
{
    notPrime[0] = notPrime[1] = true;
    for( int i = 2; i <= N; ++ i )
    {
        sum[i] = sum[i-1];
        if( !notPrime[i] )
        {
            primes[++ cnt] = i;
            sum[i] ++;
        }
        for( int j = 1; j <= cnt && i * primes[j] <= N; ++ j )
        {
            notPrime[i * primes[j]] = true;
            if( i % primes[j] == 0 ) break;
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve( maxn - 1 );
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )
    {
        int l, r;
        cin >> l >> r;
        if( 1 <= l && l <= r && r <= m )
        {
            cout << sum[r] - sum[l-1] << '\n';
        }
        else
        {
            cout << "Crossing the line" << '\n';
        }
    }

    return 0;
}