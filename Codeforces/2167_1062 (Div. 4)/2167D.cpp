#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 };

ll a[maxn];
int n;

void solve( )
{
    cin >> n;
    ll g = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( i == 1 ) g = a[1];
        else g = __gcd( g, a[i] );
    }

    for( int p : primes )
    {
        if( g % p != 0 )
        {
            cout << p << '\n';
            return;
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve();
    }
    return 0;
}