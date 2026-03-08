#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e6 + 5;

int n, mod;
ll inv[maxn];

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> mod;
    
    inv[1] = 1;
    for( int i = 2; i <= n; ++ i )
    {
        inv[i] = (ll)( mod - mod / i ) * inv[mod % i] % mod;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << inv[i] << '\n';
    }

    return 0;
}