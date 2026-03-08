#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 19260817;

ll exgcd( ll a, ll b, ll &x, ll &y )
{
    if( b == 0 ) { x = 1, y = 0; return a; }
    ll d = exgcd( b, a % b, y, x );
    y -= a / b * x;
    return d;
}

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll a = 0, b = 0;
    string s;
    
    cin >> s;
    for( char ch : s ) a = ( a * 10 + ch - '0' ) % mod;
    cin >> s;
    for( char ch : s ) b = ( b * 10 + ch - '0' ) % mod;

    if( b == 0 ) {
        cout << "Angry!" << '\n';
        return 0;
    }
    ll x, y;
    ll d = exgcd( b, mod, x, y );
    x = ( x % mod + mod ) % mod;
    cout << a * x % mod << '\n';

    return 0;
}