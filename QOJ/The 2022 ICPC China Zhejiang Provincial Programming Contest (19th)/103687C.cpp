#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn];
int b[maxn];
int n, m, x;

void solve( )
{
    cin >> n >> m >> x;

    ll sum = 0;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( a[i] >= x ) sum ++;
    }
    for( int i = 1; i <= m; ++ i ) 
    {
        cin >> b[i];
        if( b[i] <= x ) sum ++;
    }
    cout << sum << '\n';

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}