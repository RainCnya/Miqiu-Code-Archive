#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxA = 1e7 + 5;
const int maxn = 2e5 + 5;
const int mod = 998244353;

ll p[maxA];
ll max1[maxA], max2[maxA], cnt1[maxA];

vector< pair< ll, ll > > fac[maxn];
vector< ll > primes;
ll a[maxn];
int n;

ll qpow( ll a, ll b ) 
{
    ll res = 1;
    while( b ) 
    {
        if( b & 1 ) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void init( int n )
{
    for( int i = 2; i <= n; ++ i )
    {
        if( p[i] ) continue;
        for( int j = i; j <= n; j += i ) 
            if( !p[j] ) p[j] = i;
    }
}

void get_factor( int id, int val )
{
    fac[id].clear( );
    while( val > 1 )
    {
        int prime = p[val];
        int cnt = 0;
        while( val % prime == 0 ) val /= prime, cnt ++;
        fac[id].push_back({ prime, cnt });
        if( cnt > max1[prime] ) 
        {
            max2[prime] = max1[prime];
            max1[prime] = cnt;
            cnt1[prime] = 1;
            primes.push_back( prime );
        }
        else if( cnt == max1[prime] ) cnt1[prime] ++;
        else if( cnt > max2[prime] ) max2[prime] = cnt;
    }
}

void solve( )
{
    cin >> n;
    primes.clear( );
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        get_factor( i, a[i] );
    }

    sort( primes.begin( ), primes.end( ) );
    primes.erase( unique( primes.begin( ), primes.end( ) ), primes.end( ) );

    ll LCM = 1;
    for( int p : primes )
    {
        LCM = ( LCM * qpow( p, max1[p] ) ) % mod;
    }

    for( int i = 1; i <= n; ++ i )
    {
        ll res = LCM;
        for( auto [p, c] : fac[i] )
        {
            if( c == max1[p] && cnt1[p] == 1 )
            {
                ll inv = qpow( p, max1[p] - max2[p] ) % mod;
                res = res * qpow( inv, mod - 2 ) % mod;
            }
        }
        cout << res << " ";
    }
    cout << "\n";

    for( int p : primes )
    {
        max1[p] = max2[p] = cnt1[p] = 0;
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init( maxA - 1 );
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}