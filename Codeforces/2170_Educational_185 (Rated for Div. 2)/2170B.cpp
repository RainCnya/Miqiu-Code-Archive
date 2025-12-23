#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n;
ll b[maxn];

void solve()
{
    cin >> n;
    ll cnt_zero = 0;
    ll sum = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> b[i];
        if( b[i] == 0 )
            cnt_zero ++;
        else
            sum += b[i];
    }
    sort( b + 1, b + n + 1 );

    ll ans = min( sum - (n - 1), n - cnt_zero );
    
    cout << ans << '\n';
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
