#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

ll a[maxn], b[maxn];

void solve( )
{
    int n;
    cin >> n;
    ll mx = 0;
    ll mn = 0;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    ll min_ans = 0, max_ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ll max_r = max_ans - a[i];
        ll min_r = min_ans - a[i];
        ll max_b = b[i] - min_ans;
        ll min_b = b[i] - max_ans;

        max_ans = max( max_r, max_b );
        min_ans = min( min_r, min_b );
    }
    cout << max_ans << '\n';
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
