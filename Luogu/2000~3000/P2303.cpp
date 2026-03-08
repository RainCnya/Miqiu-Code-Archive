#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

ll n;

ll get_phi( ll n )
{
    ll res = n;
    for( ll i = 2; i * i <= n; ++ i )
    {
        if( n % i == 0 ) 
        {
            res = res / i * (i - 1);
            while( n % i == 0 ) n /= i;
        }
    }
    if( n > 1 ) res = res / n * (n - 1);
    return res;
}

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    ll ans = 0;
    for( ll i = 1; i * i <= n; ++ i )
    {
        if( n % i != 0 ) continue;
        ans += get_phi( n / i ) * i;
        if( i * i != n ) ans += get_phi( i ) * (n / i);
    }
    cout << ans << '\n';
    return 0;
}