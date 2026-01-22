#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod0 = 1e9 + 7;
const ll mod1 = 1e9 + 6;

const int maxn = 3e5 + 50;

ll val0[maxn];
ll val1[maxn];

int n;

ll qpow( ll base, ll k, ll mod )
{
    ll res = 1;
    while( k )
    {
        if( k & 1 ) res = ( res * base ) % mod;
        base = ( base * base ) % mod;
        k >>= 1;
    }
    return res;
}

int main( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        char opt;
        int x, u, v;
        cin >> opt;
        if( opt == 'N' )
        {
            cin >> x;
            val0[i] = x % mod0;
            val1[i] = x % mod1;
        }
        else if( opt == '+' )
        {
            cin >> u >> v;
            val0[i] = ( val0[u] + val0[v] ) % mod0;
            val1[i] = ( val1[u] + val1[v] ) % mod1;
        }
        else if( opt == '*' )
        {
            cin >> u >> v;
            val0[i] = ( (val0[u]) % mod0 * (val0[v]) % mod0 )% mod0;
            val1[i] = ( (val1[u]) % mod1 * (val1[v]) % mod1 )% mod1;
        }
        else
        {
            cin >> u >> v;
            val0[i] = ( val0[u] * qpow( 2, val1[v], mod0 ) ) % mod0;
            val1[i] = ( val1[u] * qpow( 2, val1[v], mod1 ) ) % mod1;
        }
    }
    
    for( int i = 1; i <= n; ++ i )
    {
        cout << val0[i] << '\n';
    }
    return 0;
}