#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n, q;
    cin >> n >> q;
    
    vector< int > a(n + 2, 0);
    vector< int > b(n + 2, 0);
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    a[n + 1] = 0;
    for( int i = n; i >= 1; -- i ) a[i] = max({ a[i], a[i+1], b[i] });

    vector< ll > s(n + 2, 0);
    s[0] = 0;
    for( int i = 1; i <= n; ++ i ) s[i] = s[i - 1] + a[i];

    while( q -- )
    {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << " ";
    }
    cout << '\n';
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