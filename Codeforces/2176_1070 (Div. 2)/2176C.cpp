#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

ll odds[maxn];
ll evens[maxn];
ll sum[maxn];

bool cmp( ll a, ll b ) {
    return a > b;
}

void solve( )
{
    int n;
    cin >> n;

    int cnt_odds = 0;
    int cnt_evens = 0;
    
    for( int i = 1; i <= n; ++ i )
    {
        ll x;
        cin >> x;
        if( x & 1 ) odds[++ cnt_odds] = x;
        else evens[++ cnt_evens] = x;
    }

    sort( odds + 1, odds + cnt_odds + 1, cmp );
    sort( evens + 1, evens + cnt_evens + 1, cmp );
    
    if( cnt_odds == 0 )
    {
        for( int k = 1; k <= n; ++ k ) cout << 0 << " ";
        cout << '\n';
        return ;
    }

    for( int i = 1; i <= cnt_evens; ++ i )
    {
        sum[i] = sum[i-1] + evens[i];
    }

    ll res = odds[1];
    for( int k = 1; k <= n; ++ k )
    {
        int remain = 1;

        if( cnt_evens <= k ) remain = k - cnt_evens;
        if( remain % 2 == 0 ) remain ++;

        if( remain > cnt_odds || remain > k ) cout << 0 << " ";
        else cout << res + sum[k - remain] << " ";
    }
    cout << '\n';
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
