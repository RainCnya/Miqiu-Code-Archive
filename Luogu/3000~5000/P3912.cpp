#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e8 + 5;
const int maxp = 1e7 + 5;

bool notPrime[maxn];
int prime[maxp];
int cnt;
ll n, q;

void linear_sieve( int n )
{
    notPrime[0] = notPrime[1] = 1;
    for( int i = 2; i <= n; ++ i )
    {
        if( !notPrime[i] ) prime[++ cnt] = i;
        for( int j = 1; j <= cnt && i * prime[j] <= n; ++ j )
        {
            int next = i * prime[j];
            notPrime[next] = 1;
            if( i % prime[j] == 0 ) break;
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    linear_sieve( n );
    cout << cnt << '\n';
    return 0;
}