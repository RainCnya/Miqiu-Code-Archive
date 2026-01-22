#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

int cnt[32];
int n;

ll getC( int n, int m )
{
    if( m > n ) return 0;
    ll res = 1;
    for( int i = 1; i <= m; ++ i )
    {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        ll x;
        cin >> x;
    }

    ll ans = getC( n, 3 );
    cout << ans << '\n';
    
    return 0;
}