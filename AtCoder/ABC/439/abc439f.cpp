#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;
const int mod = 998244353;

int a[maxn], c[maxn];
ll l[maxn], r[maxn];
ll pow2[maxn];
int n;

int lowbit( int x )
{
    return x & -x;
}

void update( int x, int val )
{
    for( ; x <= n; x += lowbit( x ) )
        c[x] += val;
}

ll query( int x )
{
    ll res = 0;
    for( ; x; x -= lowbit( x ) )
        res += c[x];
    return res;
}

void init( )
{
    pow2[0] = 1;
    for( int i = 1; i <= n; ++ i )
    {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    init( );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i <= n; ++ i )
    {
        l[i] = query( a[i] - 1 );
        update( a[i], 1 );
    }

    memset( c, 0, sizeof( c ) );
    for( int i = n; i >= 1; -- i )
    {
        r[i] = query( a[i] - 1 );
        update( a[i], 1 );
    }

    ll ans = 0;
    ll sum = 0;

    for( int j = 1; j <= n; ++ j )
    {
        ll cur = ( sum + l[j] ) % mod;
        ans = ( ans + cur * r[j] ) % mod;
        sum = ( sum * 2 + l[j] ) % mod;
    }

    cout << ans % mod << '\n';
    return 0;
}