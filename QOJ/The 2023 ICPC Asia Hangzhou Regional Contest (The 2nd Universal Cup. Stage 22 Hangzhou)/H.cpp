#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

ll qpow( ll a, ll b );

ll a[maxn], b[maxn], w[maxn];
int type[maxn];
int dist[maxn];
bool ok[maxn];

vector< int > radj[maxn];
int n;

ll fact[maxn], invfact[maxn];

ll qpow( ll a, ll b )
{
    ll res = 1;
    while( b )
    {
        if( b & 1 ) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void inv_init( int n )
{
    fact[0] = 1;
    for( int i = 1; i <= n; ++ i ) fact[i] = fact[i-1] * i % mod;
    invfact[n] = qpow( fact[n], mod - 2 );
    for( int i = n-1; i >= 0; -- i ) invfact[i] = invfact[i+1] * ( i+1 ) % mod;
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        radj[i].clear( );
        dist[i] = -1;
    }

    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];
    for( int i = 1; i <= n; ++ i ) cin >> w[i];

    queue< int > q;

    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] < a[ b[i] ] )
        {   // 必拿
            ok[i] = true;
            type[i] = 0;
            dist[i] = 0;
            q.push( i );
        }
        else if( a[i] >= a[ b[i] ] + w[ b[i] ] )
        {   // 不拿
            ok[i] = false;
            type[i] = 2;
            dist[i] = 0;
            q.push( i );
        }
        else 
        {   // 可拿
            type[i] = 1; 
        }
        radj[b[i]].push_back(i);
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );
        for( int v : radj[u] )
        {
            if( dist[v] == -1 && type[v] == 1 )
            {
                dist[v] = dist[u] + 1;
                ok[v] = ok[u];
                q.push( v );
            }
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        ll p = 0;
        if( dist[i] != -1 && ok[i] ) p = invfact[dist[i] + 1];
        ll ans = ( a[i] + w[i] * p ) % mod;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inv_init( maxn - 5 );
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}