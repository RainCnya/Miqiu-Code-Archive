#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e3 + 5;

int a[maxn];
int b[maxn];
int c[maxn];
ll n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];
    for( int i = 1; i <= n; ++ i ) cin >> c[i];

    ll cnt1 = 0;
    for( int t = 1; t <= n; ++ t )
    {
        bool ok = true;
        for( int i = 1; i <= n && ok; ++ i )
        {
            if( a[i] >= b[ (i + t - 1) % n + 1] ) ok = false;
        }
        if( ok ) cnt1 ++;
    }

    ll cnt2 = 0;
    for( int t = 1; t <= n; ++ t )
    {
        bool ok = true;
        for( int i = 1; i <= n && ok; ++ i )
        {
            if( b[i] >= c[ (i + t - 1) % n + 1] ) ok = false;
        }
        if( ok ) cnt2 ++;
    }

    cout << n * cnt1 * cnt2 << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
