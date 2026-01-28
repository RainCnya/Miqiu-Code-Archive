#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

ll a[maxn], b[maxn], c[maxn];
int n;
ll x;

void solve( )
{
    cin >> n >> x;

    ll sum = 0;
    ll maxx = -1;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i] >> b[i] >> c[i];
        sum += (b[i] - 1) * a[i];
        maxx = max( maxx, a[i] * b[i] - c[i] );
    }

    if( sum >= x )
    {
        cout << 0 << '\n';
        return ;
    }

    if( maxx <= 0 )
    {
        cout << -1 << '\n';
        return ;
    }

    ll remain = x - sum;
    cout << ( remain + maxx - 1 ) / maxx << '\n';
    return ;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}