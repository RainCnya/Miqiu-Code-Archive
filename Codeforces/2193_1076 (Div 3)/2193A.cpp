#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn];

void solve( )
{
    int n, s, x;
    cin >> n >> s >> x;

    ll sum = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        sum += a[i];
    }

    if( sum > s ) 
    {
        cout << "NO" << '\n';
        return;
    }
    else if( sum == s )
    {
        cout << "YES" << '\n';
        return;
    }

    ll diff = sum - s;
    
    if( x == 0 )
    {
        cout << "NO" << '\n';
        return;
    }

    if( diff % x == 0 )
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
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
        solve( );
    }
    return 0;
}