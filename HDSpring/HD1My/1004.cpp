#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int maxn = 1e6 + 5;

ull hsh[maxn];
bool vis[maxn];
int n, x;

mt19937_64 rg( random_device{ }( ) );

void init( int N )
{
    for( int i = 2; i <= N; ++i )
    {
        if( vis[i] ) continue;
        hsh[i] = rg( );
        for( int j = i + i; j <= N; j += i )
        {
            hsh[j] = hsh[j / i] ^ hsh[i];
            vis[j] = 1;
        }
    }
}

void solve( )
{
    cin >> n >> x;
    ull tar = hsh[x];
    unordered_map< ull, int > mp;
    mp.reserve( n );
    mp[0] = 1;
    ull presum = 0;
    ll ans = 0;
    for( int i = 0, val; i < n; ++i )
    {
        cin >> val;
        presum ^= hsh[val];
        ull need = presum ^ tar;
        if( mp.count( need ) ) ans += mp[need];
        mp[presum]++;
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    init( maxn - 5 );
    solve( );
    return 0;
}