#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    int st = 1;

    while( st <= n && a[st] == n - st + 1 ) st ++;
    int ed = -1;

    for( int i = st; i <= n; ++ i )
    {
        if( a[i] == n - st + 1 ) ed = i;
    }

    for( int i = 1; i < st; ++ i ) cout << a[i] << ' ';

    if( ed != -1 )
    {
        for( int i = ed; i >= st; -- i ) cout << a[i] << ' ';
        for( int i = ed + 1; i <= n; ++ i ) cout << a[i] << ' ';
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