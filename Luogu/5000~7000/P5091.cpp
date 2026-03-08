#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxm = 1e8 + 5;
const int maxp = 1e5 + 5;

ll qpow( ll a, ll b, ll mod )
{
    ll res = 1;
    while( b ) 
    {
        if( b & 1 ) res = ( res * a ) % mod;
        a = ( a * a ) % mod;
        b >>= 1;
    }
    return res;
}

ll get_phi( ll n )
{
    ll phi = n;
    for( ll i = 2; i * i <= n; ++ i )
    {
        if( n % i == 0 )
        {
            phi = phi / i * (i - 1);
            while( n % i == 0 ) n /= i;
        }
    }
    if( n != 1 ) phi = phi / n * (n - 1);
    return phi;
}


int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll a, m;
    cin >> a >> m;

    ll phi = get_phi( m );

    ll b = 0;
    bool byd = 0;
    char ch;
    while( cin >> ch ) 
    {
        if( !isdigit( ch ) ) break;
        b = b * 10 + ch - '0';
        if( b >= phi ) byd = 1, b %= phi;
    }
    if( byd ) b += phi;

    cout << qpow( a, b, m ) << '\n';
    return 0;
}