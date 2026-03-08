#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 19260817;

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ; k; k >>= 1, a = a * a % mod )
        if( k & 1 ) res = res * a % mod;
    return res;
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

    if( b == 0 )  cout << "Angry!" << '\n';
    else cout << a * qpow( b, mod - 2 ) % mod << '\n';

    return 0;
}